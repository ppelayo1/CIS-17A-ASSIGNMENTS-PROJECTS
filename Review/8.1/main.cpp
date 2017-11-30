/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 16, 2017, 11:34 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
bool linearSearch(int array[], int size,int value);

/*
 * 
 */
int main(int argc, char** argv) {
    
    //variables
    int num;       //number by the user
    int size = 18; //size of the array    
    int array[size] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,  
                       8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                       1005231, 6545231, 3852085, 7576651, 7881200, 4581002}; //the numbers to check
    
    //prompt for the number
    cout << "What number would you like to serach for?\n";
    cin >> num;
    
    //search the array and return response
    if (linearSearch(array,size,num) == true)
    {
        cout << "The number" << setw(8) << num << setw(14) << "is present.\n.";
    }else    
    {
        cout << "The number" << setw(8) << num << setw(18) << "is not present.\n.";
    }

    return 0;
}

bool linearSearch(int array[], int size,int value)
{
    bool flag=false;
    
    //search array
    for(int i = 0; (i < size) && (flag==false); i++)
    {
        if(array[i] == value)
        {
            flag=true;
        }
    }
    
    return flag;
}
