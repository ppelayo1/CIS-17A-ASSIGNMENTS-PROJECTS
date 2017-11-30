/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 6, 2017, 7:21 PM
 */

#include "PreProc.h"

//funct prototypes
void inp(Weth [], int); //gets input for the weather structure
void out(Weth [], int); //outputs the data
int hTemp(Weth [], int); //highest temperature for year
int lTemp(Weth Wet[], int size); //finds loewst temp for year
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 12; //Size of array
    Weth Wet[SIZE];      //The weather structure for each month   
    
    
    
    
    
    //build the structure
    inp(Wet,SIZE);
    
    //output the info
    out(Wet,SIZE);
    
    return 0;
}

void inp(Weth Wet[], int SIZE) //gets input for the weather structure
{    
    for( int i = Janurary; i < SIZE; i++)
    {
        cout << "What is the total rainfall for month " << i+1 <<"?\n";
        cin >> Wet[i].rain;
        
        cout << "What is the lowest temperature for month " << i+1 << "?\n";
        cout << "Only -100 to 140 acceptable input.\n";
        cin  >> Wet[i].ltemp;
        
        //input validate
        while (Wet[i].ltemp < Wet[i].lowest || Wet[i].ltemp > Wet[i].hihgest)
        {
            cout << "That is not appropriate input.\n\n";
            cout << "What is the lowest temperature for month " << i+1 << "?\n";
            cout << "Only -100 to 140 acceptable input.\n";
            cin  >> Wet[i].ltemp;
        }
        
        cout << "What is the highest temperature for month " << i+1 << "?\n";
        cout << "Only -100 to 140 acceptable input and greater than or equal the lowest temp.\n";
        cin  >> Wet[i].htemp;
        
        //input validate
        while (Wet[i].htemp < Wet[i].lowest || Wet[i].htemp > Wet[i].hihgest || Wet[i].htemp < Wet[i].ltemp)
        {
            cout << "That is not appropriate input.\n\n";
            cout << "What is the highest temperature for month " << i+1 << "?\n";
            cout << "Only -100 to 140 acceptable input and greater than or equal the lowest temp.\n";
            cin  >> Wet[i].htemp;
        }
        
        //calculate and store the avg for that month
        Wet[i].avgT = (Wet[i].htemp + Wet[i].ltemp)/2.0;
        
        
        
    }
}

void out(Weth Wet[], int size) //outputs the data
{
    //variables
    float ttlR =0;//ttl rainfall for the year
    int low;    //lowest rainfall for year
    int high;   //highest rainfall for year
    short months = 12;//months of a year
    float aTemp =0; //The average total rainfall for the year
    
    //call lowest temp funcation
    low = lTemp(Wet,size);
    //call highest temp function
    high = hTemp(Wet,size);
    
    //output data and caccumulate rainfall
    for (int i = Janurary; i< size; i++)
    {
        cout << "The average temperature for month " << i+1 << " is " << Wet[i].avgT << ".\n";
        
        //accumulate the rainfall and temperatures
        ttlR+= Wet[i].rain;
        aTemp += Wet[i].ltemp + Wet[i].htemp;
    }
    
    //calculate the average of all months
    aTemp = aTemp/(months*2);
    
    //output ttl rainfall for year
    cout << "The total rainfall for the year is " << ttlR << " and the average for the year is " << ttlR/months <<".\n";
    cout << "The lowest temperature for the year is " << Wet[low].ltemp << " in month " << low + 1 << ".\n";
    cout << "The highest temperature for the year is " << Wet[high].htemp << " in month " << high + 1 << ".\n";
    cout << "The average temperature for the year is " << aTemp << ".\n";
}

int hTemp(Weth Wet[], int size) //finds highest temp for year
{
    int   elem = 0;            //temperature element
    float high = Wet[elem].htemp; //highest temp for the year
    
    for (int i = February; i < size; i++)
    {
        if (high < Wet[i].htemp)
        {
            high = Wet[i].htemp;
            elem = i;
        }
    }
    
    return elem;
}

int lTemp(Weth Wet[], int size) //finds loewst temp for year
{
    int   elem = 0;            //temperature element
    float low = Wet[elem].ltemp; //lowest temp for the year
    
    for (int i =1; i < size; i++)
    {
        if (low > Wet[i].ltemp)
        {
            low = Wet[i].ltemp;
            elem = i;
        }
    }
    
    return elem;
}