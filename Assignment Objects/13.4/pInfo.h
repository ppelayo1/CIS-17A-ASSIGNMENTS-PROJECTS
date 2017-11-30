/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pInfo.h
 * Author: rcc
 *
 * Created on November 9, 2017, 12:26 PM
 */

#ifndef PINFO_H
#define PINFO_H

#include <string>
#include <iostream>
using namespace std;

class Pinfo
{
    
private:
    string name;
    string address;
    int age;
    string pNum;
    
public:
    Pinfo();
    Pinfo(string, string, int, string);
    string getName() {return name;}
    string getAdd() {return address;}
    int getAge() {return age;}
    string getPnum() {return pNum;}
    
    void setName(string n) {name = n;}
    void setAdd(string a) {address = a;}
    void setAge(int );
    void setPnum(string p) {pNum = p;}   
    
};


#endif /* PINFO_H */

