/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   numDays.h
 * Author: Patrick
 *
 * Created on November 14, 2017, 7:03 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include "preProc.h"
using namespace std;

class NumDays
{
    private:
        float days;
        int hours;
        void calcDaysH(int);
        void calcDaysD(float);
    public:
        NumDays(int);
        void setDays(float d) {days = d; calcDaysD(d);};
        void setHours(int h) {hours = h; calcDaysH(h);};
        
        float getDays() {return days;};
        int geHours()  {return hours;};
        
        int operator + (NumDays &);
        int operator - (NumDays &);
        
        //prefix
        int operator ++ ();
        int operator -- ();
        
        //postfix
        int operator ++(int);
        int operator --(int);
    
    
    
};

#endif /* NUMDAYS_H */

