//Filename: ConfirmationSender.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09	/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& right);
		ConfirmationSender(ConfirmationSender&& right) noexcept;
		~ConfirmationSender();
		void increment();
		void decrement();
		ConfirmationSender& operator= (const ConfirmationSender& right);
		ConfirmationSender& operator= (ConfirmationSender&& right) noexcept;
		ConfirmationSender& operator +=(const Reservation& res);
		ConfirmationSender& operator -=(const Reservation& res);
		friend std::ostream& operator<< (std::ostream& os, const ConfirmationSender& cs);
	private:
		const Reservation** reservations{};
		size_t count{};
	};
}