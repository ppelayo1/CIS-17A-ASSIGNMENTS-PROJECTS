/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   retailItem.h
 * Author: rcc
 *
 * Created on November 14, 2017, 11:18 AM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include "PreProc.h"
using namespace std;

class RetailItem
{

    
private:
    string desc;
    int uOnH; //units on hand
    float price;
    
public:
    RetailItem(string, int, float);
    
    void setDesc(string d) {desc=d;};
    void setuOnH(int);
    void setPrice(float);
    string getDesc() {return desc;};
    int getuOnh() {return uOnH;};
    float getPrice() {return price;};    
    
    
};

#endif /* RETAILITEM_H */

