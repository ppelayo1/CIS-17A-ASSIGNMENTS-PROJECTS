/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on September 14, 2017, 11:05 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    float divSales; //sales of division
    
    //prompt for sales for division
    cout << left << setw(37)<<"What were the sales for the division";
    cin >> divSales;
    
    //output the divSales;
    cout << setw(32) << "The sales for the division were" << fixed << setw(8) << setprecision(2)   << divSales;
    

    return 0;
}

