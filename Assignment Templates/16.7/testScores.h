/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testScores.h
 * Author: Patrick
 *
 * Created on November 27, 2017, 6:08 PM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

template <class T>
class TestScores{
private:
   T *aptr;
   int size;
   
public:
   TestScores( T [] ,int);
   T mean(); //returns the mean average 
    
   //exception class
   class scrOutR{}; //thrown if score out of range
    
};

#endif /* TESTSCORES_H */

template <class T>
TestScores<T>::TestScores( T array[] ,int sz)
{
    
    size = sz;
    aptr = array;   
    
}
template <class T>
T TestScores<T>::mean(){
    T sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(aptr[i] > 100 || aptr[i] < 0)
            throw scrOutR();
        sum+= aptr[i];
        
    }
    
    return sum / size;
    
    
}
