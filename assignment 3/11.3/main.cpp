/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 5, 2017, 6:31 PM
 */

#include "PreProc.h""
#include "Structs.h"

//funct proto
void build(Div [], int);  //This will build the divisions and get input
void out(Div[],int);     //Output the division info
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int SIZE = 4; //number of divisions
    Div divs[SIZE]; //The divisions
    
    //build the divisions
    build(divs,SIZE);
    
    //call output function
    out(divs,SIZE);

    return 0;
}

void build(Div divs[], int size)  //This will build the divisions and get input
{
    //variables
    float sum = 0; //a sum of all sales
    
    //give the names for the divisions
    divs[0].name = "East";
    divs[1].name = "West";
    divs[2].name = "North";
    divs[3].name = "South";
    
    //Get sales for each Quarter
    for (int i =0; i < size; i++)
    {
        //first quarter
        cout << "Please enter the first quarterly sales for " << divs[i].name << " division.\n";
        cin >> divs[i].fstQrt;
        
        
        if(divs[i].fstQrt < 0)
        {
            cout << "The value must be a positive number or 0.\n\n";
            
            cout << "Please enter the first quarterly sales for " << divs[i].name << " division.\n";
            cin >> divs[i].fstQrt;
        }
        
        //add to sum
        sum +=divs[i].fstQrt;
        
        //second quarter
        cout << "Please enter the second quarterly sales for " << divs[i].name << " division.\n";
        cin >> divs[i].scQrt;
        
        if(divs[i].scQrt < 0)
        {
            cout << "The value must be a positive number or 0.\n\n";
            
            cout << "Please enter the second quarterly sales for " << divs[i].name << " division.\n";
            cin >> divs[i].scQrt;
        }
        
        //add to sum
        sum +=divs[i].scQrt;
        
        //third quarter
        cout << "Please enter the third quarterly sales for " << divs[i].name << " division.\n";
        cin >> divs[i].thdQrt;
        
        if(divs[i].thdQrt < 0)
        {
            cout << "The value must be a positive number or 0.\n\n";
            
            cout << "Please enter the third quarterly sales for " << divs[i].name << " division.\n";
            cin >> divs[i].thdQrt;
        }
        
        //add to sum
        sum +=divs[i].thdQrt;
        
        //fourth quarter
        
        cout << "Please enter the fourth quarterly sales for " << divs[i].name << " division.\n";
        cin >> divs[i].frtQrt;
        
        if(divs[i].frtQrt < 0)
        {
            cout << "The value must be a positive number or 0.\n\n";
            
            cout << "Please enter the first quarterly sales for " << divs[i].name << " division.\n";
            cin >> divs[i].frtQrt;
        }
        
        //add to sum
        sum +=divs[i].frtQrt;
        
        //add the total
        divs[i].ttl = sum;
        
        //attach the average
        divs[i].avg = sum/size;
        
        //reset sum
        sum = 0;
    }
}

void out(Div divs[],int size)     //Output the division info
{
    for(int i =0; i< size; i++)
    {
        cout << divs[i].name << " 1st Qrt sales:" <<setw(10) << divs[i].frtQrt;
        cout << " 2nd Qrt sales:" <<setw(7) << divs[i].scQrt;
        cout << " 3rd Qrt Sales:" <<setw(7) << divs[i].thdQrt;
        cout << " 4th Qrt Sales:" <<setw(7) << divs[i].frtQrt;
        cout << " annual sales:" << setw(7) << divs[i].ttl;
        cout << " avg sales Qrt:" << setw(7) << divs[i].avg << endl;
    }
}