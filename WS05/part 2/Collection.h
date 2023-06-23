//Filename: SpellChecker.h
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 06/18/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	template <typename T>
	class Collection {
	public:
		explicit Collection(const std::string& name)
			:title{ name } {
		}

		~Collection() {
			delete[] items;
		}

		Collection(const Collection& right) = delete;
		Collection& operator=(const Collection& right) = delete;

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {
			for (unsigned i = 0; i < c.len; ++i) {
				std::cout << c.items[i];
			}
			return os;
		}

		Collection<T>& operator+=(const T& item) {
			for (auto i = 0U; i < len; ++i) {
				if (items[i].title() == item.title()) {
					return *this;
				}
			}

			auto* items_new = new T[len + 1];

			for (auto j = 0U; j < len; ++j) {
				items_new[j] = items[j];
			}

			delete[] items;

			++len;
			items_new[len - 1] = item;

			items = items_new;

			if (fnc_ptr) {
				fnc_ptr(*this, item);
			}

			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx < 0 || idx == len) {
				throw std::out_of_range{ "** EXCEPTION: Bad index [" + std::to_string(idx) + "]." + " Collection has [" + std::to_string(len) + "] items." };
			}

			return items[idx];
		}

		T* operator[](const std::string& title) const {
			for (auto i = 0U; i < len; ++i) {
				if (items[i].title() == title) {
					return &items[i];
				}
			}

			return nullptr;
		}
		const std::string& name() const {
			return title;
		}

		size_t size() const {
			return len;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			Collection<T>::fnc_ptr = observer;
		}
	private:
		std::string title;
		T* items{};
		unsigned len{};
		void(*fnc_ptr)(const Collection<T>&, const T&) {};
	};
}