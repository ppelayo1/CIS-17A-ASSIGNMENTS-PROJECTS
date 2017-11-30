/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 14, 2017, 7:01 PM
 */

#include "numDays.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int hours;
    float days;
    
    cout << "Enter the hours you want to calculate.\n";
    cin >> hours;
    
    NumDays objOne(hours);
    
    //test the object
    cout <<"Testing the getters then the setters then getters again.\n\n";
    
    cout << "Hours = " << objOne.geHours() << endl;
    cout << "Days = " << objOne.getDays() << endl;
    
    cout << endl << endl << "Testing the setters and getters after.\n";
    cout << "Enter the hours.\n";
    cin >> hours;
    objOne.setHours(hours);
    cout << "Hours = " << objOne.geHours() << endl;
    cout << "Days = " << objOne.getDays() << endl << endl;
    
    cout <<"Enter the days.\n";
    cin >> days;
    objOne.setDays(days);
    cout << "Hours = " << objOne.geHours() << endl;
    cout << "Days = " << objOne.getDays() << endl << endl;
    
    cout << endl << endl << "Testing the overloaded functions.\n";
    
    cout << "Enter the hours for object one\n";
    cin >> hours;
    NumDays objTwo(hours);
    
    cout << "Enter the hours for Object two.\n";
    cin >> hours;
    NumDays objThree(hours);
    
    cout << endl << endl << "The hours of those two objects added together is " << objTwo + objThree << endl;
    cout << "The hours of those two objects minused from each other is " << objTwo - objThree << endl;
    
    cout << "Object one hour value is " << objTwo.geHours() << "The prefix ++ value is " << ++objTwo << endl;
    cout << "Object one hour value is " << objTwo.geHours() << "The prefix -- value is " << --objTwo << endl;
    
    cout << "Object one hour value is " << objTwo.geHours() << "The postfix ++ value is " << objTwo++<< endl;
    cout << "Object one hour value is " << objTwo.geHours() << "The postfix -- value is " << objTwo--<< endl;

    return 0;
}

