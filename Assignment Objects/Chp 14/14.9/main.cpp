/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 14, 2017, 7:54 PM
 */

#include "feetInches.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    FeetInches objOne;
    FeetInches objTwo;
    
    
    objOne.setFeet(3);
    objOne.setInches(15);
    objTwo.setFeet(3);
    objTwo.setInches(15);
    
    
    
    cout << "Object one feet = " << objOne.getFeet() << " Objet one inches = " << objOne.getInches() << endl;
    cout << "Object two feet = " << objTwo.getFeet() << " Objet two inches = " << objTwo.getInches() << endl;
    
    if(objOne <= objTwo)
        cout <<"Objone is <= objTwo\n\n";
    
    if(objOne >= objTwo)
        cout <<"Objone is >= objTwo\n\n";
    
    if(objOne != objTwo)
        cout <<"Objone is != objTwo\n\n";
            
    return 0;
}

