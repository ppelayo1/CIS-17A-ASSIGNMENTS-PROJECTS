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
    float salary;
    float bonus;
    
    //prompts
    cout << "Please enter the name.\n";
    getline(cin,name);
    
    cout << "Please enter the employee number\n";
    cin >> empNum;
    cin.ignore(1000,'\n');
    
    cout << "Please enter the employee hiring date.\n";
    getline(cin,empHD);
    
    cout << "Please enter the employee salary\n";
    cin >> salary;
    
    
    cout << "Please enter the bonus for the employee.\n";
    cin >> bonus;
    cin.ignore(1000,'\n');
    
    //build object test returns 
    ShiftSupervisor objOne(salary,bonus,name,empNum,empHD);
    
    cout << "All getters tested\n";
    cout << "Employee name = " << objOne.getName() << endl;
    cout << "Employee number = " << objOne.getEmpNum() << endl;
    cout << "Employee hire date = "<< objOne.getempHD() << endl;
    cout << "Employee salary = " << objOne.getSalary() << endl;
    cout << "Employee bonus = " << objOne.getBonus() << endl; 
    
    return 0;
}

