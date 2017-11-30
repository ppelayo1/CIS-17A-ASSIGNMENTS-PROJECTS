/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 27, 2017, 7:27 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    vector<float> vect;
    const int SIZE = 12;
    float value;
    int high; //highest element
    int low;  //lowest element
    
    
    
    //get the rainfalls
    for(int i = 0; i < SIZE; i++)
    {
        
        cout << "Enter the rainfall for month " << i+1 << endl;
        cin >> value;
        
        while(value < 0)
        {
            cout << "The value must be positive.\n";
            cin >> value;
        }
        vect.push_back(value);
        
        //determines which element is highes or lowests
        if(i == 0)
        {
            high = vect[i];
            low = vect[i];
        }
        else
        {
            if(high < vect[i])
                high = i;
            if(low > vect[i])
                low = i;
        }
        
        
    }    
    
        
    
    cout << "The average rainfall for year was " << accumulate(vect.begin(),vect.end(),0)/SIZE << endl;;
    cout << "The total rainfall for year was " << accumulate(vect.begin(),vect.end(),0) << endl;
    cout << "The month with the highest rainfall was " << high + 1 << " with rainfall of " << *max_element(vect.begin(),vect.end()) << endl;
    cout << "The month with the lowest rainfall was " << low + 1 << " with rainfall of " << *min_element(vect.begin(),vect.end());
    
    return 0;
}

