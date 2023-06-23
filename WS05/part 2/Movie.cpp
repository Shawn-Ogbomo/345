//Filename: Movie.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include "Movie.h"

namespace sdds {
	Movie::Movie() = default;

	Movie::Movie(const std::string& strMovie)
		:name{ strMovie.substr(0,strMovie.find_first_of(",")) } {
		std::string internal_release_year{ strMovie.substr(strMovie.find_first_of(",") + 1, strMovie.find(",",strMovie.find_first_of(",") + 1) - name.size() - 1) };
		description = strMovie.substr(strMovie.find(internal_release_year) + internal_release_year.size() + 1);

		release_year = std::stoi(internal_release_year);

		const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789"
			".";

		name.erase(0, name.find_first_of(pattern));
		name.erase(name.find_last_of(pattern) + 1);
		description.erase(0, description.find_first_of(pattern));
		description.erase(description.find_last_of(pattern) + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& m) {
		return os << std::setw(40) << m.title() << " | " << std::right << std::setw(4) << m.release_year << " | " << m.description << "\n";
	}

	const std::string& Movie::title() const {
		return name;
	}
}