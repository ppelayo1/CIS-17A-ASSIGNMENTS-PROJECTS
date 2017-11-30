/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Widgit.h
 * Author: Patrick
 *
 * Created on October 19, 2017, 8:09 PM
 */

#ifndef WIDGIT_H
#define WIDGIT_H

//this is a class spec. that calculates the number of 16 hour days are required
//to produce the entered number of widgets.
class Wid{
    private:
        int dL; //The number of hours per day of work
        int n;  //The number of widgets produced by hour
        int nW; //The number of widgets desired to be produced
        int nD; //Number of days to produce the desired widgets
        void calcD(); //This will calculate the number of days to produce the desired widgets
        
    public:
        Wid(int); //constructor
        
        //accessors
        int getNd(); //Returns the number of days needed to produce the desired widgets
};

#endif /* WIDGIT_H */

