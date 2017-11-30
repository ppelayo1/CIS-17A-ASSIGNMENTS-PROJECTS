/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustChk.h
 * Author: Patrick
 *
 * Created on October 28, 2017, 11:23 AM
 */

//this is the customer checking account structure

#ifndef CUSTCHK_H
#define CUSTCHK_H

struct CBnkC
{
    std::string name; //name of the customer
    std::string address; //customers address
    int acct; //account number for this customer
    float bal; //current balance of account
    float chks; //checks/withdrawl values
    float dep;  //deposits to the account
};

#endif /* CUSTCHK_H */

