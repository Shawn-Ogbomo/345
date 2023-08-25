//Filename CustomerOrder.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
#include "CustomerOrder.h"

namespace sdds {
	CustomerOrder::CustomerOrder() = default;

	CustomerOrder::CustomerOrder(const CustomerOrder&) {
		throw std::string{ "error" };
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& right) noexcept {
		*this = std::move(right);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& right) noexcept {
		if (this != &right) {
			for (size_t i = 0; i < cntItem; ++i) {
				delete lstItem[i];
			}
			delete[] lstItem;
			name = right.name;
			product = right.product;
			cntItem = right.cntItem;
			lstItem = right.lstItem;
			right.name.clear();
			right.product.clear();
			right.cntItem = 0;
			right.lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < cntItem; ++i) {
			delete lstItem[i];
		}
		delete[] lstItem;
	}

	CustomerOrder::CustomerOrder(const std::string& order)
		:lstItem{ new Item * [1] } {
		Utilities u;
		size_t current_pos{};
		auto more_fields = true;

		name = u.extractToken(order, current_pos, more_fields);
		product = u.extractToken(order, current_pos, more_fields);

		lstItem[cntItem] = new Item(u.extractToken(order, current_pos, more_fields));
		++cntItem;

		while (more_fields) {
			auto lst_new = new Item * [cntItem + 1];

			for (size_t i = 0; i < cntItem; ++i) {
				lst_new[i] = new Item{ *lstItem[i] };
			}

			for (size_t internal_i = 0; internal_i < cntItem; ++internal_i) {
				delete lstItem[internal_i];
			}

			delete[] lstItem;

			lst_new[cntItem] = new Item(u.extractToken(order, current_pos, more_fields));

			++cntItem;
			lstItem = lst_new;
		}

		if (auto util_field_width = u.getFieldWidth(); m_widthField < util_field_width) {
			m_widthField = util_field_width;
		}
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		const auto& station_name = station.getItemName();
		for (size_t i = 0; i < cntItem; ++i) {
			if (lstItem[i]->itemName == station_name) {
				if (!lstItem[i]->isFilled && station.getQuantity() > 0) {
					lstItem[i]->isFilled = true;
					station.updateQuantity();
					lstItem[i]->serialNumber = station.getNextSerialNumber();
					os << "    Filled " << name << ", " << product << " [" << station_name << "]\n";
					return;
				}

				if (!lstItem[i]->isFilled && !station.getQuantity()) {
					os << "    Unable to fill " << name << ", " << product
						<< " [" << station_name << "]\n";
				}
			}
		}
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < cntItem; ++i) {
			if (lstItem[i]->itemName == itemName && !lstItem[i]->isFilled) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < cntItem; ++i) {
			if (!lstItem[i]->isFilled) {
				return false;
			}
		}
		return true;
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << name << " - " << product << "\n";
		for (size_t i = 0; i < cntItem; ++i) {
			os << "[" << std::right << std::setw(6) << std::setfill('0') << lstItem[i]->serialNumber << "] " << std::left
				<< std::setw(m_widthField) << std::setfill(' ') << lstItem[i]->itemName
				<< " - " << (lstItem[i]->isFilled ? "FILLED\n" : "TO BE FILLED\n");
		}
	}
}