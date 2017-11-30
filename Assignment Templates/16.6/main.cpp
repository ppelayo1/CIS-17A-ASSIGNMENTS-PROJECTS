/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 26, 2017, 9:35 PM
 */

#include <iostream>
#include "intArray.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int size;
    
    //prompt for the size of the object to build
    cout << "How large do you want the array to be?\n";
    cin >> size;
    cin.ignore(1000,'\n');
    
    
    IntArray obj(size);
    
    try
    {
        for(int i = 0; i <= obj.size();i++)
        {
            obj[i] = i;
            cout << "The value in sub i is " << i << endl;

            if(i == obj.size() - 1)
            {
                cout << "The exemption is about to be thrown, press enter.\n";
                cin.get();
            }
        }
    }
    
    catch(IntArray::outOfRange)
    {
        cout << "The array is now out of range.";
        return -1;
    }
    
    return 0;
}

