/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 14, 2017, 11:47 AM
 */

#include "preProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int iN; //item number
    int qty; 
    float cost;
    Inventory objOne;
    
    //test thru first object
    cout << "Testing the constructor of object one.\n";
    cout << "Inum = " << objOne.getInum() << endl;
    cout << "Qty = " << objOne.getQty() << endl;
    cout << "cost = " << objOne.getCst() << endl;
    cout << "TtlCst = " << objOne.getTtlCst() << endl << endl;
    
    //test the  setters
    cout << "Testing the setters.\n";
    
    cout << "What is the Inumber?\n";
    cin >> iN;
    objOne.setInum(iN);
    
    cout << "What is the qty?\n";
    cin >> qty;
    objOne.setQty(qty);
    
    cout << "What is the cost?\n";
    cin >> cost;
    objOne.setCst(cost);
    
    //call them
    cout << endl;
    
    cout << "Testing the constructor of object one.\n";
    cout << "Inum = " << objOne.getInum() << endl;
    cout << "Qty = " << objOne.getQty() << endl;
    cout << "cost = " << objOne.getCst() << endl;
    cout << "TtlCst = " << objOne.getTtlCst() << endl << endl;
    
    //test the second constructor
    cout << "Now testing the second constructor.\n";
    
    cout << "What is the Inumber?\n";
    cin >> iN;
    
    
    cout << "What is the qty?\n";
    cin >> qty;
    
    
    cout << "What is the cost?\n";
    cin >> cost;
    
    Inventory objTwo(iN,qty,cost);
    
    cout << "Testing the constructor of object one.\n";
    cout << "Inum = " << objTwo.getInum() << endl;
    cout << "Qty = " << objTwo.getQty() << endl;
    cout << "cost = " << objTwo.getCst() << endl;
    cout << "TtlCst = " << objTwo.getTtlCst() << endl << endl;
    
    
    return 0;
}

