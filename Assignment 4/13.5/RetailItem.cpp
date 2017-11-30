/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




//imp file for the retail class
#include "RetailItem.h"

RetI::RetI(string des,int unit,float price)
{
    this->des = des;
    
    //input validate
    while(unit < 1)
    {
        cout << "Units must be greater then zero.\n";
        cout << "Please enter the unit amount again.\n";
        cin >> unit;
    }
    this->unit = unit;
    
    
     //input validate
    while(price < 0)
    {
        cout << "Price must be greater then zero.\n";
        cout << "Please enter the price amount again.\n";
        cin >> price;
    }
    this->price = price;
    
}
        //acessors
void RetI::setDes(string des)
{
    this->des = des;
}
void RetI::setUnit(int unit)
{
     //input validate
    while(unit < 1)
    {
        cout << "Units must be greater then zero.\n";
        cout << "Please enter the unit amount again.\n";
        cin >> unit;
    }
    this->unit = unit;
}
void RetI::setPrice(float price)
{
      //input validate
    while(price < 0)
    {
        cout << "Price must be zero or greater.\n";
        cout << "Please enter the price amount again.\n";
        cin >> price;
    }
    this->price = price;
}

//getters
string RetI::getDes()
{
    return des;
}
int    RetI::getUnit()
{
    return unit;
}
float  RetI::getPrice()
{
    return price;
}