//Filename: Timer.cpp
//Name:	Shawn Ogbomo
//Student #022609127
//Section: NRA
//date: 05/28/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Timer.h"
namespace sdds {
	void Timer::start() {
		beg = std::chrono::steady_clock::now();
	}

	long long Timer::stop() const {
		const auto end = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::nanoseconds>(end - beg).count();
	}
}