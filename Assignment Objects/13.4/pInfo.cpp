/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "pInfo.h"

//public func
Pinfo::Pinfo()
{
    name = "none";
    age = 0;
    address == "none";
    pNum = "none";
    
}

Pinfo::Pinfo(string n, string a, int age, string pn)
{
    name = n;
    address = a;
    
    
    
    while(age < 0 || age > 120)
    {
        cout << "Age must be 0 to 120.\n";
        cin >> age;
        cin.ignore(1000,'\n');
        
    }
    this->age = age;
    pNum = pn;
    
}

void Pinfo::setAge(int a)
{
    while(a < 0 || a > 120)
    {
        cout << "Age must be 0 to 120.\n";
        cin >> a;
        cin.ignore(1000,'\n');
    }
    age = a;
    
    
}