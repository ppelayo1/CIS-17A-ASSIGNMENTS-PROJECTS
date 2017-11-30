/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 26, 2017, 7:30 PM
 */


#include <iostream>
using namespace std;



//two functions, max and min, return the max of two arg, or min of two args.





/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int one = 5;
    int two = 3;
    float three = 9;
    float four = 4;
    char five = 'a';
    char six = 'b';
    
    cout << "The values being testing in both max and min are.\n";
    cout << one << " ";
    cout << two << endl;
    cout << three << " ";
    cout << four << endl;
    cout << six << " ";
    cout << five << endl;
    
    
    cout << "MAX TESTS\n";
    cout << max(one,two) << endl;
    cout << max(three,four) << endl;
    cout << max(five,six) << endl;
   
    cout << "\n\nMIN TESTS\n";
    cout << min(one,two) << endl;
    cout << min(three,four) << endl;
    cout << min(five,six) << endl;

    
    
    

    
    return 0;
}

template <class T>
T max(T one, T two)
{
    if(one > two)
        return one;
    else
        return two;
}

template <class T>
T min(T one, T two)
{
    if(one < two)
        return one;
    else
        return two;
}