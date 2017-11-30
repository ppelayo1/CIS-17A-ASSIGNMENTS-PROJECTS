/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: Patrick
 *
 * Created on October 19, 2017, 9:00 PM
 */



#ifndef CAR_H
#define CAR_H

//class specification for car

#include <string>
using namespace std;

class Car
{
    private:    
        int yrMdl; //year model of car
        string mke; //make of the car
        int spd;   //current speed of car
        int spdC;  //speed change
    public:
        Car(int,string);
        
        //accessors
        int getYrMdl();
        string getMke();
        int getSpd();
        
        //other functions
        void acc(); //increases speed by spdC each time called
        void dec(); //decreases speed by spdC each time called
};


#endif /* CAR_H */

