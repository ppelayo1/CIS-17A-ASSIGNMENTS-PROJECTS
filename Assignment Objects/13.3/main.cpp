/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 14, 2017, 12:11 PM
 */

#include "preProc.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int mdl;
    string mke;
    
    cout << "Enter the car model year.\n";
    cin >> mdl;
    cin.ignore(1000,'\n');
    
    cout << "Enter the vehicle make.\n";
    getline(cin,mke);
    
    //build car object
    Car obj(mdl,mke);
    
    //test getters
    cout << "Testing the getters.\n";
    
    cout << "mdl = " << obj.getYrMdl() << endl;    
    cout << "mke = " << obj.getMke() << endl;
    cout << "spd = " << obj.getspd() << endl;
    
    cout << endl << "Now going to accelerate 5 times each call gives speed, then decelerate each call give speed.\n\n";
    
    ////////////////////////////////////////////////////////////////
    obj.acc();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.acc();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.acc();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.acc();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.acc();
    cout << "spd = " << obj.getspd() << endl;
    
    ///////////////////////////////////////////////////////////////
    obj.dec();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.dec();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.dec();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.dec();
    cout << "spd = " << obj.getspd() << endl;
    
    obj.dec();
    cout << "spd = " << obj.getspd() << endl;    
    
    return 0;
}

