



//The inventory class impl file
#include "PreProc.h"
//constructor
Inv::Inv(int iNum,int quan,float cost)
{
    //perform input validations then assign values
    while(iNum < 0)
    {
        cout << "Inventory number can not be negative, enter 0 or a positive number.\n";
        cin >> iNum;
    }
    this->iNum = iNum;
    
    while(quan < 0)
    {
        cout << "Quanity can not be negative, enter 0 or a positive number.\n";
        cin >> quan;
    }
    this->quan = quan;
    
    while(cost < 0)
    {
        cout << "Cost can not be negative, enter 0 or a positive number.\n";
        cin >> cost;
    }
    this->cost = cost;
    
    //call the set ttlcst function to calculate and set the total cost
     setTtlCst();
}
    
//mutators
void Inv::setInum(int iNum)
{
    //perform input validations then assign values
    while(iNum < 0)
    {
        cout << "Inventory number can not be negative, enter 0 or a positive number.\n";
        cin >> iNum;
    }
    this->iNum = iNum;
}
void Inv::setQuan(int quan)
{
    //perform input validations then assign values
    while(quan < 0)
    {
        cout << "Quanity can not be negative, enter 0 or a positive number.\n";
        cin >> quan;
    }
    this->quan = quan;
    
    //call the set ttlcst function to calculate and set the total cost
     setTtlCst();
}
void Inv::setCost(float cost)
{
    //perform input validations then assign values
    while(cost < 0)
    {
        cout << "Cost can not be negative, enter 0 or a positive number.\n";
        cin >> cost;
    }
    this->cost = cost; 
    
    
    //call the set ttlcst function to calculate and set the total cost
     setTtlCst();
}

void Inv::setTtlCst()    // THIS IS PRIVATE
{
    //calculate the ttl cst assign it
    ttlCst = quan*cost;    
}

//getters
int Inv::getInum()
{
    return iNum;
}
int Inv::getQuan()
{
    return quan;
}
float Inv::getCost()
{
    return cost;
}
float Inv::getTtlCst()
{
    return ttlCst;
}