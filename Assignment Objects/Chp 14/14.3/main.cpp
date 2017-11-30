/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 14, 2017, 2:02 PM
 */

#include "preProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//variables
    int n;
    string s;
    cout << "Enter the day number.\n";
    cin >> n;
        
    
    DayOfYear one(n);
    
    
    one.toString();
   
    cout << "\n\nDemonstrating++\n";
    
    one++;
    one.toString();
    
    cout << "\n\nDemonstrating--\n";
    
    one--;
    one.toString();
            
    cout << "Now demonstrating the second constructor.\n";
    
    cout << "Enter the day number.\n";
    cin >> n;
    cin.ignore(1000,'\n');
    
    cout << "Enter the month.\n";
    cin >> s;
    
    DayOfYear two(n,s);
    
    two.toString();
    
    return 0;
}

