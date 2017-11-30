/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simpleVector.h
 * Author: Patrick
 *
 * Created on November 27, 2017, 6:42 PM
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector
{
    private:
        T *aptr;        
        int arraySize;
        void memError();
        void subError();
        
    public:
        SimpleVector()
        {aptr = 0; arraySize = 0;}
        
        SimpleVector(int);
        
        SimpleVector(const SimpleVector &);
        
        ~SimpleVector();
        
        int size() const {return arraySize;}
        
        T getElementAt (int position);
        
        T &operator[] (const int &);
    
        void push_back(T);
    
        T pop_back();
};

#endif /* SIMPLEVECTOR_H */


template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    
    aptr = new T [arraySize];
    if(aptr == 0)
        memError();
    
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

template <class T>
void SimpleVector<T>::memError()
{
    cout << "Error:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if(sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template <class T>
T &SimpleVector<T>::operator [](const int &sub)
{
    if(sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template <class T>
void SimpleVector<T>::push_back(T value)
{
    //add one to the size of array, build a temp array 1 size larger to hold val
    arraySize++;
    T *temp;
    try
    {
    temp = new T[arraySize];
    }
    catch(bad_alloc)
    {
        memError();
    }
    
    //attach data to the new array, and add last value
    for(int i =0; i < (arraySize - 1); i++)
    {
        temp[i] = aptr[i];
    }
    
    temp[arraySize - 1] = value;
    
    //delete old array and point the ptr to the new array
    delete [] aptr;
    aptr = temp;
    temp = 0;
    
}

template <class T>
T SimpleVector<T>::pop_back()
{
    T value = aptr[arraySize - 1]; //to hold for return
    
    //remove one to the size of array, build a temp array 1 size less
    arraySize--;
    T *temp;
    try
    {
    temp = new T[arraySize];
    }
    catch(bad_alloc)
    {
        memError();
    }
    
    //attach data to the new array, and add last value
    for(int i =0; i < arraySize; i++)
    {
        temp[i] = aptr[i];
    }
    
    //delete old array and point the ptr to the new array
    delete [] aptr;
    aptr = temp;
    temp = 0;
    
    return value;
}