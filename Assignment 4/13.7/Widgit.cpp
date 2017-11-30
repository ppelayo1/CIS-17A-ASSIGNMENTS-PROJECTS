

//the class imp file for the Widget class
#include "PreProc.h"



Wid::Wid(int nW) //constructor
{
    //set up the variables
    this->dL = 16; //16 hours
    this->n  = 10; //10 widgets per hour
    this->nD = 0;  //Number of days to build the widgits
    
    
    
    //input validate then assign the value
    while(nW < 0)
    {
        cout << "The number of widgets must be zero or greater.\n";
        cout << "Please enter a new value.\n";
        cin >> nW;
    }
    this->nW = nW;
    
    //calculate the number of days
    calcD();
    
}

void Wid::calcD() //PRIVATE FUNCT
{
    //variable
    int bltWid = 0; //counter to keep track of the number of widgets build
    
    
    //calculate the number of days to produce a widget
    while(bltWid < nW)
    {
        
        for(int j = 0; j < dL; j++)
        {
            bltWid += n;
        }
        nD++;
            
    }
}
        
    


//accessors
int Wid::getNd()
{
    return nD;
}