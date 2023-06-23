//Filename: Timer.h
//Name:	Shawn Ogbomo
// Student #022609127
// //Section: NRA
// date: 05/28/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <chrono>

namespace sdds {
	class Timer {
	public:
		void start();
		long long stop() const;
	private:
		std::chrono::steady_clock::time_point beg;
	};
}