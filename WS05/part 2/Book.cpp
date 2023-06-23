//Filename: Book.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//----------------------------------------------------------
#include <iomanip>
#include "Book.h"

namespace sdds {
	Book::Book() = default;

	Book::Book(const std::string& strBook)
		:author{ strBook.substr(0, strBook.find_first_of(",")) },
		name{ strBook.substr(strBook.find_first_of(",") + 1, strBook.find(",",strBook.find_first_of(",") + 1) - author.size() - 1) },
		country_published{ strBook.substr(strBook.find(name) + name.size() + 1, strBook.find(",",strBook.find(name) + name.size() + 1) - (name.size() + author.size()) - 2) } {
		std::string internal_cost{ strBook.substr(strBook.find(country_published) + country_published.size() + 1, strBook.find(",",strBook.find(country_published) + country_published.size() + 1) - (country_published.size() + name.size() + author.size()) - 3) };

		std::string internal_year_published{ strBook.substr(strBook.find(internal_cost) + internal_cost.size() + 1, strBook.find(",",strBook.find(internal_cost) + internal_cost.size() + 1) - (internal_cost.size() + country_published.size() + name.size() + author.size()) - 4) };

		description = strBook.substr(strBook.find(internal_year_published) + internal_year_published.size() + 1);

		cost = std::stod(internal_cost);
		year_published = std::stoi(internal_year_published);

		const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789"
			".";

		author.erase(0, author.find_first_of(pattern));
		author.erase(author.find_last_of(pattern) + 1);
		name.erase(0, name.find_first_of(pattern));
		name.erase(name.find_last_of(pattern) + 1);
		country_published.erase(0, country_published.find_first_of(pattern));
		country_published.erase(country_published.find_last_of(pattern) + 1);
		description.erase(0, description.find_first_of(pattern));
		description.erase(description.find_last_of(pattern) + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Book& b) {
		return os << std::setw(20) << b.author << " |" << std::right << std::setw(23) << b.name << " |" << std::setw(6) << b.country_published << " |" << std::setw(5) << b.year_published << " |" << std::setw(7) << std::setprecision(2) << std::fixed << b.cost << " | " << b.description << "\n";
	}

	const std::string& Book::title() const {
		return name;
	}

	const std::string& Book::country() const {
		return country_published;
	}

	const size_t& Book::year() const {
		return year_published;
	}

	double& Book::price() {
		return cost;
	}
}