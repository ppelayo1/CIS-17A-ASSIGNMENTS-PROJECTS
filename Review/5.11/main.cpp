/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 16, 2017, 8:54 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    unsigned long long org; //# of organisms
    int dayinc; //daily population increase
    int numday; //number of days to predict pop increase  
    
    //prompt user for the # of organisms
    cout << "How many organisms would you like to start off with?\n";
    cin  >> org;
    
    //input validate
    while(org < 2)
    {
        cout << "The number of organisms must be 2 or greater.\n\n";
        cout << "How many organisms would you like to start off with?\n";
        cin  >> org;                
    }
    
    //prompt for daily pop increase
    cout << "What percentage would you like the daily population increase to be?\n";
    cout <<"Enter the number only, do not enter any decimals.\n";
    cin >> dayinc;
    
    //input validate
    while (dayinc < 0)
    {
        cout << "The daily population increase can not be a negative number.\n\n";
        cout << "What percentage would you like the daily population increase to be?\n";
        cout <<"Enter the number only, do not enter any decimals.\n";
        cin >> dayinc;
    }
    
    //prompt for number of days to perform the calculation
    cout <<"How many days would you like to calculate population growth?\n";
    cin >> numday;
    
    //input validate
    while (numday<1)
    {
        cout << "The number of days must be 1 or greater.\n\n";
        cout <<"How many days would you like to calculate population growth?\n";
        cin >> numday;
    }
    
    //loop and calculate each days population and output
    for(int i=1; i<=numday;i++)
    {               
        //calculate pop        
        org= org*static_cast<float>(dayinc) /100 + org;
        
        //output daily population
        cout << left << setw(24)<< "The population for day" << setw(3) << i<< setw(4)<< "is" << org << ".\n";
    }
            
    

    return 0;
}

