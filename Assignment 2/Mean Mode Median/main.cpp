/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 18, 2017, 12:47 PM
 */

#include <iostream>
#include <ctime>
#include <iomanip>

#include "structure for array with size.h"
using namespace std;


//function prototypes
void fillA(unsigned int **ptr, int size, unsigned int upL, unsigned int loL ); //This function builds and populates an array
void getInfo(int *size, unsigned int *upL, unsigned int *loL);       //gets the necessary info from the user for array
void dest(unsigned int **ptr); //destroy array free mem
void dest(unsigned int **ptr, ModeAry *Strt); //destroy array free mem overloaded frees struct too
void sort(unsigned int **ptr, int size); //sort the array
unsigned int mean(unsigned int **array, int size); //this function will perform the mean calculation and return an array
unsigned int median(unsigned int **array, int size); //calculates the median value and then returns it
ModeAry mode(unsigned int **array, int size);  //calculates the mode and then returns an array containing the number of modes, mode frequencey, and the modes

/*
 * 
 */
int main(int argc, char** argv) {
    //seed the random number generator
    srand(time(0));
    
    
    //variables
    int size; //size of the array
    unsigned int *ptr = 0;   //a ptr to the dynamic array
    ModeAry PtMd;
    unsigned int upL; //upper limit of the random number
    unsigned int loL; //lower limit of the random number
    unsigned int avg;//the mean average    
    
    //get the info needed for the array
    getInfo(&size,&upL,&loL);
    
    //build the array
    fillA(&ptr,size,upL,loL);        
    
    //sort the array
    sort(&ptr,size);   
    
    //display the values in the sorted array
    cout << "The values in the array are as follows.\n";
    
    for (int i = 0; i < size; i++)
    {
       
        cout << "Element:" << left << setw(20) << i   << ptr[i] << endl;        
        
    }
    
    //calculate and then output the mean average
    avg = mean(&ptr,size);
    
    cout << "The average mean of the array is " << avg << ".\n\n";
    
    //calculate the median average ,then output
    avg = median(&ptr, size);
   
    cout << "The average median of the array is " << avg << ".\n\n";    
    
    
    //calculate and return the structure containing the mode array
    PtMd = mode( &ptr, size);
    
    
    //output mode values  if exist
    if (PtMd.modeExist == true)
    {
        cout << "The number of modes in the array are.\n" << *(PtMd.ptr) << endl;    
        cout << " mode values are.\n";
        for(int i = 2; i < PtMd.size; i++)
        {
            cout << *(PtMd.ptr + i) << endl;
        }
    }else
    {
        cout << "No mode existed for that group of numbers.\n";
    }
    //destroy the array, free mem   
    if(PtMd.modeExist == true)
        dest(&ptr,&PtMd);
    else
        dest(&ptr);
    
    return 0;
}

 void fillA(unsigned int **ptr, int size, unsigned int upL, unsigned int loL )
{
    //build the array  !!!!!MUST DESTROY!!!!!!!!!!
    *ptr = new unsigned int[size];
    
    //populate the array
    for (int i = 0; i < size; i++)
    {
        if (loL > 0)
            (*ptr)[i] = rand() % upL + loL;
        else
            (*ptr)[i] = rand() % (upL + 1); 
        
        
    }
    
}

void getInfo(int *size, unsigned int *upL, unsigned int *loL)
{
     //prompt the user for the desired size
    cout << "What size of array would you like to use?\n";
    cout << "Size only allowed 1 to 1000.\n";
    cin >> *size;
    
    //input validate
    while(*size < 1 || *size > 1000)
    {
        cout << "Invalid size\n\n";
        cout << "What size of array would you like to use?\n";
        cout << "Size only allowed 1 to 1000.\n";
        cin >> *size;
    }
    
    //prompt the user for the desired lower limit
    cout << "What is the smallest number you want in an array element.\n";
    cout << "Size only allowed 0 to 3999999999.\n";
    cin >> *loL;
    
    //input validate
    while(*loL < 0 || *loL > 3999999999 )
    {
        cout << "The lower limit is out of range.\n\n";
        cout << "What is the smallest number you want in an array element.\n";
        cout << "Lower limit only allowed 0 to 3999999999.\n";
        cin >> *loL;
    }
    
    //prompt the user for the desired upper limit
    cout << "What is the largest number you would like to use in an array element\n";
    cout << "Upper limited only allowed 1 to 4000000000.\n";
    cout << "Upper limit must be > then the lower limit.";
    cin >> *upL;
    
    //input validate
    while (((*upL < 1 || *upL > 4000000000) || *upL < *loL))
    {
        cout << "The upper limit is not acceptable.\n\n";                
        cout << "What is the largest number you would like to use in an array element\n";
        cout << "Upper limited only allowed 0 to 4000000000.\n";
        cout << "Upper limit must be > then the lower limit except when zero.";
        cin >> *upL;
    }
    
}

//delete array free mem
void dest(unsigned int **ptr){
    delete [] *ptr;
    *ptr = 0;
}

//overloaded free struct memory
void dest(unsigned int **ptr, ModeAry *Strt)
{
    delete [] *ptr;
    *ptr = 0;
    
    delete [] Strt->ptr;
    Strt->ptr = 0;
}

//sorts the array in prep for the averaging
void sort(unsigned int **ptr, int size)
{
    //temp variable
    unsigned int temp;
    
    //sort the array
    for(int i=0;i<size;i++)
    {
        for (int j = i; j < size; j++)
        {
        if ((*ptr)[i] > ((*ptr)[j+1]))
        {
        
            temp = (*ptr)[i];
            (*ptr)[i] = (*ptr)[j+1];
            (*ptr)[j+1] = temp;
        }
        }
    }
}

//calculates the mean and returns a ptr to an array]
unsigned int mean(unsigned int **array, int size)
{
    //variables     
    unsigned int avgMean;      //the average mean
    long long ttl = 0;      //sum of the numbers
    
    //calculate the mean
    for (int i = 0; i < size; i++)
    {
        ttl += (*array)[i];        
    }
    avgMean = ttl/size;
    
    return avgMean;
}

//calculate the median avg
unsigned int median(unsigned int **array, int size)
{
    unsigned int avg;
    
    //calculate median if odd number of values exist
    if (size % 2 == 1)
    {
        if(size > 1)
            avg = *((*array)+(size - (size/2)-1));
        //in event only one element exists
        else
            avg = *(*array);
        
    }
    //if even number of values exist calculate the median
    else
    {
        if(size > 1)
        {
        avg = *((*array)+ (size/2)-1);
        avg += *((*array)+ (size/2));
        avg =  avg/2;
        }
        //in event only one element exists
        else
            avg = *(*array);
    }
    
    return avg;
}

ModeAry mode(unsigned int **array, int size)
{
    //variables
    ModeAry mde;         //will hold the mode values and information
    unsigned int mode;   //holds a mode found    
    int count = 0;        //counts the occurances of the mode
    int count2 = 0;       //counts the next possible mode
    bool mdeExt = false;  //set true only if a mode exists
    int numMdes = 0;      //counts the number of modes
    unsigned int *temp = new unsigned int [size]; //a temporary array to hold the multiple modes
    int    j=0;          //index for multiple mode array
    int minSize = 2;     //This is the mininum size the structure mode array will hold
    
    for (int i = 0; i < size; i++)
    {
        if(*(*array + i) == (*(*array + i + 1)) && mdeExt == false && size != i + 1)
        {                   
            mode = *(*array + i);
               
            count++;
            mdeExt = true;
        }else
        {
            if(*(*array + i) == mode && *(*array + i) == (*(*array + i + 1)) && size != i + 1)
            {
                count++;
            }else
            {
                if(*(*array + i) == (*(*array + i + 1)) && size != i + 1)
                {
                count2++;
                }else
                {
                    count2 =0;
                }
            }
        }        
        if(count < count2)
        {
            //replace the old mode and reset counter2 setting counter as the current most repeats
            mode = *(*array + i);
            count = count2;
            count2 = 0;           
        }
        
    }      
    
    //corrects a problem caused by the upper statements
    count++;
    
    //check and account for multiple modes
    if(mdeExt == true)
    {
        //at least a mode exists
        numMdes++;
        
        //find a second/third/... mode
        for(int i =0; i < size; i++)
        {           
            if(*(*array + i) != mode)
            {
                if(*(*array + i) == *(*array + i - 1))
                {
                        count2++;
                        if(count2 == count)
                    {
                        
                        numMdes++;
                        count2 = 0;
                        temp[j] = *(*array + i);
                        j++;                        
                    }
                    
                    //counter needs to be reset when new number
                    if(*(*array + i) != *(*array + i + 1) && size != i + 1)
                    {
                        count2 = 0;
                    }
                        
                        
                        
                }
                
                if(*(*array + i) == *(*array + i + 1) && size != i + 1)
                {
                    count2++;
                    
                    
                    
                    
                    if(count2 == count)
                    {
                        
                        numMdes++;
                        count2 = 0;
                        temp[j] = *(*array + i);
                        j++;                        
                    }
                    
                    //counter needs to be reset when new number
                    if(*(*array + i) != *(*array + i + 1) && size != i + 1)
                    {
                        count2 = 0;
                    }
                }
                
            }
        }
    }
    
    
    
    //corrects a problem in the lower if statment without modifying upper statements
    count++;
    
    //build the structure array containing all mode information
    if(mdeExt == true)
    {
        //set new size of mode array
        minSize += numMdes;
        
        //create the array
        mde.ptr = new unsigned int [minSize];
        mde.size = minSize;
        mde.modeExist = true;
        
        //set element zero to contain the number of modes present
        *(mde.ptr) = numMdes;
        
        //assign the first mode value
        *(mde.ptr + 2) = mode;
        
        //populate the remainder of the array
        for(int i = 3, k = 0; k <= j; i++)
        {
            *(mde.ptr + i) = temp[k];
            k++;
        }        
    }
    
    
    
    
    
    //free the memory
    delete [] temp;
    temp = 0;
    
    
    return mde;

}

