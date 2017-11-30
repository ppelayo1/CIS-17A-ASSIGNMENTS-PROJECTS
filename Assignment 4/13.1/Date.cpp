/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



//libraries
#include "Date.h"
#include <iostream>
using namespace std;


//specification file for Date.h

//constructor
Date::Date(int day,int month ,int year )
{  
    //input validate then assign the values
    while (day > 31 || day < 1)
    {
        cout << "The day is out of range and must be from 1-31";
        cout << "\nPlease enter a new day.\n";
        cin >> day;        
       
    }
    while (month > 12 || month < 1)
    {
        cout << "The month is out of range and must be from 1-12";
        cout << "\nPlease enter a new month.\n";
        cin >> month;       
    }       
    //assign values
    this->day = day;
    this->month = month;
    this->year = year;    
}

//prints out the date data as specified
void Date::print()
{
    int type;
    
    cout << "Enter 1 to print out date in format xx/xx/xxxx.\n";
    cout << "Enter 2 to print out date in format December xx, xxxx\n";
    cout << "Enter 3 to print out date in format xx December xxxx\n";
    
    cin >> type;
    
    while (type < 1 || type > 3)
    {
        cout << "That is not a valid selection.\n";
        
        cout << "Enter 1 to print out date in format xx/xx/xxxx.\n";
        cout << "Enter 2 to print out date in format December xx, xxxx\n";
        cout << "Enter 3 to print out date in format xx December xxxx\n";
        
        cin >> type;
    }
    
    //prints out the first type of output
    if(type == 1)
    {
        cout << month << "/" << day << "/" << year;
    }
    
    //prints out the second type of output multiple ifs for each month
    if(type == 2)
    {
        if(month == 1)
        {
            cout << "Janurary " << day << ", " << year;
        }
        if(month == 2)
        {
            cout << "February " << day << ", " << year;
        }
        if(month == 3)
        {
            cout << "March " << day << ", " << year;
        }
        if(month == 4)
        {
            cout << "April " << day << ", " << year;
        }
        
        if(month == 5)
        {
            cout << "May " << day << ", " << year;
        }
        if(month == 6)
        {
            cout << "June " << day << ", " << year;
        }
        if(month == 7)
        {
            cout << "July " << day << ", " << year;
        }
        if(month == 8)
        {
            cout << "August " << day << ", " << year;
        }
        if(month == 9)
        {
            cout << "September " << day << ", " << year;
        }
        if(month == 10)
        {
            cout << "October " << day << ", " << year;
        }
        if(month == 11)
        {
            cout << "November " << day << ", " << year;
        }
        if(month == 12)
        {
            cout << "December " << day << ", " << year;
        }
    }
    
    //print out for the last format type
    if(type == 3)
    {
        if(month == 1)
        {
            cout << day << " Janurary " << year;
        }
        if(month == 2)
        {
            cout << day << " February " << year;
        }
        if(month == 3)
        {
            cout << day << " March " << year;
        }
        if(month == 4)
        {
           cout << day << " April " << year;
        }
        if(month == 5)
        {
            cout << day << " May " << year;
        }
        if(month == 6)
        {
            cout << day << " June " << year;
        }
        if(month == 7)
        {
           cout << day << " July " << year;
        }
        if(month == 8)
        {
            cout << day << " Ausust " << year;
        }
        if(month == 9)
        {
            cout << day << " September " << year;
        }
        if(month == 10)
        {
            cout << day << " October " << year;
        }
        if(month == 11)
        {
            cout << day << " November " << year;
        }
        if(month == 12)
        {
            cout << day << " December " << year;
        }
        
        
    }
}
