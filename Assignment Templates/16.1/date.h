/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: rcc
 *
 * Created on November 9, 2017, 11:19 AM
 */




#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
    
    private:
        int month;
        int day;
        int year;
        string mString(); //Returns string of month
        
        
    public:
        Date() {month = 0; day = 0; year = 0;}
        Date(int,int,int);  //handles input validation
        void setDay(int);
        void setMnth(int);
        void setYr(int);
        void print1(); //12/25/2012
        void print2(); //December 25, 2012
        void print3(); //25 December 2012
        
        //exemption classes
        class InvalidDay
        {};
        class InvalidMonth
        {};
        
    
};


#endif /* DATE_H */

