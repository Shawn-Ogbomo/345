//Filename CustomerOrder.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 07/07/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <string>
namespace sdds {
	class CustomerOrder {
	public:
		struct Item {
			explicit Item(const std::string& src) : itemName(src) {};
			std::string itemName;
			size_t serialNumber{ 0 };
			bool isFilled{ false };
		};
		CustomerOrder();
		explicit CustomerOrder(const std::string& order);
		CustomerOrder(const CustomerOrder&);
		explicit CustomerOrder(CustomerOrder&& right) noexcept;
		CustomerOrder& operator = (const CustomerOrder& right) = delete;
		CustomerOrder& operator = (CustomerOrder&& right) noexcept;
		~CustomerOrder();
		void fillItem(Station& station, std::ostream& os);
		bool isItemFilled(const std::string& itemName) const;
		bool isOrderFilled() const;
		void display(std::ostream& os) const;
	private:
		std::string name;
		std::string product;
		size_t cntItem{};
		Item** lstItem{};
		static inline size_t m_widthField{};
	};
}