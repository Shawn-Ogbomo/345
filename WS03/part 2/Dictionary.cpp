//Filename: Dictionary.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/02/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//---------------
#include "Dictionary.h"

namespace sdds {
	Dictionary::Dictionary() = default;

	Dictionary::Dictionary(const std::string& term, const std::string& definition)
		:m_term{ term },
		m_definition{ definition } {}

	std::ostream& operator << (std::ostream& os, const Dictionary& d) {
		return os << std::right << std::setw(20) << d.m_term << ": " << d.m_definition;
	}

	bool operator ==(const Dictionary& left, const Dictionary& right) {
		return left.getTerm() == right.getTerm();
	}

	const std::string& Dictionary::getTerm() const {
		return m_term;
	}

	const std::string& Dictionary::getDefinition() const {
		return m_definition;
	}
}