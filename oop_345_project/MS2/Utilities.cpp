//Filename: Utilities.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Utilities.h"

namespace sdds {
	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token;

		if (str[next_pos] == m_delimiter) {
			more = false;
			throw std::string("");
		}

		if (auto found = str.find(m_delimiter, next_pos); found != std::string::npos) {
			for (auto i = next_pos; i < found; ++i) {
				token += str[i];
			}

			next_pos = found + 1;

			more = true;
		}

		else if (found == std::string::npos) {
			auto str_sz = str.size();
			for (auto i = next_pos; i < str_sz; ++i) {
				token += str[i];
			}
			more = false;
		}

		if (isspace(token.front())) {
			const auto index_non_space = token.find_first_not_of(" ");
			token.erase(0, index_non_space);
		}

		if (auto index_of_period = token.find_first_of('.'); index_of_period != std::string::npos) {
			token.erase(index_of_period + 1);
		}

		else if (isspace(token.back())) {
			const auto index_of_final_char_or_digit = token.find_last_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"0123456789");
			token.erase(index_of_final_char_or_digit + 1);
		}

		if (auto token_sz = token.size(); m_widthField < token_sz) {
			setFieldWidth(token_sz);
		}
		return token;
	}
}