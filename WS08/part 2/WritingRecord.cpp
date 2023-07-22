//Filename: WritingRecord.cpp
//Name:	Shawn Ogbomo
// Student #022609127
//Section: NRA
// date: 07/21/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		const auto emp_sz = emp.size();
		const auto sal_sz = sal.size();
		EmployeeWage* found_employee{};

		for (auto i = 0U; i < emp_sz; ++i) {
			for (auto j = 0U; j < sal_sz; ++j) {
				if (emp[i].id == sal[j].id) {
					if (activeEmp.luhns_algorithm(emp[i].id)) {
						try {
							found_employee = new EmployeeWage{ emp[i].name,sal[j].salary };
							found_employee->rangeValidator();
							activeEmp += found_employee;
						}
						catch (...) {
							delete found_employee;
							throw;
						}
					}
					else {
						throw std::string{ "Invalid SIN..." };
					}
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		const auto emp_sz = emp.size();
		const auto sal_sz = sal.size();

		for (auto i = 0U; i < emp_sz; ++i) {
			for (auto j = 0U; j < sal_sz; ++j) {
				if (emp[i].id == sal[j].id) {
					if (activeEmp.luhns_algorithm(emp[i].id)) {
						auto found_employee(std::make_unique<EmployeeWage>(emp[i].name, sal[j].salary));
						found_employee->rangeValidator();
						activeEmp += std::move(found_employee);
					}
					else {
						throw std::string{ "Invalid SIN..." };
					}
				}
			}
		}
		return activeEmp;
	}
}