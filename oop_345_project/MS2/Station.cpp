//Filename: Station.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include <iostream>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	sdds::Station::Station() = default;

	sdds::Station::Station(const std::string& record) {
		Utilities u;
		size_t current_pos{};
		auto more_fields = true;

		name = u.extractToken(record, current_pos, more_fields);
		serial_number = std::stoi(u.extractToken(record, current_pos, more_fields));
		num_items_in_stock = (std::stoi(u.extractToken(record, current_pos, more_fields)));
		description = u.extractToken(record, current_pos, more_fields);
		++id_generator;
		m_widthField = u.getFieldWidth();
		id = static_cast<int>(id_generator);
	}
}

const std::string& sdds::Station::getItemName() const {
	return name;
}

size_t sdds::Station::getNextSerialNumber() {
	return serial_number++;
}

size_t sdds::Station::getQuantity() const {
	return num_items_in_stock;
}

void sdds::Station::updateQuantity() {
	if (num_items_in_stock) {
		--num_items_in_stock;
	}
}

void sdds::Station::display(std::ostream& os, bool full) const {
	if (!full) {
		os << std::right << std::setfill('0') << std::setw(3) << id << " | " << std::setw(m_widthField - 1)
			<< std::left << std::setfill(' ') << name << "| " << std::right << std::setfill('0')
			<< std::setw(6) << serial_number << " | " << "\n";
	}
	else {
		os << std::right << std::setfill('0') << std::setw(3) << id << " | " << std::setw(m_widthField - 1)
			<< std::left << std::setfill(' ') << name << "| " << std::right << std::setfill('0') << std::setw(6)
			<< serial_number << " | " << std::right << std::setfill(' ') << std::setw(4) << std::setw(4)
			<< num_items_in_stock << " | " << std::left << description << "\n";
	}
}