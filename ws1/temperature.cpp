#include "temperature.h"

double celsius_to_fahrenheit(double celsius) {
	return celsius * 1.8 + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
	return (fahrenheit - 32) / 1.8;
}
