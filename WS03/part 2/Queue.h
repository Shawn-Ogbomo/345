//Filename: Queue.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/02/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Dictionary.h"

namespace sdds {
	template <typename T, unsigned CAPACITY = 100>
	class Queue {
	public:
		Queue() = default;
		virtual ~Queue() = default;
		T& operator[](unsigned index) {
			return object_count && index < object_count ?
				objects[index] : dummy;
		}
		virtual bool push(const T& item) {
			if (CAPACITY - object_count > 0) {
				objects[object_count] = item;
				++object_count;
				return true;
			}
			return false;
		}
		T pop() {
			const auto object_at_first_element = objects[0];
			T temp{};
			if (object_count == 1) {
				--object_count;
				return object_at_first_element;
			}

			for (auto i = 0U; i < object_count; ++i) {
				temp = objects[i + 1];
				objects[i + 1] = objects[i];
				objects[i] = temp;
			}
			--object_count;
			return object_at_first_element;
		}
		unsigned size() const {
			return object_count;
		}
		void display(std::ostream& os = std::cout) const {
			os << "----------------------\n"
				<< "| Dictionary Content |\n" <<
				"----------------------\n";
			for (auto i = 0U; i < object_count; ++i) {
				os << objects[i] << "\n";
			}
			os << "----------------------\n";
		}
		const T* get_objects() const {
			return objects;
		}
		void set(unsigned pos, double val) {
			objects[pos] = val;
		}
		void increment_count() {
			++object_count;
		}
	private:
		unsigned object_count{};
		T objects[CAPACITY]{};
		T dummy{};
	};

	template<>
	class Queue<Dictionary, 100> {
	public:
		Queue() = default;
		virtual ~Queue() = default;
		Dictionary& operator[](unsigned index) {
			return internal_object_count && index < internal_object_count ?
				internal_objects[index] : internal_dummy;
		}
		virtual bool push(const Dictionary& item) {
			if (static constexpr auto limit = 100; limit - internal_object_count > 0) {
				internal_objects[internal_object_count] = item;
				++internal_object_count;
				return true;
			}
			return false;
		}
		unsigned size() const {
			return internal_object_count;
		}
		void display(std::ostream& os = std::cout) const {
			os << "----------------------\n"
				<< "| Dictionary Content |\n" <<
				"----------------------\n";
			for (auto i = 0U; i < internal_object_count; ++i) {
				os << internal_objects[i] << "\n";
			}
			os << "----------------------\n";
		}
		Dictionary pop() {
			const auto internal_object_at_first_element = internal_objects[0];
			Dictionary internal_temp{};
			if (internal_object_count == 1) {
				--internal_object_count;
				return internal_object_at_first_element;
			}

			for (auto i = 0U; i < internal_object_count; ++i) {
				internal_temp = internal_objects[i + 1];
				internal_objects[i + 1] = internal_objects[i];
				internal_objects[i] = internal_temp;
			}
			--internal_object_count;
			return internal_object_at_first_element;
		}

		const Dictionary* get_objects() const {
			return internal_objects;
		}
	private:
		unsigned internal_object_count{};
		Dictionary internal_objects[100]{};
		Dictionary internal_dummy{ "Empty Term","Empty Substitute" };
	};
}