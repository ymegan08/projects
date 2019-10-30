//
//  bill.cpp
//
//  Created by Megan Cho on 4/16/19.
//  Copyright © 2019 Yuna Cho. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    cout << "Initial meter reading: "; //Allows for initial meter reading input
    int intMeterReading;
    cin >> intMeterReading; //Initializes variable
    cin. ignore(10000, '\n'); //Throws away remaining characters including new line
    if (intMeterReading < 0) //If statement for if the initial meter reading is a negative number
    {
        cout << "---" << '\n' << "The initial meter reading must be nonnegative." << endl;
        return (1); //'\n' ensures a new line for the sentence following the three hyphens
    }
    
    cout << "Final meter reading: "; //Allows for final meter reading input
    int finalMeterReading;
    cin >> finalMeterReading; //Initializes variable
    cin. ignore(10000, '\n'); //Throws away remaining characters including new line
    if (finalMeterReading < intMeterReading) //If statement for if final meter reading is less than the initial meter reading
    {
        cout << "---" << '\n' << "The final meter reading must be at least as large as the initial reading." << endl;
        return (1); //Return statement to end the program after error message output
    }
    
    cout << "Customer name: "; //Allows for customer name input
    string customer;
    getline(cin, customer); //Reads input and stores characters into string
    if(customer == "") //If statement for if there is an empty string
    {
        cout << "---" << '\n' << "You must enter a customer name." << endl;
        return (1);
    }
    
    cout << "Month number (1=Jan, 2=Feb, etc.): "; //Allows for month input
    double month;
    cin >> month; //Input taken as double form and stored into month value
    if (month < 1 || month > 12) //If statement for if input is not between 1 and 12 inclusive
    {
        cout << "---" << '\n' << "The month number must be in the range 1 through 12." << endl;
        return (1);
    }
    
    double HCF = finalMeterReading - intMeterReading; //HCF defined as an equation
    if (month >= 4 && month <= 10) //If statement for high usage season (April ~ October)
    {
        if (HCF <= 43) //During high usage season, first tier rate
        {
            double amount = (HCF * 2.71);
            cout.setf(ios::fixed); //Ensures fixed-point notation
            cout.precision(2); //Two digits right of the decimal point
            cout << "---" << '\n' << "The bill for " << customer << " is $" << amount << endl;
            return (1);
        }
        else //During high usage season, second tier rate added to first tier rate
        {
            double amount = ((HCF-43)*(3.39)+116.53);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "---" << '\n' << "The bill for " << customer << " is $" << amount << endl;
            return (1);
        }
    }
    if ((month == 11 || month == 12) || (month >= 1 && month <=3)) //If statement for low usage season (November ~ March)
    {
        if (HCF <= 29) //During low usage season, first tier rate
        {
            double amount = (HCF * 2.71);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "---" << '\n' << "The bill for " << customer << " is $" << amount << endl;
            return (1);
        }
        else //During low usage season, second tier rate added to first tier rate
        {
            double amount = ((HCF-29)*(2.87)+78.59);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "---" << '\n' << "The bill for " << customer << " is $" << amount << endl;
            return (1);
        }
    }
}
