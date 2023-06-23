//Filename: ConfirmationSender.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "ConfirmationSender.h"

namespace sdds {
	sdds::ConfirmationSender::ConfirmationSender() = default;

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& right) {
		*this = right;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& right) noexcept {
		*this = std::move(right);
	}

	ConfirmationSender::~ConfirmationSender() {
		for (auto i = 0U; i < count; ++i) {
			reservations[i] = nullptr;
		}

		delete[] reservations;
	}

	void ConfirmationSender::increment() {
		++count;
	}

	void ConfirmationSender::decrement() {
		--count;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& right) {
		if (this != &right) {
			for (auto i = 0U; i < count; ++i) {
				reservations[i] = nullptr;
			}

			delete[] reservations;
			count = right.count;
			reservations = new const Reservation * [count];

			for (auto j = 0U; j < count; ++j) {
				if (right.reservations[j]) {
					reservations[j] = right.reservations[j];
				}
				else {
					reservations[j] = nullptr;
				}
			}
		}
		return*this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& right) noexcept {
		if (this != &right) {
			for (auto i = 0U; i < count; ++i) {
				reservations[i] = nullptr;
			}

			delete[] reservations;
			count = right.count;
			reservations = right.reservations;
			right.count = 0;
			right.reservations = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		for (auto i = 0U; i < count; ++i) {
			if (reservations[i] == &res) {
				return *this;
			}
		}

		auto reservs_new = new const Reservation * [count + 1];

		for (auto j = 0U; j < count; ++j) {
			reservs_new[j] = reservations[j];
		}

		for (auto k = 0U; k < count; ++k) {
			reservations[k] = nullptr;
		}

		delete[]reservations;
		reservs_new[count] = &res;
		reservations = reservs_new;
		increment();
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (auto i = 0U; i < count; ++i) {
			if (reservations[i] == &res) {
				const auto found_at_pos = i;
				reservations[found_at_pos] = nullptr;
				return *this;
			}
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";

		if (!cs.count) {
			os << "There are no confirmations to send!\n" << "--------------------------\n";
		}

		else {
			for (auto i = 0U; i < cs.count; ++i) {
				if (cs.reservations[i]) {
					os << *cs.reservations[i];
				}
			}
			os << "--------------------------\n";
		}

		return os;
	}
}