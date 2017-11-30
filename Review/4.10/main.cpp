/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on September 14, 2017, 11:29 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int qtySld; //The quantity of products sold
    float dsc10_19 = 0.20; //Discount if 10-19 items were sold
    float dsc20_49 = 0.30; //Discount if 20-49 items were sold
    float dsc50_99 = 0.40; //Discount if 50-99 items were sold
    float dsc100_xx = 0.50; //Discount if 100> items were sold
    float prodP    = 99.00; //price of the product
    float ttlCst;           //total cost of the sale
        
    //prompt for quanity sold
    cout << left << setw(33)<< "How many of the units were sold?";
    cin >> qtySld;
    cout << endl;
    
    //input validate
    while(qtySld <= 0)
    {
        
        cout <<"The quantity of units sold must be greater than zero.\n";
        cout << setw(33)<< "How many of the units were sold?";
    cin >> qtySld;
    cout << endl;
    }
    
    //calculate the total cost of the sale
    if (qtySld < 10)
        ttlCst = qtySld * prodP;
    
    if(qtySld >= 10 && qtySld <= 19)
        ttlCst = qtySld*(prodP - (prodP*dsc10_19));
    
    if(qtySld >= 20 && qtySld <= 49)
        ttlCst = qtySld*(prodP - (prodP*dsc20_49)); 
    
    if(qtySld >= 50 && qtySld <= 99)
        ttlCst = qtySld*(prodP - (prodP*dsc50_99));
    
    if(qtySld > 99)
        ttlCst = qtySld*(prodP - (prodP*dsc100_xx));
    //output the total cost of all units
    cout << "The total cost of the sale is $" << ttlCst;
    
    

    return 0;
}

