//Filename: Utilities.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Utilities.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		if (in.peek() == 'c' || in.peek() == 'C') {
			auto* c = new Car{ in };
			return c;
		}

		return nullptr;
	}
}