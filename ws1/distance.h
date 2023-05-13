#ifndef DISTANCE_H
#define DISTANCE_H

struct feet_inches {
	int feet;
	int inches;
};

double km_to_miles(double km);
double miles_to_km(double miles);
feet_inches meters_to_feet(double meters);

#endif //DISTANCE_H