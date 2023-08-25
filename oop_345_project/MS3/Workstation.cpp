//Filename: Workstation.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iostream>
#include "Workstation.h"

namespace sdds {
	Workstation::Workstation() = default;

	Workstation::Workstation(const std::string& station_name) :Station(station_name) {
	}

	Workstation::~Workstation() = default;

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

	bool Workstation::attemptToMoveOrder() {
		if (!m_orders.empty()) {
			CustomerOrder& order = m_orders.front();

			if (order.isItemFilled(getItemName()) || !getQuantity()) {
				if (!m_pNextStation) {
					if (order.isOrderFilled()) {
						g_completed.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}

					else {
						g_incomplete.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}
				}

				m_pNextStation->m_orders.push_back(std::move(order));
				m_orders.pop_front();
				return true;
			}
		}

		return false;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		if (!m_pNextStation) {
			os << getItemName() << " --> " << "End of Line\n";
		}

		else {
			os << getItemName() << " --> "
				<< m_pNextStation->getItemName() << "\n";
		}
	}

	void Workstation::setNextStation(Workstation* station) {
		if (station) {
			m_pNextStation = station;
		}
	}
}