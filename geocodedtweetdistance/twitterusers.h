#ifndef TWITTERUSERS_H
#define TWITTERUSERS_H
#include "twitteruser.h"

//TwitterUsers class the is a composite of a bunch of TwitterUser classes, keeps track of how many based on data collected from .csv file.
class TwitterUsers {
    private:
        TwitterUser collection[1000]; //1000 was just a number I chose that I figured would be more than enough to cover an array of all the twitter users. This is why the empty constructor was needed for the TwitterUser class, as I have no string to supply to it (yet).
        int numTwitterUsers;
    public:
        TwitterUsers();
        bool addTwitterUser(TwitterUser);
        void printNumWithinDistance(double);
        void printWithinDistance(double);
        void printAll();
};

#endif // TWITTERUSERS_H
