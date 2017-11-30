/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 24, 2017, 5:36 PM
 */

#include <iostream>
#include <iomanip>

//function prototypes
void  crtArry(short **ptr,int size); //Creates the student score array
void  dstry(short **ptr); //frees memory
void  sort(short **ptr, int size); //sorts the array
short avg(short **ptr, int size);  //calculate the average score and return it
void getScrs(short **ptr, int size); //get the user scores
void outpt(short **ptr, int size, short avg); //output formated info
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int size; //size of array
    short *score = 0; //ptr to the scores dynamically created
    int avgScr; //Avg score
    //prompt for number of tests
    cout << "How many tests would you like to enter?\n";
    cin >> size;
    
    //input validation
    while (size < 1)
    {
        cout << "The number of scores to be entered must be 1 or more.\n\n";
        
        cout << "How many tests would you like to enter?\n";
        cin >> size;
    }
    
    //create the array
     crtArry(&score,size);
    
    
    
    //get the scores
    getScrs(&score,size);   
    
    //sort the scores
    sort(&score, size);
    
    //caclulate the avg score
    avgScr = avg(&score,size);
    
    //output the info
    outpt(&score,size,avgScr);
            
    //free the memory
    dstry(&score);      
    
    
    return 0;
}

//creates the array dynamically
void  crtArry(short **ptr, int size)
{    
    //create the array
    *ptr = new short[size];        
    
}

//clean up the memory
void  dstry(short **ptr)
{
    delete [] *ptr;
    *ptr = 0;   
}

//user inputs the scores thru this function
void getScrs(short **ptr, int size)
{
    //get the scores
    for(int i = 0; i < size; i++)
    {
        cout << "Please enter the score for the test.\n";
        cin >> *(*ptr+i);
        
        //input validate
        while(*(*ptr+i) < 0 || *(*ptr+i) > 100)
        {
            cout << "The a test score must be between 0 and 100.\n\n";
            
            cout << "Please enter the score for the student.\n";
            cin >> *(*ptr+i);
            
        }        
        
    }
}

//sort the array from smallest to largest
void  sort(short **ptr, int size)
{
    //variables
    short temp; //for the swap
    
    for(int i = 0; i < size; i++)
    {
        for (int j=i; j < size; j++)
        if (*(*ptr+i) > *(*ptr+j))
        {
            temp = *(*ptr+j);
            *(*ptr+j) = *(*ptr + i);
            *(*ptr+i) = temp;            
        }
        
    }    
}

//calculates and returns the average score
short avg(short **ptr, int size) 
{
    //variables
    int sum = 0;
    
    for (int i =0; i< size; i++)
    {
        sum += *(*ptr+i);
    }
    
    //return avg
    return sum/size;
    
}

//outputs the info formated
void outpt(short **ptr, int size, short avg)
{
 cout << "|test|"  << "|Grade|\n";   
 
 for (int i =0; i < size; i++)
 {
     cout <<"|" << setw(4) << i+1<< "||" << setw(5) << *(*ptr+i) << "|\n";
 }
 
 //output avg
 cout <<"|-----------|\n";
 cout <<"|Average:" << setw(3) << avg << "|";
}