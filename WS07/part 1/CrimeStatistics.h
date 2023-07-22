//Filename: CrimeStatistics.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 07/10/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <vector>
#include <string_view>
#include <list>

namespace sdds {
	class CrimeStatistics {
	public:
		struct Crime {
		public:
			std::string province;
			std::string district;
			std::string	crime;
			unsigned year{};
			unsigned number_of_cases{};
			unsigned m_resolved{};
		};

		CrimeStatistics();
		explicit CrimeStatistics(const std::string& file_name);
		friend std::ifstream& operator >> (std::ifstream& ifs, Crime& c);
		friend std::ostream& operator << (std::ostream& os, const Crime& theCrime);
		void display(std::ostream& os);
		void sort(std::string_view option);
		void cleanList();
		bool inCollection(std::string_view crime_type) const;
		std::list<Crime> getListForProvince(std::string_view prov) const;
	private:
		std::vector<Crime> crimes;
	};
}