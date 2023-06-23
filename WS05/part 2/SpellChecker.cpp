//Filename: SpellChecker.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream ifs{ filename };

		if (!ifs) {
			throw std::string{ "** EXCEPTION: Bad file name!" };
		}

		for (auto i = 0U; !ifs.eof(); ++i) {
			ifs >> m_badWords[i] >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& text) {
		auto pos = 0;
		auto count = 0;
		for (const auto& word : m_badWords) {
			for (auto found_index = text.find(word); found_index != std::string::npos;) {
				text.replace(found_index, word.size(), m_goodWords[pos]);
				replaced_words_count[count] += 1;
				found_index = text.find(word);
			}
			++count;
			++pos;
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";
		auto count = 0;
		for (const auto& word : m_badWords) {
			out << std::right << std::setw(15) << word << ": " << replaced_words_count[count] << " replacements\n";
			++count;
		}
	}
}