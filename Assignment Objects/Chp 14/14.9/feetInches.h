/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   feetInches.h
 * Author: Patrick
 *
 * Created on November 14, 2017, 7:55 PM
 */

#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches
{
private:
    int feet;
    int inches;
    void simplify();
    
public:
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }
  
   void setFeet(int f)
    {
        feet = f;
    }
    
   void setInches(int i)
   {
       inches = i;
       simplify();
   }
   
   int getFeet() const
   {
       return feet;
   }
   
   int getInches() const
   {
       return inches;
   }
   
   FeetInches operator + (const FeetInches &);
   FeetInches operator - (const FeetInches &);
   
   bool operator <= (const FeetInches &);
   bool operator >= (const FeetInches &);
   bool operator != (const FeetInches &);
   
   
};

#endif /* FEETINCHES_H */

