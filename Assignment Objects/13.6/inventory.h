/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   inventory.h
 * Author: rcc
 *
 * Created on November 14, 2017, 11:48 AM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "preProc.h"
using namespace std;

class Inventory
{
private:
    int iNum;
    int qty;
    float cost;
    float ttlcst; 
    void setTtlCst() {ttlcst = qty * cost;};
    
    
public:
    Inventory() {iNum =0; qty =0; cost = 0; ttlcst = 0;};
    Inventory(int,int,float);
    //setters
    void setInum(int);
    void setQty(int);
    void setCst(float);
    
    //getters
    int getInum() {return iNum;};
    int getQty() {return qty;};
    float getCst() {return cost;};
    float getTtlCst() {return ttlcst;};
    
    
    
};


#endif /* INVENTORY_H */

