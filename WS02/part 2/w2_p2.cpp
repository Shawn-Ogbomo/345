// Workshop 2 - Fall 2022
// w2_p1.cpp
// Michael Huang

#include <chrono> // For part 2 experiements

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "TennisLog.h"
#include "TennisLog.h"
#include "Timer.h"
#include "Timer.h"

void printDivider(size_t cnt) {
	for (auto i = 0u; i < cnt; ++i)
		std::cout << "*";
	std::cout << std::endl;
}

void printHeader(const char* head) {
	std::cout << std::endl;
	printDivider(53);
	std::cout << head << std::endl;
	printDivider(53);
}

constexpr size_t MAX_OP = 7u;
struct OperationTimes
{
	// stores the times of each supported operation
	long long times[MAX_OP + 1]{}; // the last elem is invalid

	// supported operations
	const char* operations[MAX_OP]{
		"Default Constructor",
		"Custom Constructor",
		"Copy Constructor",
		"Copy Assignment Operator",
		"Move Constructor",
		"Move Assignment Operator",
		"Destructor"
	};

	long long& operator[](const char* operation)
	{
		// assuming parameter is correct
		for (auto i = 0u; i < MAX_OP; ++i)
			if (std::strcmp(operations[i], operation) == 0)
				return times[i];

		return times[MAX_OP]; // unknown operation; return the invalid elem
	}
};
std::ostream& operator<<(std::ostream& out, const OperationTimes& ot)
{
	out << "\n\nStatistics\n"
		"-----------------------\n";

	for (auto i = 0u; i < MAX_OP; ++i)
		out << std::setw(25) << std::right << ot.operations[i] << ": "
		<< std::setw(10) << std::right << ot.times[i] << " nanoseconds.\n";

	return out;
}

// ws tennis-data.csv
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	for (int i = 0; i < argc; i++)
		std::cout << i + 1 << ". " << argv[i] << std::endl;

	if (argc != 2)
	{
		std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
		return 1;
	}

	OperationTimes times;
	sdds::Timer timer;

	printHeader("Empty Tennis Log entries");

	timer.start();
	sdds::TennisLog tlog1;
	times["Default Constructor"] = timer.stop();

	std::cout << tlog1[0] << std::endl;
	std::cout << tlog1[1000] << std::endl;
	std::cout << tlog1[10000] << std::endl;
	std::cout << tlog1[size_t(tlog1) - 1] << std::endl;

	printHeader("Non Empty Tennis Log entries");

	timer.start();
	sdds::TennisLog tlog2(argv[1]);
	times["Custom Constructor"] = timer.stop();

	std::cout << tlog2[0] << std::endl;
	std::cout << tlog2[1000] << std::endl;
	std::cout << tlog2[10000] << std::endl;
	std::cout << tlog2[size_t(tlog2) - 1] << std::endl;

	printHeader("Add to Empty Tennis Log");
	sdds::TennisMatch t1{ "2022-120", "Wimbeldon", 12, "Player 1", "Player 2" };
	sdds::TennisMatch t2{ "2022-121", "US Open", 1, "Player 3", "Player 4" };
	sdds::TennisMatch t3{ "2022-122", "Davis Cup", 7, "Player 5", "Player 6" };
	sdds::TennisMatch t4{ "2022-123", "New Year Cup", 4, "Player 7", "Player 8" };
	tlog1.addMatch(t1);
	tlog1.addMatch(t2);
	tlog1.addMatch(t3);
	tlog1.addMatch(t4);

	std::cout << tlog1[0] << std::endl;
	std::cout << tlog1[1] << std::endl;
	std::cout << tlog1[2] << std::endl;
	std::cout << tlog1[size_t(tlog1) - 1] << std::endl;

	printHeader("Find specific player matches and display");
	sdds::TennisLog found = tlog2.findMatches("Wentworth Gore");
	std::cout << "Number of matches found: " << size_t(found) << std::endl;
	std::cout << "First match found:\n" << found[0] << std::endl;
	std::cout << "Last match found:\n" << found[size_t(found) - 1] << std::endl;

	printHeader("Find an non existing player");
	sdds::TennisLog notfound = tlog2.findMatches("Tennis Playing Robot");
	std::cout << "Number of matches found: " << size_t(notfound) << std::endl;

	// Part 2
	{
		printHeader("Copy Construction");

		timer.start();
		sdds::TennisLog tlog = tlog2;
		times["Copy Constructor"] = timer.stop();

		std::cout << tlog[0] << std::endl;
		std::cout << tlog[1] << std::endl;
		std::cout << tlog[2] << std::endl;
		std::cout << tlog[size_t(tlog) - 1] << std::endl;
	}

	{
		printHeader("Copy Assignment");

		timer.start();
		tlog1 = tlog2;
		times["Copy Assignment Operator"] = timer.stop();

		std::cout << tlog1[0] << std::endl;
		std::cout << tlog1[1000] << std::endl;
		std::cout << tlog1[10000] << std::endl;
		std::cout << tlog1[size_t(tlog1) - 1] << std::endl;
	}

	{
		printHeader("Move Construction");

		timer.start();
		sdds::TennisLog tlog = std::move(tlog1);
		times["Move Constructor"] = timer.stop();

		std::cout << tlog[0] << std::endl;
		std::cout << tlog[1000] << std::endl;
		std::cout << tlog[10000] << std::endl;
		std::cout << tlog[size_t(tlog) - 1] << std::endl;

		std::cout << "First element of tlog1 after move: " << tlog1[0] << std::endl;
		std::cout << "Size of tlog1 after move: " << size_t(tlog1) << std::endl;
	}

	{
		printHeader("Move Assignment");
		sdds::TennisLog tlog;

		timer.start();
		tlog = std::move(tlog2);
		times["Move Assignment Operator"] = timer.stop();

		std::cout << tlog[0] << std::endl;
		std::cout << tlog[1] << std::endl;
		std::cout << tlog[2] << std::endl;
		std::cout << tlog[size_t(tlog) - 1] << std::endl;

		std::cout << "First element of tlog2 after move: " << tlog2[0] << std::endl;
		std::cout << "Size of tlog2 after move: " << size_t(tlog2) << std::endl;

		// tlog goes out of scope; record the time of the destructor
		timer.start();
	}
	times["Destructor"] = timer.stop();

	std::cout << times;
}