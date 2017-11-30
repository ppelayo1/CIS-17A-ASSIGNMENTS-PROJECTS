/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   essay.h
 * Author: Patrick
 *
 * Created on November 16, 2017, 5:26 PM
 */

#ifndef ESSAY_H
#define ESSAY_H

#include "preProc.h"

class Essay : public GradedActivity{
    private:
        int gramPts;
        int spellPts; 
        int corLPts;
        int contPts; 
        
    public:        
        Essay(float ,float  ,float ,float );
        
        
        
        char getLetterGrade() const;
};


#endif /* ESSAY_H */

