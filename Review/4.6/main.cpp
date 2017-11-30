/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on September 14, 2017, 12:52 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//constants
float const G= 9.8; //speed of gravity

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    float mass; //mass of the object
    float newt; //the newtons of the object
    int   max = 1000; //max newtons allowed
    short min = 10;  //least newtons allowed
    
    //prompt for the mass
    cout << "What is the mass of the object?\n";
    cin  >> mass;
    
    //calculate the weight
    newt = mass * G;
    
    
    //input validate
    while (newt < min || newt > max)
    {
        if(newt < min){
            cout << "The object is too light.\n";
            cout << "What is the mass of the object?\n";
            cin  >> mass;
        }
        
        if (newt > max)
        {
        cout << "The object is too heavy.\n";
        cout << "What is the mass of the object?\n";
        cin  >> mass;
        
        
        }
        
        //calculate weight
        newt = mass * G;
        
    }   

    //output the newtons
    cout << left << setw(31)<< "The newtons for that object is" << newt;
    return 0;
}

