#include "coordinates.h"
#include "twitteruser.h"
#include "twitterusers.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

/*The main function creates a TwitterUsers object which is made up of TwitterUser objects, 
 which also contain Coordinates. It then reads in data from the .csv file which is then 
 kept track of in the objects mentioned above. The program then uses said data to determine 
 the distance from the fire the tweets were made from. It also keeps track of to total number of  
 unique tweets (not unique twitter accounts, multiple accounts make multiple tweets that are
 tracked seperately). The main function checks to see how many tweets were made within a user specified 
 distance. It also gives the user the option to view all tweets at once.
 */
int main() {
    string data;
    TwitterUsers userRecords;
    ifstream infile;
    string fileName = "geocodedTweets.csv";
    infile.open("geocodedTweets.csv");
    if (infile.good()) {
        cout << "Reading in data from " << fileName << endl;

        getline(infile, data);
        bool good = true;

        while (getline(infile,data)) {
            good = userRecords.addTwitterUser(TwitterUser(data)); //adds data from the .csv file as long as the program can finds data to add.
            if (!good) {
                break;
            }
        }
    }

    //Main menu of the program, will continue to run until the user indicates wish to quit.
    cout<< "\n" << "Welcome. This program asks the user to input a distance in kilometers " <<endl;
    cout<< "and prints out the number of tweets made during the 2014 Carlton Complex " <<endl;
    cout<< "Wildfire that were made within the user specified distance. You can then have " <<endl;
    cout<< "the program print out all those specific tweets or enter a new distance." <<endl;

    bool run = true;
    while (run == true) {
   		int menuOption = 0;
        cout<< endl;
        cout<< "Menu" << endl;
        cout<< "----" <<endl;
        cout<< "1) Calculate number of tweets made within distance (km)" <<endl;
        cout<< "2) Print all tweets." <<endl;
        cout<< "3) Quit" <<endl;
        cout<< "Enter the desired option (3 to quit): ";
        cin>> menuOption;

        if (menuOption == 1) {
        	double userDistance;
        	cout<< "\n" << "Please enter the desired distance (in kilometers): ";
        	cin>>userDistance;

        	if (userDistance < 0) {
                cout<< "\n" << "You input a negative distance, please try again." <<endl;
        	}

        	else {
                userRecords.printNumWithinDistance(userDistance); //prints the number of tweets within the user specified distance.
                int printOption = 0;
                cout<< "\n\n" << "Would you like to view the tweets within this distance?" <<endl;
                cout<< "-------------------------------------------------------" <<endl;
                cout<< "1) Yes" <<endl;
                cout<< "2) No" <<endl;
                cout<< "Enter the desired option: ";
                cin>> printOption;

                if (printOption ==  1) {
                    userRecords.printWithinDistance(userDistance);  //prints the tweets that were within the user specified distance, if the user so wishes.
                    int returnOption = 0;
                    cout<< "\n" << "Would you like to return to the menu or end the program?" <<endl; //then gives the user the option to return to the menu or quit the program.
                    cout<< "--------------------------------------------------------" <<endl;
                    cout<< "1) Menu" <<endl;
                    cout<< "2) Quit" <<endl;
                    cout<< "Enter the desired option (2 to quit): ";
                    cin>> returnOption;

                    if (returnOption == 1) {

                    }

                    else if (returnOption == 2) {
                        run = false; //if they wish to quit the program this line of code ends the loop.
                    }

                    else {
                        cout<< "\n" << "This is not a valid choice, returning to menu." <<endl; //if invalid input was entered it returns to the menu regardless. Would admittedly keep my code from breaking so easily if a non number is entered if I had it set to just end the program on invalid input. Oh well.
                    }
                }

                else if (printOption == 2) { 
                                                //This is where the user is returned to the main menu if they don't want to view the tweets within the distance the specify.
                }

                else {
                    cout<< "\n" << "This is not a valid choice, returning to menu." <<endl;
                }
			}
		}

        else if (menuOption == 2) {
            userRecords.printAll(); //Prints every tweet. 
        }

        else if (menuOption == 3) {
            run = false; //Quit from main menu
        }

        else {
            cout<< "\n" << "This is not a valid input. Please try again." <<endl;
        }
    }
    return 0;
}
