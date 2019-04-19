#include "coordinates.h"
#include <iostream>
#include <cmath>
using namespace std;

//Construnctor for the object, using two doubles to define latitude and longitude.
Coordinates::Coordinates(double lat, double lon) {
	latitude = lat;
	longitude = lon;
}

//Allows the user to change the latitude.
void Coordinates::setLatitude(double lat) {
	latitude = lat;
}

//Allows the user to change the longitude.
void Coordinates::setLongitude(double lon) {
	longitude = lon;
}

//Returns the current value of latitude.
double Coordinates::returnLatitude() {
	return latitude;
}

//Returns the current value of longitude.
double Coordinates::returnLongitude() {
	return longitude;
}

//Prints out the latitude.
void Coordinates::printLatitude() {
	cout<< "The latitude is " << latitude <<endl;
}

//Prints out the longitude.
void Coordinates::printLongitude() {
	cout<< "The longitude is " << longitude <<endl;
}

//Prints out the latitude and longitude of the coordinate set.
void Coordinates::printCoordinates() {
	cout<< "The coordinates are " << latitude << ", " << longitude <<endl;
}

//Code that calculates the shortest distance between two sets of latitude/longitude coordinates.
//Code found on stackoverflow. http://stackoverflow.com/questions/365826/calculate-distance-between-2-gps-coordinates
void Coordinates::calcDistance(Coordinates input) {
	double pi = atan(1) * 4; //approximation of pi.
	double radiusOfEarth = 6371; //in kilometers
	double lat2 = input.returnLatitude() * pi/180.0;
	double lat1 = latitude * pi/180.0;
	double changeInLat = (latitude - input.returnLatitude()) * pi/180.0;
	double changeInLon = (longitude - input.returnLongitude()) * pi/180.0;
	double a = (sin(changeInLat/2.0) * sin(changeInLat/2.0)) + (sin(changeInLon/2.0) * sin(changeInLon/2.0)) * cos(lat1) * cos(lat2);
	double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
	distance = c * radiusOfEarth;
}

//Returns the distance calculated by the previous method.
double Coordinates::returnDistance() {
	return distance;
}