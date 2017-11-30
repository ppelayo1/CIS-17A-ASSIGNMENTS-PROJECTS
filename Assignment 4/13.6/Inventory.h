/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: Patrick
 *
 * Created on October 19, 2017, 6:56 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

//specification file for the inventory class
class Inv{
    private:
        int iNum; //item number
        int quan; //quanity of the items
        float cost; //cost of the item
        float ttlCst;     //ttl cost of all items quan * cost        
        void setTtlCst();
        
    public:
    Inv() {iNum = 0; quan = 0; cost = 0; ttlCst = 0;};
    Inv(int,int,float);
    
    //mutators
    void setInum(int);
    void setQuan(int);
    void setCost(float);
    
    
    //getters
    int getInum();
    int getQuan();
    float getCost();
    float getTtlCst();
    
};

#endif /* INVENTORY_H */

