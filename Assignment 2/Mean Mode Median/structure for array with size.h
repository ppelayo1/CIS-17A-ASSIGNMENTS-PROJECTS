/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structure for array with size.h
 * Author: Patrick
 *
 * Created on September 26, 2017, 4:52 PM
 */

#ifndef STRUCTURE_FOR_ARRAY_WITH_SIZE_H
#define STRUCTURE_FOR_ARRAY_WITH_SIZE_H

//this structure purpose is to be a package of both an array pointer and size
struct ModeAry{
    unsigned int *ptr = 0;// pointer to  a dynamic array
    int size;              //size of the dynamic array
    bool modeExist = false; //Flag of mode existence
};


#endif /* STRUCTURE_FOR_ARRAY_WITH_SIZE_H */

