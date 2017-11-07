#include <string>

#ifndef TIMEFORMATMISTAKE_H
#define TIMEFORMATMISTAKE_H

using namespace std;

class TimeFormatMistake
{
    public:
    TimeFormatMistake();
    //Post-Condition: has no effect on my code, kept it just incase
    TimeFormatMistake(string input);
    //Pre-Condition: there is a string input, meant to be an invalid inputted time
    //Post-Condition: sets the invalid input
    string getTime();
    //Post-Condition: This function accesses the private variable that holds the invalid time input
        
    private:
    string inTime;
    // invalid time input
};

#endif