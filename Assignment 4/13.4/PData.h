/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PData.h
 * Author: Patrick
 *
 * Created on October 17, 2017, 2:53 PM
 */

//class specification file for  personal data class

#ifndef PDATA_H
#define PDATA_H


#include <string>
using namespace std;


class PData
{
    private:
        string name; //person name
        string ad;   //person address
        int    age;  //person age
        string num;  //person phone number
    public:
        //mutators
        void setName(string);
        void setAd(string);
        void setAge(int);
        void setNum(string);
        //accessors
        string getName();
        string getAd();
        int    getAge();
        string getNum();
};

#endif /* PDATA_H */

