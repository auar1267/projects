#include "coordinates.h"
#include "twitteruser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Long ass constructor that uses stringsteam to retrieve tweet data from a string build the TwitterUser Class.
//I use a variable called junk to store all the data I don't plan on using. Not going to lie, this felt weird to code, as in I feel this could have been done better.
TwitterUser::TwitterUser(string s) {
    string junk;
    stringstream datastream(s);
    getline(datastream,junk,','); //Commas seperate each row in a .csv file when that .csv while is read into a string.
    getline(datastream,tweetDate,',');
    getline(datastream,tweetHour,',');
    getline(datastream,tweetMinute,',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,junk,'"'); //Used this to remove quotation marks from latitude data, without this my latitudes were always taking on a value of zero.
    string strLat;
    getline(datastream,strLat,',');
    double tempLat;
    stringstream latConvert(strLat);
    latConvert>>tempLat;
    tweetLocation.setLatitude(tempLat);
    string strLon;
    getline(datastream,strLon,'"');
    double tempLon;
    stringstream lonConvert(strLon);
    lonConvert>>tempLon;
    tweetLocation.setLongitude(tempLon);
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,screenName,',');
    getline(datastream,junk,',');
    string idStr;
    getline(datastream,idStr,',');
    stringstream idConvert(idStr);
    idConvert>>userId;
    getline(datastream, userLink, ',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream,junk,',');
    getline(datastream, tweetContent, '\n'); //Because the tweet itself was contained in the last row of data in the .csv file, I could instead use the '\n' character as my parameter to stop reading the string. 
                                             //If I had used a comma as a parameter instead, there would be the chance that it would cut the tweet off early if it contained a comma.
}

//Empty constructor defined so that I could define a TwitterUser object in another class without having to supply a string.
TwitterUser::TwitterUser() {

}

//Givin the coordinates of the 2014 Carlton Complex Wildfire and the tweet, it will calculate the distance between the two.
double TwitterUser::getDistance() {
    Coordinates initialCoordinates(48.211, -120.103);
    tweetLocation.calcDistance(initialCoordinates);
    return tweetLocation.returnDistance();
}

//Prints out the contents of the TwitterUser Class.
void TwitterUser::print() {
    cout<< "\n" << "Twitter User: " << screenName << "\n" << "User ID: " << userId << "\n" << "User Link: " << userLink << "\n" << "Date: " << tweetDate << "\n" << "Time: " << tweetHour << ":" << tweetMinute << "\n" << "Tweet: " << tweetContent <<endl;
    tweetLocation.printCoordinates();
}

