/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 24, 2017, 8:27 PM
 */

#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>

//function prototypes
int *swapA(int **ptr, int size); //array swaps the values in the elements

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int size; //size of array
    int *ptr =0; //points to the array with values swapped
    int sum = 0; //sum for formating
    
    //seed rand
    srand(time(0));
        
    size = rand() % 500;
    
    //dynamically create the array
    int *array = new int[size];
    
    cout << "The values in the array are\n\n";
    
    //populate the array
    for (int i =0; i < size; i++,sum++)
    {
        array[i] = rand() % 100 + 1; 
        
        if (sum == 5)
        {
            cout << endl << setw(5)<< array[i];
            sum =0;
        }else
            cout<< left << setw(5)<< array[i];
    }
    
    //get the swapped array
    ptr = swapA(&array, size);
    
    cout << endl << endl;
    cout << "The values swapped in the new array are.\n\n";
    
    
    
     //Display the new array
    for (int i =0; i < size; i++,sum++)    {
        
        
        if (sum == 5)
        {
            cout << endl << setw(5)<< ptr[i];
            sum =0;
        }else
            cout<< left << setw(5)<< ptr[i];
    }
    
    //free mem
    delete [] ptr;
    delete [] array;
    
    cout <<endl << endl<< ptr;
    cout <<endl << endl << array;
    
    ptr = 0;
    array = 0;
    
    return 0;
}

//this function accepts an array and swaps the values
int *swapA(int **ptr, int size)
{
    //variables
    int *swpA =0;
    swpA = new int[size]; //Array to contain swapped elements
    
    int j=size - 1;            //element to swap from top down    
    
    for (int i =0; i < size; i++,j--)
    {
        swpA[j] = *(*ptr+i);
    }
    
    return swpA;
}
