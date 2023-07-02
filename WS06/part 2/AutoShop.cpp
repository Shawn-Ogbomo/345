//Filename: AutoShop.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/20/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iterator>
#include "Autoshop.h"

namespace sdds {
	Autoshop::Autoshop() = default;

	Autoshop::~Autoshop() {
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
			delete (*it);
		}
	}

	Autoshop& Autoshop::operator+=(Vehicle* right) {
		m_vehicles.push_back(right);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n"
			<< "| Cars in the autoshop!        |\n"
			<< "--------------------------------\n";

		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
			(*it)->display(std::cout);
			std::cout << "\n";
		}

		std::cout << "--------------------------------\n";
	}
}