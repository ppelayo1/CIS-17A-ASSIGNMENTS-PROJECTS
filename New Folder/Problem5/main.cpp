/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 28, 2017, 8:22 PM
 */

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int fact = 1; //current factorial    
    const int SIZE = 2; // two arrays, the current value and the last value, last value if > overflowed
    unsigned int            i = 1; // The collection of numerous data types
             int            ii = 1; //
    unsigned short          s = 1; //
             short          ss = 1; //      //fact 0 = 1
    unsigned long           l = 1; //
             long           ll = 1; //
    unsigned long long      L = 1; //         //using this as a large data type accumulator
             long long      LL = 1; //
    
             float          ff = 1;
    
             double         dd = 1;
    
    long double             llD = 1;
    
    bool flag = true;      //flag for the while loop, breaks when largest factorial reached
    
    //temp double double variable for holding last value
    long double temp2 = 1;
    //temp long long for holding last variables value
        unsigned long temp = 1;
    
    //calculate the largest fact for each data type starting with int ,then unsigned int    
    while(flag)
    {
        i = L * fact;          
        
        
        //check if overflowed
        if(i < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = i;      
        
    }
    
    cout << "Largest factorial that can fit in a 4 byte int unsigned is !" << fact - 1 << endl;

    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //int
    while(flag)
    {
        ii = L * fact;       
        
        
        //check if overflowed
        if(ii < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = ii;      
        
    }
    
    cout << "Largest factorial that can fit in a 4 byte int signed is !" << fact - 1 << endl;
    
     //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //short unsigned
    while(flag)
    {
        s = L * fact;       
        
        
        //check if overflowed
        if(s < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = s;      
        
    }
    
    cout << "Largest factorial that can fit in a unsigned short!" << fact - 1 << endl;
    
     //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //short unsigned
    while(flag)
    {
        ss = L * fact;       
        
        
        //check if overflowed
        if(ss < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = ss;      
        
    }
    
    cout << "Largest factorial that can fit in a signed short! " << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //long long unsigned
    while(flag)
    {
        
        
        
        L = temp * fact;          
        
        
        //check if overflowed
        if(L < temp)
            flag = false;
        
        if(flag)           
            fact++;
        
        temp = L;      
        
    }
    
    cout << "Largest factorial that can fit in a unsigned long long!" << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    temp = 1;
    
    //long long signed
    while(flag)
    {
        LL = L * fact;              
        
        
        
        //check if overflowed
        if(LL < 0)
            flag = false;
        
        if(flag)           
            fact++;
        
        L = LL;      
        
    }
    
    cout << "Largest factorial that can fit in a signed long long !" << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //float
    while(flag)
    {
        ff = llD * fact;     
        
        
        
        //check if overflowed
        if(ff < llD * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        llD = ff;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a float is !" << fact - 1 << endl;    
    
     //reset for the next data type
    L = 1;
    llD = 1;
    flag = true;
    fact = 1;
    
    //double
    while(flag)
    {
        dd = llD * fact;     
        
        
        
        //check if overflowed
        if(dd < llD * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        llD = dd;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a double  is !" << fact - 1 << endl;    
    
    //reset for the next data type
    L = 1;
    llD = 1;
    flag = true;
    fact = 1;
    
    //double
    while(flag)
    {
        
        dd = temp2 * fact;     
        
        
        
        //check if overflowed
        if(dd < temp2 * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        temp2 = dd;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a long double is !" << fact - 1 << endl;    
    
    return 0;
}

