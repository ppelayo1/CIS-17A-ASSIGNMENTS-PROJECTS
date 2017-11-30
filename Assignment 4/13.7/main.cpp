/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 19, 2017, 7:43 PM
 */

#include "PreProc.h"



/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int num;  //number of widgits desired
    
    //prompt for num
    cout << "Please enter the number of widgits that you would like to know the number of days to make.\n";
    cin >> num;
    
    //create the Wid object
    Wid object(num);
    
    //output the number of days
    cout << "It will take " << object.getNd() << " days to make those widgits.\n";
    

    return 0;
}

