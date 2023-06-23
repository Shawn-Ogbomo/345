//Filename: Book.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/17/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class Book {
	public:
		Book();
		explicit Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& b);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(description);
		}
	private:
		std::string author;
		std::string name;
		std::string country_published;
		double cost{};
		size_t year_published{};
		std::string description;
	};
}