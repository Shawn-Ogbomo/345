#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "CrimeStatistics.h"
#include "CrimeStatistics.h"

int cout = 0; // won't compile if headers don't follow convention

void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::CrimeStatistics statistics(argv[1]);

	printHeader("The original Statistics");
	statistics.display(std::cout);
	printbar();

	
	printHeader("The Statistics sorted by Province");
	statistics.sort("Province");
	statistics.display(std::cout);
	printbar();

	printHeader("The Statistics sorted by Crime Types");
	statistics.sort("Crime");
	statistics.display(std::cout);
	printbar();

	printHeader("The Statistics sorted by total cases");
	statistics.sort("Cases");
	statistics.display(std::cout);
	printbar();

	printHeader("The Statistics sorted by Number of Resolved Cases");
	statistics.sort("Resolved");
	statistics.display(std::cout);
	printbar();

	printHeader("The Statistics with fixed Crime Type Names");
	statistics.cleanList();
	statistics.display(std::cout);
	printbar();

	{
		// looking for "Fraud" in the data collections
		if (statistics.inCollection("Fraud"))
			std::cout << "There are Fraud cases in the data collection.\n";
		else
			std::cout << "There are no Fraud cases in the data collection.\n";
	}

	{
		printHeader("Crimes in Ontario");
		auto col = statistics.getListForProvince("Ontario");
		for (auto& crime : col)
		{
			crime.m_resolved -= 3;
			std::cout << crime << "\n";
		}
		printbar();
	}

	return cout;
}
