/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 9, 2017, 12:22 PM
 */

#include <iostream>
#include "pInfo.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    string name;
    string address;
    int age;
    string phoneN;
    
    cout << "Testing constructor\n";
    cout << "Enter name\n";
    getline(cin,name);
    
    
    
    cout << "Enter address\n";
    getline(cin,address);
    
    
    
    cout << "Enter the age.\n";
    cin >> age;
    
    cin.ignore(1000,'\n');
    
    cout << "Enter phone number\n";
    getline(cin,phoneN);
    
    
    
    //build the object
    Pinfo person1(name,address,age,phoneN);
    
    cout << endl << endl;
    
    //test the getters, then accessors, then getters again
    cout << "Testing the constructor and getters\n";
    cout << person1.getAdd() << endl << person1.getAge() << endl << person1.getName() << endl;
    cout << person1.getPnum() << endl;
    
    cout << endl << endl;
    
    cout << "Test setters then call getters again\n";
    cout << "Enter name\n";
    getline(cin,name);
    
    
    
    cout << "Enter address\n";
    getline(cin,address);
    
    
    
    cout << "Enter the age.\n";
    cin >> age;
    
    cin.ignore(1000,'\n');
    
    cout << "Enter phone number\n";
    getline(cin,phoneN);
    
    
    
    person1.setName(name);
    person1.setAge(age);
    person1.setAdd(address);
    person1.setPnum(phoneN);
    
    //call getters again
    cout << person1.getAdd() << endl << person1.getAge() << endl << person1.getName() << endl;
    cout << person1.getPnum() << endl;
    
    
    
    //test two other objects
    
    cout << "Two other objects for friends and family created.\n";
    
    //build the object
    Pinfo person2;
    
    cout << endl << endl;
    
        
    cout << "Test setters then call getters again second object\n";
    cout << "Enter name\n";
    getline(cin,name);
    
    
    
    cout << "Enter address\n";
    getline(cin,address);
    
    
    
    cout << "Enter the age.\n";
    cin >> age;
    
    cin.ignore(1000,'\n');
    
    cout << "Enter phone number\n";
    getline(cin,phoneN);
    
    
    
    person2.setName(name);
    person2.setAge(age);
    person2.setAdd(address);
    person2.setPnum(phoneN);
    
    //call getters again
    cout << person2.getAdd() << endl << person2.getAge() << endl << person2.getName() << endl;
    cout << person2.getPnum() << endl;
    
    
    //build the object
    Pinfo person3;
    
    cout << endl << endl;
    
        
    cout << "Test setters then call getters again third object\n";
    cout << "Enter name\n";
    getline(cin,name);
    
    
    
    cout << "Enter address\n";
    getline(cin,address);
    
    
    
    cout << "Enter the age.\n";
    cin >> age;
    
    cin.ignore(1000,'\n');
    
    cout << "Enter phone number\n";
    getline(cin,phoneN);
    
    
    
    person3.setName(name);
    person3.setAge(age);
    person3.setAdd(address);
    person3.setPnum(phoneN);
    
    //call getters again
    cout << person3.getAdd() << endl << person3.getAge() << endl << person3.getName() << endl;
    cout << person3.getPnum() << endl;

    return 0;
}

