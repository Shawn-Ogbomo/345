//Filename: Racecar.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Racecar.h"

namespace sdds {
	sdds::Racecar::Racecar() = default;

	Racecar::Racecar(std::istream& in)
		:Car(in) {
		if (in.peek() == ',') {
			in.get();
			in >> m_booster;
			Car::top_speed() = Racecar::topSpeed();
			in.get();
		}
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed();
	}

	double Racecar::topSpeed() {
		return Car::top_speed() += (Car::topSpeed() * m_booster);
	}
}