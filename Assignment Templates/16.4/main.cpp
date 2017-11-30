/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 26, 2017, 8:57 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


//return the absolute value of any number
template <class T>
T absV(T abs)
{
    if(abs < 0)
        return abs * -1;
    
    return abs;
    
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    //test various values and data types
    int one = -5;
    short two = -1;
    float three = -2;
    double four = -6;
    long five = 0;
    
    cout << "Values being abs determined.\n";
    cout << one << endl;
    cout << two << endl;
    cout << three << endl;
    cout << four << endl;
    cout << five << endl;
    
    cout << "\n the abs value is \n\n";
    cout << absV(one) << endl;
    cout << absV(two) << endl;
    cout << absV(three) << endl;
    cout << absV(four) << endl;
    cout << absV(five) << endl;
    
    
    
    return 0;
}

//return the absolute value of any number
