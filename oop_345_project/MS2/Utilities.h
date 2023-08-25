//Filename: Utilities.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
namespace sdds {
	class Utilities {
	public:
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		size_t getFieldWidth() const;
		void setFieldWidth(size_t newWidth);
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	private:
		size_t m_widthField = 1;
		static inline char m_delimiter{};
	};
}