#ifndef SDDS_EMPPROFILE_H
#define SDDS_EMPPROFILE_H

#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>

namespace sdds {
	struct Employee {
		std::string id;
		std::string name;
		bool load(std::ifstream& f) {
			f >> id >> name;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << id << std::setw(7) << name << std::endl;
		}
	};

	struct Salary {
		std::string id;
		double salary;
		bool load(std::ifstream& f) {
			f >> id >> salary;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << id << std::setw(10) << salary << std::endl;
		}
	};

	struct EmployeeWage {
		std::string name{};
		double m_salary{};
		int m_counter{};
		static int recCount;
		static bool Trace;

		EmployeeWage() {
			m_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Default Constructor [" << m_counter << "]" << std::endl;
			}
		}

		EmployeeWage(const std::string& str, double sal)
		{
			this->name = str;
			this->m_salary = sal;
			m_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Ovdrloaded Constructor" << std::setw(6) << "[" << m_counter << "]" << std::endl;
			}
		}

		EmployeeWage(const EmployeeWage& copyEmpProf) {
			this->name = copyEmpProf.name;
			this->m_salary = copyEmpProf.m_salary;
			m_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Copy Constructor " << std::setw(11) << "[" << m_counter << "] from [" << copyEmpProf.m_counter << "]" << std::endl;
			}
		}

		~EmployeeWage() {
			if (Trace)
			{
				std::cout << "Destructor " << std::setw(17) << "[" << m_counter << "]" << std::endl;
			}
		}

		//TODO: add a function here to check correct salary range
		void rangeValidator() const {
			constexpr auto max_salary = 99999;
			if (m_salary <0 || m_salary > max_salary) {
				throw std::string{ "salary range is not valid" };
			}
		}

		void print(std::ostream& os)const {
			os << std::setw(15) << name << std::setw(10) << m_salary << std::endl;
		}
	};
}
#endif // !SDDS_EMPPROFILE_H
