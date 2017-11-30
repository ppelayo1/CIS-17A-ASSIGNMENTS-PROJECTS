/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: Patrick
 *
 * Created on October 19, 2017, 6:18 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>
#include <iostream>
using namespace std;
//class specification file for a retail item
class RetI
{
    private: 
        string des;   //item description
        int    unit;  //units available
        float  price; //price of object
    public:
        RetI(string,int,float);
        //acessors
        void setDes(string);
        void setUnit(int);
        void setPrice(float);
        
        //getters
        string getDes();
        int    getUnit();
        float  getPrice();
        
};

#endif /* RETAILITEM_H */

