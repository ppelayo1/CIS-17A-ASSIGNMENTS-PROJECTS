/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 27, 2017, 6:08 PM
 */

#include <iostream>
#include "testScores.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //variables
    int size;
    float *value;
    
    cout << "Please enter the number of scores to enter and sum.\n";
    cin >> size;
    
    value = new float[size];
    
    for(int i =0; i < size; i++)
    {
        cout << "Please enter the score for number " << i+1 << endl;
        cin >> value[i];
        cout << endl;
    }
    
    TestScores <float> test(value,size);
    
    try{
        cout << "The average of those scores is " << test.mean();
    }
    catch(TestScores<float>::scrOutR)
    {
        cout << "A score was greater than 100, or negative, program terminated.\n";
        return -1;
    }
    
    
    delete value;
    
    return 0;
}

