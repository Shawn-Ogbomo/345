//Filename: Reservation.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include <algorithm>
#include "Reservation.h"
#include "Util.h"

namespace sdds {
	Reservation::Reservation() = default;

	Reservation::Reservation(const std::string& res)
		:id{ res.substr(0, res.find_first_of(":")) },
		name{ res.substr(res.find(id) + id.size() + 1, (res.find(",",res.find(id) + id.size() + 1) - (res.find(id) + id.size() + 1))) },
		email{ res.substr((res.find(name) + name.size() + 1), (res.find(",",res.find(name) + name.size() + 1)) - (res.find(name) + name.size() + 1)) } {
		std::string p{ res.substr((res.find(email) + email.size() + 1) , (res.find(",", res.find(email) + email.size() + 1)) - (res.find(email) + email.size() + 1)) };
		std::string day{ res.substr((res.find(p) + p.size() + 1) , (res.find(",", res.find(p) + p.size() + 1)) - (res.find(p) + p.size() + 1)) };
		std::string h{ res.substr(res.find(day,res.find(p) + p.size() + 1) + day.size() + 1) };

		people = std::stoi(p);
		d = std::stoi(day);
		hour = std::stoi(h);

		const auto pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789";

		id.erase(0, id.find_first_of(pattern));
		id.erase(id.find_last_of(pattern) + 1);
		name.erase(0, name.find_first_of(pattern));
		name.erase(name.find_last_of(pattern) + 1);
		email.erase(0, email.find_first_of(pattern));
		email.erase(email.find_last_of(pattern) + 1);
	}

	Reservation::Reservation(const Reservation& right) {
		*this = right;
	}

	Reservation& Reservation::operator=(const Reservation& right) {
		if (this != &right) {
			id = right.id;
			name = right.name;
			email = right.email;
			people = right.people;
			d = right.d;
			hour = right.hour;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& r) {
		if (r.hour >= 6 && r.hour <= 9) {
			os << "Reservation" << std::right << std::setw(11) << r.id << ":" << std::setw(21) << r.name << "  " << std::left << std::setw(24) << "<" + r.email + ">" << "Breakfast on day " << r.d << " @ " << r.hour << ":00 for " << r.people << (r.people == 1 ? " person" : " people") << ".\n";
		}

		else if (r.hour >= 11 && r.hour <= 15) {
			os << "Reservation" << std::right << std::setw(11) << r.id << ":" << std::setw(21) << r.name << "  " << std::left << std::setw(24) << "<" + r.email + ">" << "Lunch on day " << r.d << " @ " << r.hour << ":00 for " << r.people << (r.people == 1 ? " person" : " people") << ".\n";
		}

		else if (r.hour >= 17 && r.hour <= 21) {
			os << "Reservation" << std::right << std::setw(11) << r.id << ":" << std::setw(21) << r.name << "  " << std::left << std::setw(24) << "<" + r.email + ">" << "Dinner on day " << r.d << " @ " << r.hour << ":00 for " << r.people << (r.people == 1 ? " person" : " people") << ".\n";
		}

		else {
			os << "Reservation" << std::right << std::setw(11) << r.id << ":" << std::setw(21) << r.name << "  " << std::left << std::setw(24) << "<" + r.email + ">" << "Drinks on day " << r.d << " @ " << r.hour << ":00 for " << r.people << (r.people == 1 ? " person" : " people") << ".\n";
		}

		return os;
	}

	void Reservation::update(int day, int time) {
		d = day;
		hour = time;
	}
}