/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "preProc.h"
using namespace std;

DayOfYear::DayOfYear(int d)
{
    day = d;
    flag = true;
    
    month[0] = "January";
    month[1] = "February";
    month[2] = "March";
    month[3] = "April";
    month[4] = "May";
    month[5] = "June";
    month[6] = "July";
    month[7] = "August";
    month[8] = "September";
    month[9] = "October";
    month[10] = "November";
    month[11] = "December";
        
    
    
}

DayOfYear::DayOfYear(int d,string s)
{
    mnthEl = -2;
    
    month[0] = "January";
    month[1] = "February";
    month[2] = "March";
    month[3] = "April";
    month[4] = "May";
    month[5] = "June";
    month[6] = "July";
    month[7] = "August";
    month[8] = "September";
    month[9] = "October";
    month[10] = "November";
    month[11] = "December";
    
    
    
    flag = false;
    if(d < 0 || d > 31)
    {
        cout << "Out of range of day, program will end.";
        exit(EXIT_FAILURE);
    }
    day = d;
    
    for(int i = 0; i < 13 && mnthEl != i - 1; i++)
    {
        if(s == month[i])        {
            
            mnthEl = i;
        }
        if(i == 12)
        {
            cout << "The month does not exist, the program will end.";
            exit(EXIT_FAILURE);
        }
    }
    
    
}

void DayOfYear::toString()
{
    int temp;
    
    if(flag == true)
    {
        if(day >= 1 && day <= 31)
        {
            cout << month[0] << " " << day;
        }else
        {
            temp = day;
            temp-=31;
            if(temp >= 1 && temp <= 28)
            {
                cout << month[1] << " " << temp;
            }else
            {
                temp = day;
                temp-= 59;
                if(temp >= 1 && temp<= 31)
                {
                    cout << month[2]<< " " << temp;
                }else
                {
                    temp = day;
                    temp -= 90;
                    if(temp >= 1 && temp <= 30)
                    {
                        cout << month[3] << " " << temp;
                    }else
                    {
                        temp = day;
                        temp -= 120;
                        if(temp >= 1 && temp <= 31)
                        {
                            cout << month[4] << " " << temp;
                        }else
                        {
                            temp = day;
                            temp -= 151;
                            if(temp >= 1 && temp <= 30)
                            {
                                cout << month[5] << " " << temp;
                            }
                            else{
                                temp = day;
                                temp -= 181;
                                if(temp >= 1 && temp <= 31)
                                {
                                    cout << month[6] << " " << temp;
                                }else
                                {
                                    temp = day;
                                    temp -= 212;
                                    if(temp>=1 && temp <= 31)
                                    {
                                        cout << month[7] <<" " << temp;
                                    }else
                                    {
                                        temp = day;
                                        temp -= 243;
                                        if(temp >=1 && temp <= 30)
                                        {
                                            cout << month[8] << " " << temp;
                                        }else
                                        {
                                            temp = day;
                                            temp -= 273;
                                            if(temp >= 1 && temp <= 31)
                                            {
                                                cout << month[9] << " " << temp;
                                            }else
                                            {
                                                temp = day;
                                                temp -= 304;
                                                if(temp >= 1 && temp <= 30)
                                                {
                                                    cout << month[10] << " " << temp;
                                                }else{
                                                    temp = day;
                                                    temp-= 334;
                                                    if(temp >=1 && temp <= 31)
                                                    {
                                                        cout << month[11] << " " << temp;
                                                    }
                                                }
                                            }
                                        }

                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }else
    {
        cout << month[mnthEl] << " " << day;
    }
        
    
    
    
    
}

DayOfYear DayOfYear::operator++(int )
{
    
    
    if(flag == true)
    {
        
        DayOfYear temp(day);
        day++;        
    
        if(day > 365)
        {
            day = 1;
        }   
        return temp;
    }else
    {
        cout << "This function does not work with the second constructor.\n";
         exit(EXIT_FAILURE);
    }
    
    
    
}

DayOfYear DayOfYear::operator--(int)
{
   if(flag == true)
    {
        
        DayOfYear temp(day);
        day--;
    
        if(day < 1)
        {
            day = 365;
        }   
        return temp;
    }else
    {
        cout << "This function does not work with the second constructor.\n";
         exit(EXIT_FAILURE);
    }
   
   
}