/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 16, 2017, 10:45 PM
 */

#include <iostream>
#include <string>

using namespace std;

//function prototypes
int binarySearch( string array[], int numElems, string value);
/*
 * 
 */
int main(int argc, char** argv) {
    
    const int NUM_NAMES = 20;
    int value; //the element if found or -1 if not found
    string search; //string being searched
    
     string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };

    
    
     
   //sort the strings
   for(int i= 0; i< NUM_NAMES; i++)
   {
        for(int j = i; j< NUM_NAMES; j++)
        {
            if(names[i] > names[j+1])
            {
                string temp = names[j+1];
                names[j+1] = names[i];
                names[i] = temp;
            }
        }
    }      
     
     //prompt for a name
     cout << "What name would you like to search for?\n";
     getline(cin, search);
     
    //search for a name
    value = binarySearch(names,NUM_NAMES,search);
    
    //output the element
    cout << value;
    
  
    
    return 0;
}


int binarySearch( string *array, int numElems, string value)
{
    int first = 0, // First array element
        last = numElems - 1, // Last array element
        middle, // Midpoint of search
        position = -1; // Position of search value
    bool found = false; // Flag
    
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (array[middle] == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
            else if (array[middle] > value) // If value is in lower half
                last = middle - 1;
            else
                first = middle + 1; // If value is in upper half
        }
    return position;
}