#include <cmath>
#include "distance.h"


double km_to_miles(double km) {
	return km * 0.6214;
}

double miles_to_km(double miles) {
	return miles / 0.6214;
}

feet_inches meters_to_feet(double meters) {
	double aux = meters * 3.28084;
	feet_inches result;
	result.feet = floor(aux);
	result.inches = round((aux - result.feet) * 12);
	return result;
}