
#include "PreProc.h"
using namespace std;


RetailItem::RetailItem(string d, int u, float p)
{
    desc = d;
    
    while (u < 0)
    {
        cout << "The number of units must be 0 or greater\n";
        cin >> u;
        cin.ignore(1000,'\n');       
        
    }
    uOnH = u;
    
    while (p < 0)
    {
        cout << "The price must be 0 or greater.\n";
        cin >> p;
        cin.ignore(1000,'\n');
        
        
    }
    price = p;    
    
}
       
    
    
    void RetailItem::setuOnH(int u)
    {
        while (u < 0)
    {
        cout << "The number of units must be 0 or greater\n";
        cin >> u;
        cin.ignore(1000,'\n');       
        
    }
    uOnH = u;        
        
    }
    
    
    void RetailItem::setPrice(float p)
    {
        
        while (p < 0)
    {
        cout << "The price must be 0 or greater.\n";
        cin >> p;
        cin.ignore(1000,'\n');
        
        
    }
    price = p;    
        
        
        
    }
    
    
    
     