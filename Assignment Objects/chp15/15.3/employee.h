/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: rcc
 *
 * Created on November 16, 2017, 11:16 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "preProc.h"
using namespace std;

//base class
class Employee{
    private:
        string name;
        int empNum;
        string empHD;
        
    public:
        Employee(string s,int eN,string eI) {name = s; empNum = eN; empHD = eI;}        
        void setName(string s) {name = s;}
        void setEmpNum(int eN) {empNum = eN;}
        void setEmpHD(string eID) {empHD = eID;}
        
        string getName() {return name;}
        int getEmpNum() {return empNum;}
        string getempHD() {return empHD;}  
          
    
    
};


#endif /* EMPLOYEE_H */

