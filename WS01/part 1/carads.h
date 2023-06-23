//Filename: carads.h
//Name:	Shawn Ogbomo
// Student #022609127
// Instructor Rania Arbash
// OOP345 Section NRA
// date: 05/13/23
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	void listArgs(int argc, char* argv[]);

	class Cars {
	public:
		Cars();
		void read(std::istream& is);
		char getStatus() const;
		void display(bool reset) const;
	private:
		char status{};
		char brand[10]{};
		char model[15]{};
		unsigned year{};
		double price{};
		bool discount_status{};
	};
}
