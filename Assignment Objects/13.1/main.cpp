/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 9, 2017, 11:19 AM
 */



#include <iostream>
#include "date.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    int d;
    int m;
    int y;
    
    cout << "Enter the day\n";
    cin >> d;
    
    cout << "Enter the month\n";
    cin >> m;
    
    cout << "Enter the year\n";
    cin >> y;
    
    //build the class
    Date date(d,m,y);
    
    //test the output functions
    
    date.print1();
    cout << endl;
    
    date.print2();
    cout << endl;
    
    date.print3();
    cout << endl;
    
    
    return 0;
}

