/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 14, 2017, 11:16 AM
 */

#include "PreProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    string d; //description of item
    int u; //units on hand
    float p; //price
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    cout << endl << endl;
    
    //build object
    RetailItem objOne(d,u,p);
    
    cout << "The description is " << objOne.getDesc() << endl;
    cout << "The number of units is " << objOne.getuOnh() << endl;
    cout << "The price of the item is " << objOne.getPrice() << endl;
    
    //test the set then call get again
    cout << "Testing the get and set functions.\n";
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    objOne.setDesc(d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    objOne.setuOnH(u);
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    objOne.setPrice(p);
    
    cout << "The description is " << objOne.getDesc() << endl;
    cout << "The number of units is " << objOne.getuOnh() << endl;
    cout << "The price of the item is " << objOne.getPrice() << endl;
    
    cout << endl << endl;
    
    cout << "Building 2 differant objects to do the same thing.\n";
    //////////////////////////////////////////////////////////////////////
    
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    cout << endl << endl;
    
    //build object
    RetailItem objTwo(d,u,p);
    
    cout << "The description is " << objTwo.getDesc() << endl;
    cout << "The number of units is " << objTwo.getuOnh() << endl;
    cout << "The price of the item is " << objTwo.getPrice() << endl;
    
    //test the set then call get again
    cout << "Testing the get and set functions.\n";
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    objTwo.setDesc(d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    objTwo.setuOnH(u);
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    objTwo.setPrice(p);
    
    cout << "The description is " << objTwo.getDesc() << endl;
    cout << "The number of units is " << objTwo.getuOnh() << endl;
    cout << "The price of the item is " << objTwo.getPrice() << endl;
    
    cout << endl << endl;
    
    //////////////////////////////////////////////////////////////////////
    
    
    cout << "Testing the third object now.\n";
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    cout << endl << endl;
    
    //build object
    RetailItem objThree(d,u,p);
    
    cout << "The description is " << objThree.getDesc() << endl;
    cout << "The number of units is " << objThree.getuOnh() << endl;
    cout << "The price of the item is " << objThree.getPrice() << endl;
    
    //test the set then call get again
    cout << "Testing the get and set functions.\n";
    
    cout << "Please enter the description of the item.\n";
    getline(cin,d);
    
    objThree.setDesc(d);
    
    cout << "Please enter the number of units on hand.\n";
    cin >> u;
    
    objThree.setuOnH(u);
    
    cout << "Please enter the item price.\n";
    cin >> p;
    cin.ignore(1000,'\n');
    
    objThree.setPrice(p);
    
    cout << "The description is " << objThree.getDesc() << endl;
    cout << "The number of units is " << objThree.getuOnh() << endl;
    cout << "The price of the item is " << objThree.getPrice() << endl;
    
    cout << endl << endl;
    
    return 0;
}

