//Filename: Utilities.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Utilities.h"
#include "Racecar.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		if (!in) {
			return nullptr;
		}

		char record_prefix{};
		in >> record_prefix;

		in.ignore(50, ',');

		if (record_prefix == 'C' || record_prefix == 'c') {
			auto* c = new Car{ in };
			return c;
		}

		else if (record_prefix == 'R' || record_prefix == 'r') {
			auto* r = new Racecar{ in };
			return r;
		}

		throw std::string{ "Unrecognized record type: [" } + record_prefix + "]";
	}
}