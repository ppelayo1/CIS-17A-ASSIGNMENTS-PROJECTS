#include "preProc.h"
using namespace std;

//private
void NumDays::calcDaysH(int h)
{
    hours = h;
    days = h/8.0;
    
    
}

void NumDays::calcDaysD(float d)
{
    days = d;
    hours = d*8;
    
}

//public
NumDays:: NumDays(int h)
{
    calcDaysH(h);
    
}


//prefix
        int NumDays::operator ++ ()
        {
            hours++;
            calcDaysH(hours);
            
            return hours;            
            
            
        }
        
        int NumDays::operator -- ()
        {
            hours--;
            calcDaysH(hours);
            
            return hours;  
            
            
            
        }
        
        //postfix
        int NumDays::operator ++(int)
        {
            NumDays temp(hours);
            hours++;
            calcDaysH(hours);
            
            return temp.hours;
        }
        int NumDays::operator --(int)
        {
            NumDays temp(hours);
            hours--;
            calcDaysH(hours);
            
            return temp.hours;            
                    
            
        }
        
        
        
int NumDays::operator + (NumDays &right)
{
    return hours+right.hours;
    
}


        


int NumDays::operator - (NumDays &right)
{
    return hours-right.hours;
}