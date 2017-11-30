#include "date.h"
#include <iostream>

using namespace std;



//private functions
string Date::mString()
{
    
    
    string sMonth; //the month value to be returned as a string
    
    if(month == 1)
    {
        sMonth = "Janurary";
    }
    
    if(month == 2)
    {
        sMonth = "February";
    }
    
    if(month == 3)
    {
        sMonth = "March";
    }
    
    if(month == 4)
    {
        sMonth = "April";
    }
    
    if(month == 5)
    {
        sMonth = "May";
    }
    
    if(month == 6)
    {
        sMonth = "June";
    }
    
    if(month == 7)
    {
        sMonth = "July";
    }
    
    if(month == 8)
    {
        sMonth = "August";
    }
    
    if(month == 9)
    {
        sMonth = "September";
    }
    
    if(month == 10)
    {
        sMonth = "October";
    }
    
    if(month == 11)
    {
        sMonth = "November";
    }
    
    if(month == 12)
    {
        sMonth = "December";
    }
    
    return sMonth;
    
}


//public functions
Date::Date(int d,int m,int y)
{
    
    
    
    
    year = y;
    
    while(d < 1 || d > 31)
    {
        cout << "The day must be between 1 and 31.\n";
        cin >> d;
               
    }
    day = d;
    
    while(m < 1 || m > 12)
    {
        cout << "The month must be between 1 and 12.\n";
        cin >> m;
               
    }
    month = m;
    
    
}





void Date::print1()  //  12/25/2012
{
    cout <<    day << "/" << month << "/" << year;
}


void Date::print2()  //December 25, 2012
{
    cout << mString() <<" " << day <<", " << year;
       
    
}
 



void Date::print3()  //25 December 2012
{
    
    cout << day << " " << mString() << " " << year;
    
    
    
}

void Date::setDay(int d )
{
    if(d < 1 || d > 31)
        throw InvalidDay();
    
    day = d;
    
    
}

void Date::setMnth(int m)
{
    if(m < 1 || m > 12)
        throw InvalidMonth();
    
    month = m;
    
    
    
}
void Date::setYr(int y)
{
    
    
    year = y;
    
}
