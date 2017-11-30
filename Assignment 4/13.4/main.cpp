/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 17, 2017, 2:52 PM
 */

#include "PData.h"
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 3;//size of the object array
    string data;       //holds names, addresses, and numbers
    int age;           //holds the age of person
    //create the three class objects
    PData info[SIZE];
    
    //prompt for the info set the info, and call the info
    for(int i =0; i < SIZE; i++)
    {
        //set and get name
        cout << "Please enter the name of person " << i+1 << ".\n";
        getline(cin,data);
        info[i].setName(data);
        cout << "You entered a name as "<< info[i].getName() << endl << endl;
        
        //set and get address
        cout << "Please enter the address of person " << i+1 <<".\n";
        getline(cin,data);
        info[i].setAd(data);
        cout << "You entered a address as "<< info[i].getAd() << endl << endl;
        
        //set and get the age
        cout << "Please enter the age of person " << i+1 <<".\n";
        cin >> age;
        info[i].setAge(age);
        cout << "You entered  the age as "<< info[i].getAge() << endl << endl;
        
        //clear buffer
        cin.ignore(1000,'\n');
        
        //set and get the phone number
        cout << "Please enter the phone number of person " << i+1 <<".\n";
        getline(cin,data);
        info[i].setNum(data);
        cout << "You entered  the number as "<< info[i].getNum() << endl << endl;
        
    }
    return 0;
}

