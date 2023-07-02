//Filename: AutoShop.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator += (Vehicle* right);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
				if (test(*it)) {
					vehicles.push_back(*it);
				}
			}
		}
	private:
		std::vector<Vehicle*> m_vehicles;
	};
}