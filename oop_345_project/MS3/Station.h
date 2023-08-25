//Filename: Station.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
namespace sdds {
	class Station {
	public:
		Station();
		explicit Station(const std::string& record);
		virtual ~Station() = default;
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		virtual void display(std::ostream& os, bool full) const;
	private:
		std::string name;
		int id{};
		unsigned num_items_in_stock{};
		std::string description;
		unsigned serial_number{};
		static inline size_t m_widthField = 1;
		static inline size_t id_generator{};
	};
}