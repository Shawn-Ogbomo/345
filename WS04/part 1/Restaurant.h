//Filename: Restaurant.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
	public:
		explicit Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& right);
		Restaurant(Restaurant&& right) noexcept;
		~Restaurant();
		Restaurant& operator=(const Restaurant& right);
		Restaurant& operator=(Restaurant&& right) noexcept;
		explicit operator size_t() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& r);
	private:
		Reservation** reservs{};
		size_t count{};
	};
}