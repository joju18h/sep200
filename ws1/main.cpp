#include <iostream>
#include "distance.h"
#include "temperature.h"

int main() {
	int temp, distance;

	std::cout << "Enter a temperature in celsius: ";
	std::cin >> temp;
	std::cout << temp << "C in Fahrenheit is: " << celsius_to_fahrenheit(temp) << "F" << std::endl;

	std::cout << "Enter a temperature in fahrenheit: ";
	std::cin >> temp;
	std::cout << temp << "F in Celsius is: " <<
		fahrenheit_to_celsius(temp) << "C" << std::endl;

	std::cout << "Enter a distance in kilometers: ";
	std::cin >> distance;
	std::cout << distance << "km in miles is: " <<
		km_to_miles(distance) << " miles" << std::endl;

	std::cout << "Enter a distance in miles: ";
	std::cin >> distance;
	std::cout << distance << " miles in kilometers is: " <<
		miles_to_km(distance) << "km" << std::endl;

	std::cout << "Enter a distance in meters: ";
	std::cin >> distance;
	feet_inches result;
	result = meters_to_feet(distance);
	std::cout << distance << " meters in feet/inches is: " <<
		result.feet << "'" << result.inches << "''" << std::endl;

	return 0;
}

/* SHORT ANSWER QUESTIONS
Q1 - What errors does the compiler point out if you forget to include the header files?

- Essentially the functions and the struct defined and declared in the header and implemenation file respectively are not included and hence the compiler cannot find them.
So it gives us an undefined identifier error which is a syntatic error.

Q2 - What error does the compiler point out if you forget to define the variables temp
and distance at the beginning of main()?

- If you forget to define temp and distance at the beginning of main, the compiler gives out an undefined identifier error which is a syntatic error.

Q3 - What errors does the compiler point out if you forget to add the semi-colon (;)
at the end of "std::cin >> temp;"

The compiler shows the expected ';' after expression at the exact line and column error, which indicates a syntatic error.

Q4 - Does the compiler gives an error if temp and distance are defined as ints,
instead of doubles? If not, how come functions defined to operate on doubles, can
operate on ints? Check: https://www.cplusplus.com/doc/tutorial/typecasting/

- No it doesnt because C++ has implicit type conversion/coercion in place that promotes int data types to double automatically.(lower datatype to higher datatype)



*/
