/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chk.h
 * Author: Patrick
 *
 * Created on October 28, 2017, 12:50 PM
 */

//structure for employee information
#ifndef CHK_H
#define CHK_H
struct Emp
{
    
    std::string name;  //that employees name
    float rPay; //rate of pay hourly
    int hours; //number of hours worked
    float gPay = 0; //gross pay
};


#endif /* CHK_H */

