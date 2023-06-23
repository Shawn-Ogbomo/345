// Workshop 2 - Fall 2022
// w2_p1.cpp
// Michael Huang

#include <iostream>
#include <iomanip>
#include <string>
#include "TennisLog.h"
#include "TennisLog.h"

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

	printHeader("Empty Tennis Log entries");

	sdds::TennisLog tlog1;

	std::cout << tlog1[0] << std::endl;
	std::cout << tlog1[1000] << std::endl;
	std::cout << tlog1[10000] << std::endl;
	std::cout << tlog1[size_t(tlog1) - 1] << std::endl;

	printHeader("Non Empty Tennis Log entries");

	sdds::TennisLog tlog2(argv[1]);

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
}