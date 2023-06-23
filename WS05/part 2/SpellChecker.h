//Filename: SpellChecker.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <array>
#include <string>

namespace sdds {
	class SpellChecker {
	public:
		explicit SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	private:
		std::array<std::string, 6> m_badWords;
		std::array<std::string, 6> m_goodWords;
		std::array<int, 6> replaced_words_count{};
	};
}