/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   numbers.h
 * Author: rcc
 *
 * Created on November 14, 2017, 12:56 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include "preProc.h"
using namespace std;

class Numbers
{
private:
    int number;
    
    string numS[30]; //array of strings representing numbers
    
public:
    Numbers(int);
    
    void toString(); //outputs the number constructed as a string
    void setNumbers(int n) {number = n;};
    
    
    
};

#endif /* NUMBERS_H */

