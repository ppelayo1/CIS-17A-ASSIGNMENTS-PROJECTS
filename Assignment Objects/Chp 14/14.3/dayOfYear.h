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
    int mnthEl; //current month element for when user enters month
    string month[12];
    bool flag;   //This is a flag that is set true when constructor 2 runs or false when constructor 1 runs
    
public:
    DayOfYear(int);
    DayOfYear(int,string);
    void toString();
    DayOfYear operator++(int);
    DayOfYear operator--(int);
    
    
    
    
};

#endif /* DAYOFYEAR_H */

