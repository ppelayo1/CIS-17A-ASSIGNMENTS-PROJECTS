/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shiftSupervisor.h
 * Author: Patrick
 *
 * Created on November 16, 2017, 6:44 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "preProc.h"
using namespace std;
class ShiftSupervisor : public Employee{
    private:
        float salary;
        float bonus;
        
    public:
        ShiftSupervisor(float salar, float bon, string nam, int empNum, string empHD ) : Employee(nam,empNum,empHD)
        {
            salary = salar;
            bonus = bon;
        }
    
        float getSalary() {return salary;}
        float getBonus() {return bonus;}
        void setSalary(float s) {salary = s;}
        void setBonus(float b) {bonus = b;}
        
    
};

#endif /* SHIFTSUPERVISOR_H */

