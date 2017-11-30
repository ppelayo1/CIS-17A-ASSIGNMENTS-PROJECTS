/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   milTime.h
 * Author: rcc
 *
 * Created on November 16, 2017, 11:49 AM
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "preProc.h"
using namespace std;

class MilTime : public Time{
    private:
        int milHours;
        int milSeconds;        
    public:
    MilTime() {milHours = 0, milSeconds = 0;}
    MilTime(int,  int );
    void setTime(int,int);
    int getHour() {return milHours;}
    int getStndHour() {return Time::getHour();}
            
    //exemptions
    class BadHour{};
    class BadSeconds{};
    
    
    
    
};


#endif /* MILTIME_H */

