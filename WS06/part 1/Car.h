//Filename: Car.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
	public:
		Car();
		explicit Car(std::istream& is);
		~Car();
		virtual double topSpeed() const;
		virtual void display(std::ostream& os) const;
		virtual std::string condition() const;
	private:
		std::string make;
		char state{};
		double max_speed{};
	};
}