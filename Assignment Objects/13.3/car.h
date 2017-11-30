/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   car.h
 * Author: rcc
 *
 * Created on November 14, 2017, 12:21 PM
 */

#ifndef CAR_H
#define CAR_H

#include "preProc.h"
using namespace std;

class Car
{
private:
    int yrMdl;
    string mke;
    int spd;
    
public:
    Car(int yM,string m) {yrMdl = yM; mke = m; spd = 0;};
    
    int getYrMdl() {return yrMdl;};
    string getMke() {return mke;};
    int getspd() {return spd;};
    
    void acc() {spd+=5;};
    void dec() {spd-=5; if(spd < 0) spd = 0;};
        
    
    
};

#endif /* CAR_H */

