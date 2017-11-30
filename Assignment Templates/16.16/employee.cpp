
#include "preProc.h"

Employee::Employee(string s,int eN,string eI) 
{
    try{
        
        if(eN < 0 || eN > 9999)
            throw InvalidEmployeeNumber();
    
        name = s;
        empNum = eN; 
        empHD = eI;

    }
    catch(Employee::InvalidEmployeeNumber){
        cout << "Employee number is not acceptable, program terminated.";
        exit(EXIT_FAILURE);
        
    }
}

void Employee::setEmpNum(int eN) 
{
    try{
        
        if(eN < 0 || eN > 9999)
            throw InvalidEmployeeNumber();
        
        empNum = eN;


    }
    catch(Employee::InvalidEmployeeNumber){
        cout << "Employee number is not acceptable, program terminated.";
        exit(EXIT_FAILURE);
        
    }
}