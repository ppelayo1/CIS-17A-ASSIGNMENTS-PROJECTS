/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time.h
 * Author: rcc
 *
 * Created on November 16, 2017, 11:43 AM
 */

#ifndef TIME_H
#define TIME_H

#include "preProc.h"

class Time{
    
protected:
    int hour;
    int min;
    int sec;
    
public:
    Time()
    {hour = 0; min = 0; sec = 0;}
    
    Time(int h, int m, int s)
    {
        hour = h; min = m; sec = s;   
    
    }
    
    int getHour() {return hour;}
    int getMin() {return min;}
    int getSec() {return sec;}  
    
    
};


#endif /* TIME_H */

