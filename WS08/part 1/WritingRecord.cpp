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

		for (auto i = 0; i < emp_sz; ++i) {
			for (auto j = 0; j < sal_sz; ++j) {
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
}