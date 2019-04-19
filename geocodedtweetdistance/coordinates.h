#ifndef COORDINATES_H
#define COORDINATES_H

//Class created in order to keep track of the latitude and longitude of a coordinate system.
class Coordinates {
	private:
		double latitude;
		double longitude;
		double distance; //In kilometers
	public:
		Coordinates(double, double);
		void setLatitude(double);
		void setLongitude(double);
		double returnLatitude();
		double returnLongitude();
		void printLatitude();
		void printLongitude();
		void printCoordinates();
        void calcDistance(Coordinates);
        double returnDistance();
};

#endif // COORDINATES_H
