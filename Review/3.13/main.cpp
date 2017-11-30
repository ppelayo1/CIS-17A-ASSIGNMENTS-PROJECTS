/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on September 14, 2017, 11:23 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    float totalAge;
    
    //prompt for the age
    cout << left << setw(24) << "What is your total age?";
    cin >> totalAge;
    
    cout << setw(17)<< "The total age is" << setw(12) << fixed << setprecision(4) << totalAge;

    return 0;
}

