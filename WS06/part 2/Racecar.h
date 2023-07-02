//Filename: Racecar.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
	public:
		Racecar();
		explicit Racecar(std::istream& in);
		virtual void display(std::ostream& out) const;
		virtual double topSpeed() const;
		double topSpeed();
	private:
		double m_booster{};
	};
}