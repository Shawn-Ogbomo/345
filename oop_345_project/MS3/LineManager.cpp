//Filename: LineManager.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <ios>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Workstation.h"
#include "LineManager.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		std::ifstream ifs{ file };
		if (!ifs) {
			std::cerr << "The file: " << file << " does not exist...\n";
			ifs.exceptions(ifs.exceptions() | std::ios::badbit);
		}

		constexpr auto bar = '|';

		while (!ifs.eof()) {
			std::string record;
			std::getline(ifs, record);
			auto pos_of_bar = record.find(bar);
			const auto first_station_name = record.substr(0, pos_of_bar);

			const auto first_station = std::find_if(stations.begin(),
				stations.end(), [&first_station_name](Workstation const* ws)
				{return ws->getItemName() == first_station_name; });

			if (pos_of_bar != std::string::npos) {
				const auto second_station_name = record.substr(pos_of_bar + 1);

				m_activeLine.emplace_back(*first_station)->setNextStation(*std::find_if(stations.begin(),
					stations.end(), [&second_station_name](Workstation const* internal_ws)
					{return internal_ws->getItemName() == second_station_name; }));
			}

			else {
				m_activeLine.emplace_back(*first_station)->setNextStation();
			}
		}
		m_firstStation = m_activeLine.front();
	}

	void LineManager::reorderStations() {
		auto last_station = std::find_if(m_activeLine.begin(), m_activeLine.end(), [](const Workstation* ws) {
			return !(*ws).getNextStation();
			});

		std::swap(*last_station, m_activeLine.back());
		const auto* station_ptr = &m_activeLine.back()->getItemName();

		for (auto i = m_activeLine.size() - 1; i > 0; --i) {
			const auto matching_station = find_if(m_activeLine.begin(), m_activeLine.end(), [&station_ptr](const Workstation* internal_ws)
				{return (*internal_ws).getNextStation()->getItemName() == *station_ptr; });

			std::swap(*matching_station, m_activeLine[i - 1]);
			station_ptr = &m_activeLine[i - 1]->getItemName();
		}

		m_firstStation = m_activeLine.front();
	}

	bool LineManager::run(std::ostream& os) {
		static auto count = 1;
		static const auto max_orders = g_pending.size();
		os << "Line Manager Iteration: " << count << "\n";

		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* ws)
			{ws->fill(os); });

		std::for_each(m_activeLine.cbegin(), m_activeLine.cend(), [](Workstation* internal_ws)
			{ internal_ws->attemptToMoveOrder(); });

		++count;

		const auto all_orders_filled = g_completed.size() + g_incomplete.size() == max_orders ? true : false;
		return all_orders_filled;
	}

	void LineManager::display(std::ostream& os) const {
		for (const auto& line : m_activeLine) {
			line->display(os);
		}
	}
}