/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 27, 2017, 6:40 PM
 */

#include <iostream>
#include "simpleVector.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 30;
    int value; //holds a value for the class object array

    
    
    
    SimpleVector<int> obj(SIZE);
    
    //test the push and pop functions
    for(int i = 0; i < obj.size();i++)
    {
        obj[i] = i;
    }
    
    //push values on
    for(int i = 50; i <= 60; i++)
    {
        obj.push_back(i);
    }
    
    
    //pop values off
    while(obj.size() >= 1)
    {
        cout << "Value is " << obj.pop_back() << endl;
    }
    return 0;
}

