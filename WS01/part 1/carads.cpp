//Filename: carads.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// Instructor Rania Arbash
// OOP345 Section NRA
// date: 05/13/23
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iomanip>
#include "carads.h"
namespace sdds {
	void listArgs(int argc, char* argv[]) {
		if (argc > 0) {
			std::cout << "Command Line:\n"
				<< "--------------------------\n";

			for (auto i = 0; i < argc; ++i) {
				std::cout << "  " << i + 1 << ": " << argv[i] << "\n";
			}

			std::cout << "--------------------------\n\n";
		}
	}

	Cars::Cars() = default;

	void Cars::read(std::istream& is) {
		if (is) {
			status = is.get();
			is.ignore();
			std::string s;
			std::getline(is, s, ',');
			std::strcpy(brand, s.c_str());
			std::getline(is, s, ',');
			std::strcpy(model, s.c_str());
			is >> year;
			is.ignore();
			is >> price;
			is.ignore();

			if (is.peek() == 'Y') {
				discount_status = true;
			}
			else {
				discount_status = false;
			}

			is.ignore();
			is.ignore();
		}
	}

	char Cars::getStatus() const {
		return status;
	}

	void Cars::display(bool reset) const {
		static auto counter = 0;

		if (reset) {
			counter = 0;
		}

		++counter;
		const auto name_len = std::strlen(brand);

		if (name_len) {
			std::cout << std::left << std::setw(2) << counter << ". " << std::setw(10) << brand <<
				"| " << std::setw(15) << model << "| " << std::setw(4) << year << " |" << std::setw(12) << std::right
				<< std::setprecision(2) << std::fixed << price + (price * g_taxrate) << "|";
		}

		if (name_len && discount_status) {
			std::cout << std::setw(12) << ((price * g_taxrate) + price) - ((price * g_discount * g_taxrate) + (price * g_discount));
		}

		else if (!name_len) {
			std::cout << counter << std::left << std::setw(2) << ". No Car";
		}

		std::cout << "\n";
	}
}