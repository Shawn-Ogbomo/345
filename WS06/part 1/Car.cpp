//Filename: Car.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include "Car.h"

namespace sdds {
	Car::Car() = default;

	Car::Car(std::istream& is) {
		std::string s;
		std::getline(is, s);

		const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const auto pattern2 = "abcdefghijklmnopqrstuvwxyz";
		const auto pattern3 = "123456789";

		make = s.substr(s.find_first_of(pattern), s.find(',', s.find_first_of(pattern)) - s.find_first_of(pattern));
		state = s[s.find_first_of(pattern2, s.find(make) + (make.size()))];
		max_speed = std::stod(s.substr(s.find_first_of(pattern3)));

		make.erase(make.find_last_of(pattern2) + 1);
	}

	Car::~Car() = default;

	double Car::topSpeed() const {
		return max_speed;
	}

	void Car::display(std::ostream& os) const {
		os << "| " << std::right << std::setw(10) << make << "| "
			<< std::left << std::setw(6) << condition() << "| "
			<< std::setw(6) << std::setprecision(2) << std::fixed << max_speed << "| ";
	}

	std::string Car::condition() const {
		if (state == 'n') {
			return std::string{ "new" };
		}

		if (state == 'u') {
			return std::string{ "used" };
		}

		if (state == 'b') {
			return std::string{ "broken" };
		}
	}
}