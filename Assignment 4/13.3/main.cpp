/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 19, 2017, 9:00 PM
 */

#include "Car.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int yrMdl; //year model of the car
    string mke; //make of the car
    
    //prompt for the values
    cout << "What is the make of the car?.\n";
    getline(cin,mke);
    
    cout << endl << "What is the year model of the car?\n";
    cin >> yrMdl;
    
    //create the object
    Car object(yrMdl,mke);
    
    //call the acc function 5 times and get speed each time
    object.acc();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.acc();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.acc();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.acc();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.acc();
    cout << "Speed now is " << object.getSpd() << endl;
    
    //now call the dec function 5 times and get speed each time
    object.dec();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.dec();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.dec();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.dec();
    cout << "Speed now is " << object.getSpd() << endl;
    
    object.dec();
    cout << "Speed now is " << object.getSpd() << endl;

    return 0;
}

