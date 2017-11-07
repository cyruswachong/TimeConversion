#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include "TimeFormatMistake.h"

using namespace std;

TimeFormatMistake::TimeFormatMistake()
{
    //not necessary, just wrote it here
}
TimeFormatMistake::TimeFormatMistake(string input)
{
/**
* @brief This function sets the value of inTime as the inputted time
*
* @param "input" is an inputted string variable
*/
    inTime = input;
}
string TimeFormatMistake::getTime()
{
/**
* @brief This function returns the inputted time
* @return string
*/
    return inTime;
}
    

    