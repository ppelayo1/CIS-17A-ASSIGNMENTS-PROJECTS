/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 16, 2017, 11:15 AM
 */

#include "preProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    string name;
    int empNum;
    string empHD;
    int shift;
    float payR;
    
    //prompts
    cout << "Please enter the name.\n";
    getline(cin,name);
    
    cout << "Please enter the employee number";
    cin >> empNum;
    cin.ignore(1000,'\n');
    
    cout << "Please enter the employee hiring date.\n";
    getline(cin,empHD);
    
    cout << "Please enter the shift of employee 1 for day, 2 for night.\n";
    cin >> shift;
    
    
    cout << "Please enter the payrate for the employee.\n";
    cin >> payR;
    cin.ignore(1000,'\n');
    
    //build object test returns 
    ProductionWorker objOne(name,empNum,empHD,shift,payR);
    
  
    
    cout << "All getters tested\n";
    cout << "Employee name = " << objOne.getName() << endl;
    cout << "Employee number = " << objOne.getEmpNum() << endl;
    cout << "Employee hire date = "<< objOne.getempHD() << endl;
    cout << "Employee shift = " << objOne.getShift() << endl;
    cout << "Employee payR = " << objOne.getPayR() << endl; 
    
    return 0;
}

