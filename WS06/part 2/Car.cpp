//Filename: Car.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include <cctype>
#include "Car.h"

namespace sdds {
	Car::Car() = default;

	Car::Car(std::istream& is) {
		char c{};
		while (is.get(c) && (isspace(c) || isalpha(c))) {
			make += c;
		}

		const std::string valid_conditions = "nub";

		while (is.get(c) && (isspace(c) || isalpha(c))) {
			if (isalpha(c) && valid_conditions.find_first_of(c) == std::string::npos) {
				throw std::string{ "Invalid record!" };
			}
			state = c;
		}

		if (!state || isspace(state)) {
			state = 'n';
		}

		std::string s;

		while (is.get(c) && (c == ' ' || isdigit(c) || isalpha(c))) {
			if (isalpha(c)) {
				throw std::string{ "Invalid record!" };
			}
			s += c;
		}

		is.unget();

		const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		make.erase(0, make.find_first_of(pattern));
		make.erase(make.find_last_of(pattern) + 1);
		max_speed = std::stod(s);
	}

	Car::~Car() = default;

	double Car::topSpeed() const {
		return max_speed;
	}

	void Car::display(std::ostream& os) const {
		os << "| " << std::right << std::setw(10) << make << " | "
			<< std::left << std::setw(7) << condition() << "| "
			<< std::setw(7) << std::setprecision(2) << std::fixed << max_speed << "| ";
	}

	std::string Car::condition() const {
		if (state == 'n') {
			return "new";
		}

		if (state == 'u') {
			return "used";
		}

		return  "broken";
	}
	double& Car::top_speed() {
		return max_speed;
	}
}