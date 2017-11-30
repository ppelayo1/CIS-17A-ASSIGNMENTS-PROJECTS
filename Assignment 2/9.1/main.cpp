/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 24, 2017, 7:26 PM
 */

#include <iostream>

//function prototypes
int *crtAry(int size); //dynamically created array
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int *arry = 0;
    int size;  
    
    //prompt for number of elements
    cout << "How many elements do you want the array to have?\n";
    cin  >> size;
    
    arry = crtAry(size);
    
    cout << "Mem address assigned to arry is" << arry << endl;
    
    //free mem
    delete [] arry;
    arry =0;
    
    cout << "address after cleanup" << arry;
    return 0;
}

//returns pointer to the dynamic array
int *crtAry(int size)
{
    int *ptr= new int[size];
    
    cout << "Array mem address after creation is" << ptr << endl;
    return ptr;
}