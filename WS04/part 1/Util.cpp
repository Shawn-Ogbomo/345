//Filename: Util.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------

#include <iostream>
#include "Util.h"

void sdds::Util::clear_space(std::string& target) {
	const auto space = ' ';
	const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";

	if (target.front() == space) {
		target.erase(0, target.find_first_of(pattern));
	}

	if (target.back() == space) {
		target.erase(target.find_last_of(pattern) + 1);
	}
}