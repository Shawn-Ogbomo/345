//Filename: Reservation.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	class Reservation {
	public:
		Reservation();
		explicit Reservation(const std::string& res);
		Reservation(const Reservation& right);
		Reservation& operator= (const Reservation& right);
		friend std::ostream& operator << (std::ostream& os, const Reservation& r);
		void update(int day, int time);
	private:
		std::string id;
		std::string name;
		std::string email;
		int people{};
		int d{};
		int hour{};
	};
}