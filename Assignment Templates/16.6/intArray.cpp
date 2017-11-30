#include <iostream>
#include <cstdlib>
#include "intArray.h"
using namespace std;



IntArray::IntArray(int s)
{
    arraySize = s;
    aptr = new int [s];
    for(int count =0; count <arraySize; count++)
        *(aptr + count) = 0;
    
    
}

IntArray::IntArray(const IntArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new int [arraySize];
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
    
    
}

IntArray::~IntArray()
{
    if (arraySize > 0)
        delete [] aptr;
}

void IntArray::subscriptError(){
    
    throw outOfRange();
}

int &IntArray::operator [](const int &sub)
{
    if(sub < 0 || sub >= arraySize)
        subscriptError();
    return aptr[sub];
}