/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 26, 2017, 9:12 PM
 */

#include <iostream>

using namespace std;

template <class T>
T total(int n)
{
    T sum = 0;
    T temp = 0;
    
    for (int i =0; i < n; i++)
    {
        cout << "Please enter value " << i + 1 << endl;
        cin >> temp;
        sum += temp;
        
        cin.ignore(1000,'\n');
        
    }
    
    return sum;
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int n; //number of values to sum
    
    cout << "Please enter the number of numbers to sum for a int.";
    cin >> n;
    
    cout << "\nThe total is " << total<int>(n) << endl;
    
    cout << "Please enter the number of numbers to sum for a float.";
    cin >> n;
    
    cout << "\nThe total is " << total<float>(n) << endl;
    
    return 0;
}

