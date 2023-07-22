#include <iostream>
#include <fstream>
#include <iomanip>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;
using namespace sdds;

int EmployeeWage::recCount = 0;
bool EmployeeWage::Trace = true;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4) {
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	try {
		sdds::GeneratingList<sdds::Employee> emp(argv[1]);
		sdds::GeneratingList<sdds::Salary> correctSal(argv[2]);
		sdds::GeneratingList<sdds::Salary> wrongSal(argv[3]);

		cout << setw(10) << "SIN No" << setw(17) << "Employee Name" << endl;
		cout << emp << endl;

		cout << "********************************************" << endl
			<< "* Correct Salaries with SIN No's" << endl
			<< "********************************************" << endl;
		cout << setw(10) << "SIN No" << setw(10) << "Salary" << endl;
		cout << correctSal << endl;

		cout << "********************************************" << endl
			<< "* Wrong Salaries with SIN No's" << endl
			<< "********************************************" << endl;
		cout << setw(10) << "SIN No" << setw(10) << "Salary" << endl;
		cout << wrongSal << endl;

		EmployeeWage::Trace = true;
		cout << "********************************************" << endl
			<< "* Merging wrong salaries using Raw Pointers" << endl
			<< "********************************************" << endl;

		try {
			GeneratingList<EmployeeWage> empPro = writeRaw(emp, wrongSal);
		}
		catch (const string& msg)
		{
			cout << "ERROR: " << msg << endl;
		}

		cout << endl;
		cout << "********************************************" << endl
			<< "* Merging wrong salaries using Smart Pointers" << endl
			<< "********************************************" << endl;
		try {
			GeneratingList<EmployeeWage> empPro = writeSmart(emp, wrongSal);;
		}
		catch (const string& msg) {
			cout << "ERROR: " << msg << std::endl;
		}

		EmployeeWage::Trace = false;
		cout << endl << endl;
		// no exceptions should be generated from the code below.
		cout << "********************************************" << endl
			<< "* Merging correct salaries using Raw Pointers" << endl
			<< "********************************************" << endl;
		{
			GeneratingList<EmployeeWage> empPro = writeRaw(emp, correctSal);
			cout << setw(5) << "Employee Name" << setw(10) << "Salary" << endl;
			cout << empPro << endl;
		}

		cout << "********************************************" << endl
			<< "* Merging good prices using Smart Pointers" << endl
			<< "********************************************" << endl;
		{
 			GeneratingList<EmployeeWage> empPro = writeSmart(emp, correctSal);
			cout << setw(5) << "Employee Name" << setw(10) << "Salary" << endl;
			cout << empPro << endl;
		}
	}
	catch (...)
	{
		cout << "ERROR: Unknown error!";
	}

	return 0;
}