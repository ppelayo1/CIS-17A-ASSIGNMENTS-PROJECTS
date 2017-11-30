/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dayOfYear.h
 * Author: rcc
 *
 * Created on November 14, 2017, 2:04 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include "preProc.h"
using namespace std;

class DayOfYear{
private:
    int day;
    string month[12];
    
public:
    DayOfYear(int);
    
    void toString();
    
    
    
    
};

#endif /* DAYOFYEAR_H */

