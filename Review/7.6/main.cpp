/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 16, 2017, 9:49 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//function prototypes
void sort(int *array, int size);//determines number of lines in the file
int avg(int *array, int size);  //determines the avg of the numbers in the file
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int dummy;     //dummy variable to hold data for counting
    int size= 0;   //size of array
    ifstream file; //file stream object
    file.open("numbers.txt");

    //determine length of the file
    while(file >> dummy)
        size++;
        
    //close out and reopen to read again from begining
    file.close();
    
    //dynamically create an array
    int *ptr = 0;
    ptr = new int[size];
    
    //reopen and begin grabbing contents
    
    file.open("numbers.txt");
    //grab contents
    for(int i =0; i < size; i++)
    {
        file >> ptr[i];        
    }
    
    //close the file stream
    file.close();
    
    //sort the array
    sort(ptr,size);
    
    //output the desired info
    cout << "The highest number in the file are"<< setw(18) << ptr[size-1] << endl;
    cout << "The smallest number in the file are"<<setw(17) << ptr[0] << endl;
    cout << "The total numbers in the file are" << setw(19) << size << endl;
    cout << "The average of the numbers in the file are" << setw(10) << avg(ptr,size) << endl;
    
    //free memory
    delete []ptr;
    ptr = 0;
    
    
    
    return 0;
}

// this function will sort the array and then return it
void sort(int *array, int size)
{
    int temp; //temporary holder
    
    //sort
    for(int i= 0; i< size; i++)
    {
        for(int j = i; j< size; j++)
        {
            if(array[i] > array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[i];
                array[i] = temp;
            }
        }
    }      
}

//calculates and returns the avg of the numbers in the file
int avg(int *array, int size)
{
    int sum = 0;//sum of the numbers
    for (int i = 0; i < size; i++)
    {
        sum+= array[i];
    }
    
    return sum/size;
}


