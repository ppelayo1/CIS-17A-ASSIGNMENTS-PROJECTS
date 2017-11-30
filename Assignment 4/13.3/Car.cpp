




//class implementation file for Car

#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(int yrMdl,string mke)
{
    //set speed to zero
    this->spd = 0;
    this->mke = mke;
    this->spdC = 5; //The accel and deceleration value
    
    //input validate year model then assign
    while (yrMdl < 1900 || yrMdl > 2017)
    {
        cout << "The car must have a year model after 1900 and before 2018.\n";
        cout << "Enter a new value.\n";
        cin >> yrMdl;
    }
    this->yrMdl = yrMdl;
    
    
}
        
//accessors
int Car::getYrMdl()
{
    return yrMdl;
}
string Car::getMke()
{
    return mke;
}
int Car::getSpd()
{
    return spd;
}

//other functions
void Car::acc()
{
    spd += 5;
}
void Car::dec()
{
    spd -= 5;
    
    //set speed to zero if it becomes negative
    if(spd < 0)
    {
        spd = 0;
    }
    
}