/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 19, 2017, 6:56 PM
 */


#include "PreProc.h"



/*
 * 
 */
int main(int argc, char** argv) {
    //variables 
    int iNum;
    int quan;
    float cost;
    Inv *ptr = new Inv;  //this one will use 0 0 0 data
    
    cout << "The default constructor is being tested at this time and will output the default values of 0.\n";
    cout << "Press enter to continue.\n";
    cin.get();
    cout << endl << endl;
    
    //test the getters
    cout << "Inventory number from default constructor is " << ptr->getInum() << endl;
    cout << "Quanity from default constructor is " << ptr->getQuan() << endl;
    cout << "Cost from default constructor is " << ptr->getCost() << endl;
    cout << "Total Cost from default constructor is " << ptr->getTtlCst() << endl;
    
    //test the setters
    cout << "Enter the inventory number to set will be outputed  from get function..\n";
    cin >> iNum;    
    ptr->setInum(iNum);
    cout << "Inventory number  is " << ptr->getInum() << endl;
    
    cout << "Enter the quanity to set will be outputed  from get function..\n";
    cin >> quan;
    ptr->setQuan(quan);
    cout << "Quanity is " << ptr->getQuan() << endl;
    
    cout << "Enter the cost number to set will be outputed  from get function..\n";
    cin >> cost;
    ptr->setCost(cost);
     cout << "Cost is " << ptr->getCost() << endl;
    
    cout << "Total Cost  is " << ptr->getTtlCst() << endl;
    
    //delete current inventory object and create a new one testing the second constructor
    delete [] ptr;
    ptr = 0;
    
    //get new values
    cout << "Now testing the second constructor, enter requested values.\n";
    cout << "Enter the inventory number to set will be outputed  from get function..\n";
    cin >> iNum;
    
    cout << "Enter the quanity to set will be outputed  from get function..\n";
    cin >> quan;
    
    cout << "Enter the cost number to set will be outputed  from get function..\n";
    cin >> cost;
    
    //create the object
    ptr = new Inv(iNum,quan,cost);
    
    
    
    
    //check the stored values
    cout << "Inventory number from constructor is " << ptr->getInum() << endl;
    cout << "Quanity from constructor is " << ptr->getQuan() << endl;
    cout << "Cost from constructor is " << ptr->getCost() << endl;
    cout << "Total Cost from constructor is " << ptr->getTtlCst() << endl;
    
    //free up the memory
    delete [] ptr;
    ptr = 0;
    
    
    return 0;
}

