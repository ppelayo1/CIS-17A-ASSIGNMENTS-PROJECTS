/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "PData.h"


//implication file for the PData class

//mutators
        void PData::setName(string name)
        {
            this->name = name;
            
        }
        void PData::setAd(string ad)
        {
            this->ad = ad;
            
        }
        void PData::setAge(int age)
        {
            this->age = age;
            
        }
        void PData::setNum(string num)
        {
            
            this->num = num;
        }
        
        
        //accessors
        string PData::getName()
        {
            return name;
            
        }
        string PData::getAd()
        {
            
            return ad;
        }
        int    PData::getAge()
        {
            return age;
            
        }
        string PData::getNum()
        {
            return num;
            
        }