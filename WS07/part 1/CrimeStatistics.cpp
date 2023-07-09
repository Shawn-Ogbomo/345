//Filename: CrimeStatistics.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "CrimeStatistics.h"

namespace sdds {
	sdds::CrimeStatistics::CrimeStatistics() = default;

	CrimeStatistics::CrimeStatistics(const std::string& file_name) {
		std::ifstream ifs{ file_name };

		if (!ifs) {
			std::cerr << "Sorry the file: " << file_name << " does not exist...\n";
			ifs.exceptions(ifs.exceptions() | std::ios::badbit);
		}

		for (Crime the_crime; ifs >> the_crime;) {
			crimes.push_back(the_crime);
			the_crime = {};
		}
	}

	void CrimeStatistics::display(std::ostream& os) {
		auto total_cases = 0;
		auto total_resolved_cases = 0;

		std::for_each(crimes.begin(), crimes.end(), [&os, &total_cases, &total_resolved_cases](const Crime& c) {
			os << c;
			total_cases += c.number_of_cases;
			total_resolved_cases += c.m_resolved;
			});

		os << "----------------------------------------------------------------------------------------\n"
			<< std::right << "|" << std::setw(80) << "Total Crimes:  " << total_cases << " |\n"
			<< "|" << std::setw(80) << "Total Resolved Cases : " << total_resolved_cases << " |\n";
	}

	void CrimeStatistics::sort(std::string_view option) {
		if (option == "Province") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& c_left, const Crime& c_right) {
				return c_left.province < c_right.province;
				});
		}

		else if (option == "Crime") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& c_left, const Crime& c_right) {
				return c_left.crime < c_right.crime;
				});
		}

		else if (option == "Cases") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& c_left, const Crime& c_right) {
				return c_left.number_of_cases < c_right.number_of_cases;
				});
		}

		else if (option == "Resolved") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& c_left, const Crime& c_right) {
				return c_left.m_resolved < c_right.m_resolved;
				});
		}
	}

	void CrimeStatistics::cleanList() {
		std::transform(crimes.begin(), crimes.end(), crimes.begin(), [](Crime c) {
			if (c.crime == "[None]") {
				c.crime = "";
			}
			return c;
			});
	}

	bool CrimeStatistics::inCollection(std::string_view crime_type) const {
		return std::any_of(crimes.begin(), crimes.end(), [crime_type](const Crime& c) {
			return c.crime == crime_type;
			});
	}

	std::list<sdds::CrimeStatistics::Crime> CrimeStatistics::getListForProvince(std::string_view prov) const {
		std::list<sdds::CrimeStatistics::Crime> crimes_containing_prov;

		std::copy_if(crimes.begin(), crimes.end(), std::back_inserter(crimes_containing_prov), [prov](const Crime& c) {
			return c.province == prov;
			});

		return crimes_containing_prov;
	}

	std::ifstream& operator>>(std::ifstream& ifs, sdds::CrimeStatistics::Crime& c) {
		ifs >> c.province >> c.district >> c.crime
			>> c.year >> c.number_of_cases >> c.m_resolved;
		return ifs;
	}

	std::ostream& operator<<(std::ostream& os, const sdds::CrimeStatistics::Crime& theCrime) {
		os << std::left << "| " << std::setw(22) << theCrime.province << "| " << std::setw(16) << theCrime.district << "| " << std::setw(21)
			<< theCrime.crime << "| " << std::setw(6) << std::right << theCrime.year << " | " << std::setw(4)
			<< theCrime.number_of_cases << " | " << std::setw(3)
			<< theCrime.m_resolved << " | \n";
		return os;
	}
}