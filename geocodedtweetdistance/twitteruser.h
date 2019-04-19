#ifndef TWITTERUSER_H
#define TWITTERUSER_H
#include <string>
#include "coordinates.h"
using namespace std;

//Twitter User class that contains information on the username, user id, and link to the twitter account. 
//Also contains the location, time, and date of the tweet. Also contains the content of each tweet. 
class TwitterUser {
    private:
        string screenName;
        string tweetDate;
        string tweetHour;
        string tweetMinute;
        Coordinates tweetLocation{0,0};
        int userId;
        string userLink;
        string tweetContent;
    public:
        TwitterUser(string);
        TwitterUser();
        double getDistance();
        void print();
};

#endif // TWITTERUSER_H
