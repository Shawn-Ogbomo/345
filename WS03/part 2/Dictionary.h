//Filename: Dictionary.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/02/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <iostream>
#include <iomanip>

namespace sdds {
	class Dictionary {
	public:
		Dictionary();
		explicit Dictionary(const std::string& term, const std::string& definition);
		friend bool operator ==(const Dictionary& left, const Dictionary& right);
		friend std::ostream& operator << (std::ostream& os, const Dictionary& d);
		const std::string& getTerm() const;
		const std::string& getDefinition() const;
	private:
		std::string m_term;
		std::string m_definition;
	};
}