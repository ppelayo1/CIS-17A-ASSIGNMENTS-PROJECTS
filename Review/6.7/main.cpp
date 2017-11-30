/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 16, 2017, 9:30 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
/*
 * 
 */
//function prototypes
float celcCon(float ferh);

int main(int argc, char** argv) {
    //variables
    
    
    
    //loop and call the function displaying the table of values
    for (int i = 0; i<=20;i++ )
    {
        cout << left << setw(22) <<"The Fahrenheit value" << setw(6)<< i << setw(4) << "is"<< setw(10) << celcCon(static_cast<float>(i)) << "in Celsius.\n";
    }
    return 0;
}

//purpose of this function is to accept a ferhenheight value and convert it to celsious.
float celcCon(float ferh)
{
    ferh = (5.0/9.0)*static_cast<float>(ferh-30);    
    return ferh;
}

