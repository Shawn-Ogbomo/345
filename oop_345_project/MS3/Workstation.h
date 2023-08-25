//Filename Workstation.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <deque>
#include <memory>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds {
	inline std::deque <CustomerOrder> g_pending;
	inline std::deque <CustomerOrder> g_completed;
	inline std::deque <CustomerOrder> g_incomplete;

	class Workstation : public Station {
	public:
		Workstation();
		explicit Workstation(const std::string& station_name);
		~Workstation() override;
		Workstation(const Workstation& right) = delete;
		Workstation(Workstation&& right) = delete;
		Workstation& operator+=(CustomerOrder&& newOrder);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		Workstation* getNextStation() const;
		void setNextStation(Workstation* station = nullptr);
		virtual void display(std::ostream& os) const;
		using Station::display;
	private:
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{};
	};
}