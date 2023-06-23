//Filename: UniqueQueue.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/02/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <cmath>
#include "Queue.h"

namespace sdds {
	template <typename T>
	class UniqueQueue : public Queue< T, 100> {
	public:
		virtual	bool push(const T& item) {
			auto contains_duplicates = false;
			const auto objects = Queue<T, 100>::get_objects();
			const auto que_sz = Queue<T, 100>::size();

			for (auto i = 0U; i < que_sz; ++i) {
				if (item == objects[i]) {
					return contains_duplicates;
				}
			}
			return Queue<T, 100>::push(item);
		}
	};
	template<>
	bool UniqueQueue<double>::push(const double& item) {
		const auto internal_que_sz = this->size();
		if (constexpr auto limit = 100; internal_que_sz >= limit) {
			return false;
		}

		constexpr auto thresh_hold = 0.005;
		auto internal_contains_duplicates = false;
		const auto internal_objects = this->get_objects();

		for (auto i = 0U; i < internal_que_sz; ++i) {
			if (std::fabs(item - internal_objects[i]) <= thresh_hold) {
				return internal_contains_duplicates;
			}
		}

		set(internal_que_sz, item);
		increment_count();
		return true;
	}
}