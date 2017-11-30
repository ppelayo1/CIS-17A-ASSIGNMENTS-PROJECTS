/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   intArray.h
 * Author: Patrick
 *
 * Created on November 26, 2017, 9:36 PM
 */

#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
    int *aptr;
    int arraySize;
    void subscriptError();
public:
    IntArray(int);
    IntArray(const IntArray &);
    ~IntArray();
    
    int size() const
        { return arraySize;}
    
    int &operator[](const int &);
    
    //exemption class
    class outOfRange {};
};


#endif /* INTARRAY_H */

