
#include "preProc.h"
using namespace std;

MilTime::MilTime(int h,  int s)
{
    //variables
    int temp;
    
    //input validate
    while(h > 2359 || h < 0)
    {
        cout << "The military hour must be between 0 and 2359\n";
        cin >> h;
    }
    
    while(s < 0 || s > 59)
    {
        cout << "The military seconds must be between 0 and 59\n;";
        cin >> s;
    }
    
    milHours = h;
    milSeconds = s;
    sec = s;
    
    
    
    //convert hours to hours and minutes
    if(h < 100)
    {
        hour = 12;
        min = h;
    }
    
    if (h >= 100 && h < 1300)
    {
        temp = h;
        
        while(temp > 100)
        {
            temp-= 100;
        }
        min = temp;
        hour = h / 100;
        
    }
    
    if(h>= 1300 && h <= 2400)
    {
        temp = h;
        
        while(temp > 100)
        {
            temp-= 100;
        }
        min = temp;
        
        hour = (h / 100) - 12;
    }
}

void MilTime::setTime(int h,int s)
{
    //variables
    int temp;
    
    //input validate
    while(h > 2359 || h < 0)
    {
        cout << "The military hour must be between 0 and 2359\n";
        cin >> h;
    }
    
    while(s < 0 || s > 59)
    {
        cout << "The military seconds must be between 0 and 59\n;";
        cin >> s;
    }
    
    milHours = h;
    milSeconds = s;
    sec = s;
    
    
    
    //convert hours to hours and minutes
    if(h < 100)
    {
        hour = 12;
        min = h;
    }
    
    if (h >= 100 && h < 1300)
    {
        temp = h;
        
        while(temp > 100)
        {
            temp-= 100;
        }
        min = temp;
        hour = h / 100;
        
    }
    
    if(h>= 1300 && h <= 2400)
    {
        temp = h;
        
        while(temp > 100)
        {
            temp-= 100;
        }
        min = temp;
        
        hour = (h / 100) - 12;
    }
}