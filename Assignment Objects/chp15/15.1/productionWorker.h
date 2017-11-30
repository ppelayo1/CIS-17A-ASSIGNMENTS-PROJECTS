/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   productionWorker.h
 * Author: rcc
 *
 * Created on November 16, 2017, 11:22 AM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "preProc.h"
using namespace std;

class ProductionWorker : public Employee
{
private:
    int shift;
    float payR;
    
public:
    ProductionWorker(string s,int eN,string eI, int shf, float pR) : Employee(s,eN,eI)
    {
        shift = shf;
        payR = pR;
    }       
    
    void setShift(int s) {shift = s;}
    void setPayR(float pR) {payR = pR;}
    int  getShift() {return shift;}
    float getPayR() {return payR;}
};


#endif /* PRODUCTIONWORKER_H */

