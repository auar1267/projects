#include "twitterusers.h"
#include "coordinates.h"
#include "twitteruser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//Intializes number of twitter user accounts to zero, as none have been read it as of the construction of this object in the main code.
TwitterUsers::TwitterUsers() {
    numTwitterUsers = 0;
}

//Checks to make sure that we don't exceed the limit of how many accounts I previously set it to hold. If we don't exceed the limit, it adds the twitter user information to the current index of TwitterUser object and increases the value of the number of twitter users by one.
bool TwitterUsers::addTwitterUser(TwitterUser user) {
    if (numTwitterUsers >= 1000) {
        cout << "Data limit reached" << endl;
        return false;
    }
    collection[numTwitterUsers] = user;
    numTwitterUsers++;
    return true;
}

//Prints the number of twitter posts that fall within the user defined distance.
void TwitterUsers::printNumWithinDistance(double distance) {
    int counterWithin = 0;
    double totalTwitterUsers = numTwitterUsers;
    for (int i=0; i < numTwitterUsers; i++) {
        if (collection[i].getDistance() <= distance) {
            counterWithin++;
        }
    }
    cout<< "The number of tweets made within " << distance << " kilometers was " << counterWithin << " out of " << numTwitterUsers << "." <<endl;
    cout<< "In other words, " << counterWithin/totalTwitterUsers * 100.0 << "% of the tweets were made within" <<endl;
    cout<< distance << " kilometers of the 2014 Carlton Complex Wildfire.";
}

//Prints the twitter posts that fall within the user defined distance.
void TwitterUsers::printWithinDistance(double distance) {
    for (int i=0; i < numTwitterUsers; i++)  {
        if (collection[i].getDistance() <= distance) {
            collection[i].print();
            cout<< "This tweet was made " << collection[i].getDistance() << " kilometers from the 2014 Carlton Complex Wildfire." <<endl;
        }
    }
}

//Prints all the twitter posts, and what distance they were from the 2014 Carlton Complex Wildfire,
void TwitterUsers::printAll() {
    for (int i=0; i < numTwitterUsers; i++)  {
        collection[i].print();
        cout<< "This tweet was made " << collection[i].getDistance() << " kilometers from the 2014 Carlton Complex Wildfire." <<endl;
    }
}
