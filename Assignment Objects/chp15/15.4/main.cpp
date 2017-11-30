/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 16, 2017, 11:42 AM
 */

#include "preProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int milH;
    int milS;
    
    cout << "Please enter the military hour.\n";
    cin >> milH;
    
    cout << "Please enter the military seconds.\n";
    cin >> milS;
    
    //create the object
    MilTime objOne(milH,milS);
    
    cout << "The time in military time is " << objOne.getHour() << ":" << objOne.getSec() << endl;
    cout << "The standard time is " << objOne.getStndHour() << ":" << objOne.getMin() << ":" << objOne.getSec() << endl;

    return 0;
}

