//Filename: Restaurant.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Restaurant.h"
namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
		:reservs{ new Reservation * [cnt] } {
		for (auto i = 0U; i < cnt; ++i) {
			reservs[i] = new Reservation{ *reservations[i] };
			++count;
		}
	}

	Restaurant::~Restaurant() {
		for (auto i = 0U; i < count; i++) {
			delete reservs[i];
		}
		delete[] reservs;
	}

	Restaurant::Restaurant(const Restaurant& right) {
		*this = right;
	}

	Restaurant::Restaurant(Restaurant&& right) noexcept {
		*this = std::move(right);
	}

	Restaurant& Restaurant::operator=(const Restaurant& right) {
		if (this != &right) {
			for (auto i = 0U; i < count; ++i) {
				delete reservs[i];
			}

			delete[] reservs;
			count = right.count;
			reservs = new Reservation * [count];

			for (auto i = 0U; i < count; ++i) {
				reservs[i] = new Reservation{ *right.reservs[i] };
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& right) noexcept {
		if (this != &right) {
			for (auto i = 0U; i < count; ++i) {
				delete reservs[i];
			}

			delete[] reservs;

			count = right.count;
			right.count = 0;
			reservs = right.reservs;
			right.reservs = nullptr;
		}
		return *this;
	}

	Restaurant::operator size_t() const {
		return count;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& r) {
		static auto call_count = 0;
		++call_count;

		os << "--------------------------\n" << "Fancy Restaurant (" << call_count << ")\n"
			<< "--------------------------\n";

		if (!r.count) {
			os << "This restaurant is empty!\n";
		}

		else {
			for (auto i = 0U; i < r.count; ++i) {
				os << *r.reservs[i];
			}
		}

		os << "--------------------------\n";
		return os;
	}
}