#include "preProc.h"


ProductionWorker::ProductionWorker(string s,int eN,string eI, int shf, float pR) : Employee(s,eN,eI)
    {
    try
        {
        if(shf != 1 && shf != 2)
            throw InvalidShift();
        if(pR < 0)
            throw InvalidPayRate();
        
        
        
        
            shift = shf;
            payR = pR;
        }
    
     catch(ProductionWorker::InvalidPayRate)
    {
         cout << "Payrate is not acceptable, program terminated.";
         exit(EXIT_FAILURE);
    }   
    
    catch(ProductionWorker::InvalidShift)
    {
         cout << "Shift is not acceptable, program terminated.";
         exit(EXIT_FAILURE);
    }   
   }       

void ProductionWorker::setShift(int s) 
{
    try{
        

        if(s != 1 && s != 2)
                throw InvalidShift();

        shift = s;
    
    }
    
    catch(ProductionWorker::InvalidShift)
    {
         cout << "Shift is not acceptable, program terminated.";
         exit(EXIT_FAILURE);
    }   
}




void ProductionWorker::setPayR(float pR) 
{
    
    try{
        
        if(pR < 0)
            throw InvalidPayRate();
        
        
       payR = pR;
       
       
    }
    
    catch(ProductionWorker::InvalidPayRate)
    {
         cout << "Payrate is not acceptable, program terminated.";
         exit(EXIT_FAILURE);
    }   
    
}