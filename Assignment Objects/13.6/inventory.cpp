/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "preProc.h"
using namespace std;

//public
 
    Inventory::Inventory(int iN,int q,float cst)
    {
        while (iN < 0)
        {
            cout << "Item Number must be 0 or greater.\n";
            cin >> iN;
            cin.ignore(1000,'\n');
        }
        iNum = iN;
        
        while(q < 0)
        {
            cout << "The quantity must be 0 or greater.\n";
            cin >> q;
            cin.ignore(1000,'\n');
            
            
        }
        
        qty = q;
        
        while(cst < 0)
        {
            cout << "The cost of the item must be 0 or greater.\n";
            cin >> cst;
            cin.ignore(1000,'\n');
            
        }
        
        cost = cst;
        
        //calculate and set the ttlcst by calling its funcition
        setTtlCst();
        
    }
    
    
    //setters
    void Inventory::setInum(int iN)
    {
        while (iN < 0)
        {
            cout << "Item Number must be 0 or greater.\n";
            cin >> iN;
            cin.ignore(1000,'\n');
        }
        iNum = iN;
    }
    
    
    void Inventory::setQty(int q)
    {
        while(q < 0)
        {
            cout << "The quantity must be 0 or greater.\n";
            cin >> q;
            cin.ignore(1000,'\n');
            
            
        }
        
        qty = q;
        
        //calculate and set the ttlcst by calling its funcition
        setTtlCst();
        
        
    }
    void Inventory::setCst(float cst)
    {
        
        while(cst < 0)
        {
            cout << "The cost of the item must be 0 or greater.\n";
            cin >> cst;
            cin.ignore(1000,'\n');
            
        }
        
        cost = cst;
        
        //calculate and set the ttlcst by calling its funcition
        setTtlCst();
        
    }
    
    