//Filename: AutoShop.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator += (Vehicle* right);
		void display(std::ostream& out) const;
	private:
		std::vector<Vehicle*> m_vehicles;
	};
}