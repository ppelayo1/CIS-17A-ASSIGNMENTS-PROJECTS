#include <cstdlib>
#include "feetInches.h"


void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if(inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
    
    
    
}


FeetInches FeetInches:: operator + (const FeetInches &right)
{
    FeetInches temp;
    
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
    
}

FeetInches FeetInches::operator - (const FeetInches &right)
{
    
    FeetInches temp;
    
    temp.inches = inches - right.inches;
    temp.feet = feet-right.feet;
    temp.simplify();
    return temp;
    
}

bool FeetInches::operator <= (const FeetInches &right)
{
    bool flag = false;
    
    if (feet < right.getFeet())
    {
        flag = true;
    }else{
        
    
        if(feet == right.getFeet())
        {
            if (inches <= right.getInches())
            {
                flag = true;
            }
        }
    }
    
    return flag;
}



   bool FeetInches::operator >= (const FeetInches &right)
   {
       bool flag = false;
    
    if (feet > right.getFeet())
    {
        flag = true;
    }else{
        
    
        if(feet == right.getFeet())
        {
            if (inches >= right.getInches())
            {
                flag = true;
            }
        }
    }
    
    return flag;
       
       
       
   }
   bool FeetInches::operator != (const FeetInches &right)
   {
       bool flag = true;
       
       if(feet == right.getFeet() && inches == right.getInches())
       {
           flag = false;
       }
       
       return flag;
   }

