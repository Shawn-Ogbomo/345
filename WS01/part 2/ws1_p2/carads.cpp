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

	std::istream& operator>>(std::istream& is, Cars& car) {
		if (is) {
			delete[] car.brand;
			car.status = is.get();
			is.ignore();
			std::string s;
			std::getline(is, s, ',');
			car.brand = new char[std::char_traits<char>::length(s.c_str()) + 1];
			std::strcpy(car.brand, s.c_str());
			std::getline(is, s, ',');
			std::strcpy(car.model, s.c_str());
			is >> car.year;
			is.ignore();
			is >> car.price;
			is.ignore();

			if (is.peek() == 'Y') {
				car.discount_status = true;
			}
			else {
				car.discount_status = false;
			}

			is.ignore();
			is.ignore();
		}
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2) {
		car2 = car1;
	}

	Cars::Cars() = default;

	Cars::Cars(const Cars& c) {
		*this = c;
	}

	Cars::~Cars() {
		delete[] brand;
	}

	Cars& Cars::operator=(const Cars& right) {
		if (this != &right) {
			delete[] brand;
			brand = new char[std::char_traits<char>::length(right.brand) + 1];
			strcpy(brand, right.brand);
			status = right.status;
			strcpy(model, right.model);
			year = right.year;
			price = right.price;
			discount_status = right.discount_status;
		}
		return *this;
	}

	Cars::operator bool() const {
		return status == 'N' ? true : false;
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