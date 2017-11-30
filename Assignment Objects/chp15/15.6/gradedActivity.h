/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gradedActivity.h
 * Author: Patrick
 *
 * Created on November 16, 2017, 5:23 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

#include "preProc.h"

class GradedActivity{
protected:
    float score;

    GradedActivity()
    {
        score = 0.0;
    }
    
    GradedActivity (float s)
    {
        score = s;
    }

    void setScore(float s)
    {
        score = s;
    }   
    
    virtual char getLetterGrade() const = 0;
    
public:
    float getScore()
    {
        return score;
    }
    
};

#endif /* GRADEDACTIVITY_H */

 