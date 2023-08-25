//Filename: LineManager.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <vector>
#include "Workstation.h"
namespace sdds {
	class LineManager {
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	private:
		std::vector<Workstation*> m_activeLine{};
		size_t m_cntCustomerOrder{ g_pending.size() };
		Workstation* m_firstStation{};
	};
}