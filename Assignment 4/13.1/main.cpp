/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 17, 2017, 2:12 PM
 */

#include "Date.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int day;
    int month;
    int year;
    
    //prompt    
    cout << "Enter the day as an integer.\n";
    cin >> day;
    
    cout << "Enter the month as an integer.\n";
    cin >> month;
    
    cout << "Enter the year.\n";
    cin >> year;
    
    //create the class
    Date date(day,month,year);
    
    //print out the data
    date.print();
    

    return 0;
}

