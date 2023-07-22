#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>
#include <functional>

namespace sdds {
	template<typename T>
	class GeneratingList {
		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the
		//      valadity of SIN No's
		bool luhns_algorithm(const std::string& sin_no) const {
			/*	function isValid(cardNumber[1..length])
					sum : = 0
					parity : = length mod 2
					for i from 1 to length do
						if i mod 2 != parity then
							sum : = sum + cardNumber[i]
							elseif cardNumber[i] > 4 then
							sum : = sum + 2 * cardNumber[i] - 9
						else
							sum : = sum + 2 * cardNumber[i]
							end if
							end for
							return cardNumber[length] == (10 - (sum mod 10))
							end function*/

			auto sum = 0;
			auto parity = (sin_no.size() % 2);
			const auto sin_sz = sin_no.size();

			for (int i = sin_sz - 1; i >= 0; --i) {
				if (i % 2 != parity) {
					sum += (sin_no[i] - '0');
				}

				else if ((sin_no[i] - '0') > 4) {
					sum += (2 * (sin_no[i] - '0')) - 9;
				}

				else {
					sum += 2 * (sin_no[i] - '0');
				}
			}

			return  (10 - (sum % 10)) == 10;
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.

		void operator += (T* right) {
			list.push_back(std::move(*right));
			delete right;
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
