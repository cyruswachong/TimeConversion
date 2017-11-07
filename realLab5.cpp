/**
* @file realLab5.cpp
* @author Cyrus WaChong
* @date November 3, 2017
* @version 1
*
* @brief <ENSC 251, Lab 5>
*
* @section DESCRIPTION
*
* This lab converts basic 24 hour time to 12 hour time, and makes sure that the input is valid
* I used strings to test my knowledge on how they works, and to make sure that my outputted 
* error time actually existed, unlike when you use integers.
*
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include "TimeFormatMistake.h"

using namespace std;


bool validCheck(string input);
void converter(string input);

int main()
{
        string inTime;
        char restart = 'y';
        cout << "Please include a 0 infront of the first 9 hours of the day (e.g. 09:34)" << endl;
            
            // this while() loop allows the user to repeat the loop as long as he inputs 'y' as a value for restart, or if they give an invalid input
            while ((restart != 'n' || restart != 'N') && (restart == 'y' || restart == 'Y'))
            {
                try
                {
                    cout << "Enter time in 24-hour notation (e.g 12:34):" << endl;
                    cin >> inTime;
                    
                    // Uses my "validCheck" function to check whether the input in valid
                    // if it is not, it throws to the catch statement
                    if (validCheck(inTime) == false)
                    {
                        throw TimeFormatMistake(inTime);
                    }
                    
                    // uses my "converter" function to calculate the final output,
                    // then prompts the user to restart, and acts accordingly
                    converter(inTime);
                    cout << "Again? (y/n)" << endl;
                    cin >> restart;
                    continue;
                }
                
                // takes the thrown value, and outputs the error code and time value stored in the "TimeFormatMistake" class.
                catch(TimeFormatMistake e)
                {
                    cerr << "No such time as "<< e.getTime() << ", Try again:" << endl;
                }
            }
        cout << "End of Program"<<endl;
        return 0;
}

bool validCheck(string input)
{
/**
* @brief This function tests if the input is valid
* 
* @param "input" is an initialized string variable
* @return bool
*/
        if (input.length() != 5)
            {
                return false;
            }
        else if (input[2] != ':')
            {
                return false;
            }
        else if (input[0]<48 || input[0]>50)
            {
                return false;
            }
        else if (input[1]<48 || input[1]>57)
            {
                return false;
            }
        else if (input[3]<48 || input[3]>53)
            {
                return false;
            }
        else if (input[4]<48 || input[4]>57)
            {
                return false;
            }
        else 
            {
                return true;
            }
}

void converter(string input)
{
/**
* @brief This function calculates the final time to output
* 
* @param "input" is an initialized string variable
* @return void
*/

    if (input[0] >= 49 && input[1] > 50)
    {
        
    string f = "0000";
    int z = 0;
    int y = 0;
    f[0] = input[0];
    f[1] = input[1];
    f[2] = input[3];
    f[3] = input[4];

    string stringToInteger(f);
	stringstream str(stringToInteger);
	int x;
	str >> x;
    y = x/100;
    y = y-12;
    z = x%100;
    
        cout << "That is the same as " << y << ":" << z << "PM" << endl;
    }
    else if(input[0] == 48 && input[1] == 48)
    {
        cout << "That is the same time as " << "12" << input[2] << input[3] << input[4] << "AM" << endl;
    }
    else if(input[0] == 48 && input[1] !=0)
    {
        cout << "That is the same time as " <<input[1] << input[2] << input[3] << input[4] << "AM" << endl;
    }
    else if( input[0] == 49 && input[1]!=50)
    {
        cout << "That is the same as " << input << "AM" << endl;
    }
    else 
    {
        cout << "That is the same as " << input << "PM" << endl;
    }
}