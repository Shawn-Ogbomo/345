//Filename: Movie.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class Movie {
	public:
		Movie();
		explicit Movie(const std::string& strMovie);
		friend std::ostream& operator << (std::ostream& os, const Movie& m);
		const std::string& title() const;
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(name);
			spellChecker(description);
		}
	private:
		std::string name;
		unsigned release_year{};
		std::string description;
	};
}