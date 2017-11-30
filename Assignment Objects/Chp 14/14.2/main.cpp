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
    
    cout << "Enter the day number.\n";
    cin >> n;
    
    DayOfYear one(n);
    
    one.toString();
    
    return 0;
}

