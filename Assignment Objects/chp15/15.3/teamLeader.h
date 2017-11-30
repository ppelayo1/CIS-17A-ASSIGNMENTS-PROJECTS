/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teamleader.h
 * Author: Patrick
 *
 * Created on November 16, 2017, 6:57 PM
 */

#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "preProc.h"
using namespace std;

class TeamLeader : public ProductionWorker{
    private:
        float bonus;
        int reqHours;
        int hoursAtnd;
        
    public:
        TeamLeader(float bon,int rH,int hA,string s,int eN,string eI, int shf, float pR) : ProductionWorker(s,eN,eI,shf,pR)
        { bonus = bon; reqHours = rH; hoursAtnd = hA;}
        
       float getBonus() {return bonus;}
        int getReqHours() {return reqHours;}
        int getHoursAtnd() {return hoursAtnd;}
                  
        void setBonus(float b) {bonus = b;} 
        void setReqHours(int r) {reqHours = r;}
        void setHoursAtnd(int h) {hoursAtnd = h;}
        
};

#endif /* TEAMLEADER_H */

