// Workshop 1
// Wail Mardini - 2022/07/04
// Cornel - 2022/09/08

#include <iostream>
#include <iomanip>
#include <fstream>
#include "carads.h"
#include "carads.h" // This is intentional to test your safe guard in .h file

// TODO: explain in the reflection what is the effect of the keyword "constexpr"
constexpr int MAX_CARS = 100;

int cout = 0; // this is intentional

//check the format of the input file at the end of this file

// TODO: write the prototype for the main function
//         to accept command line arguments
double g_taxrate{};
double g_discount{};

int main(int argc, char* argv[])
{
	// will break compilation if best practices about namespaces are ignored
	cout = 1;

	// This functions lists the command line arguments
	sdds::listArgs(argc, argv);

	// Read all ads and record them
	sdds::Cars recordedCarsOnAds[MAX_CARS];

	// Keep a count of how many new cars and all cars read
	size_t newCars = 0, allCars = 0;

	sdds::Cars currentCar;

	std::cout << "--------------------\n";
	std::cout << "All Cars\n";
	std::cout << "--------------------\n";

	std::cout << "    Brand     | Model     | Year |Price w/Tax |Special Price" << std::endl;

	for (auto ad = 1; ad < argc; ++ad)
	{
		// Rates change from ad 1 to ad 2
		if (ad == 1) { // special day! no tax for all cars and 10% discount for applicable cars!
			g_taxrate = 0;
			g_discount = 0.10;
		}
		else {
			g_taxrate = 0.13;
			g_discount = 0.05;
		}

		// each parameter contains the orders from one day, process each one at a time
		std::ifstream in(argv[ad]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << argv[ad] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}

		// loop through each ad
		while (!in.eof())
		{
			// read in the rest of the data as a FoodOrder
			currentCar.read(in);

			// Count the new cars
			if (currentCar.getStatus() == 'N') {
				newCars++;
			}
			recordedCarsOnAds[allCars++] = currentCar;
			currentCar.display(0);
		}
	}

	// print the new cars
	std::cout << "--------------------\n";
	std::cout << "New Cars\n";
	std::cout << "--------------------\n";
	std::cout << "    Brand     | Model     | Year |Price w/Tax |Special Price" << std::endl;
	bool resetCounter = true;
	for (auto i = 0u; i < allCars; ++i)
		if (recordedCarsOnAds[i].getStatus() == 'N') {
			if (resetCounter) {
				recordedCarsOnAds[i].display(resetCounter);
				resetCounter = false;
			}
			else
				recordedCarsOnAds[i].display(resetCounter);
		}
	std::cout << "--------------------\n";
}

/* input file format: a comma separated set of fields with a consistent format of
<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
e.g.:
U,Honda,CRV,2015,15000,Y

<Order Tag> can be one of:
	N - New Car (Milage zero)
	U - Used Car

<Discount status> can be one of:
	Y - Discount applies
	N - Discount does not apply
*/