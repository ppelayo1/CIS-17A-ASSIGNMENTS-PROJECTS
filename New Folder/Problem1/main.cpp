
/* 
 * File:   problem 1
 * Author: Patrick
 *
 * Created on October 28, 2017, 11:22 AM
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "CustChk.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int size; //This will be by user choice the number of customers to be inputed
    CBnkC *ptr; //this is a pointer to the dynamically created checking structure
    const short OVERD = 15;//the fee for overdrawing the account   
    char x; //exits the loop for withdrawls/deposits
    float temp; //holds the deposit/withdrawl value temporarily for input validation
    int count = 0; //a loop control counter
    bool flag; //This is only set to false when stream fails in the deposit/withdrawl loops
    
    //prompt for the number of customers to be calculated
    cout << "How many customer's bank accounts would you like to enter and calculate?.\n";
    cin >> size;
    
    //input validate
    while(cin.fail() || size <= 0)
    {
        //clear junk then get new input
        cin.clear(); //reset flags
        cin.sync();  //clear stream
        
        cout << "That is not valid input, please enter the number of customers.\n";
        cin >> size;
    }
    
    //build the checking array
    ptr = new CBnkC[size];    
   
    
    //loop through all the accounts to get input
    for(int i =0; i < size; i++)
    {
        //need to clear buffer bcuz of cin
        cin.ignore(1000,'\n'); 
        
        //get the name,address
        cout << "What is the name of customer " << i+1 <<"?\n";
        getline(cin,ptr[i].name);
        
        cout << "What is the address for " << ptr[i].name <<"?\n";
        getline(cin,ptr[i].address);
        
        //get the account info,must validate input
        do
        {
            cout << "Please enter the account number for " << ptr[i].name << ".\n";
            cout << "It must be a positive five digit number only.\n";
            cin >> ptr[i].acct;
            
            //clear if cin error occurs
            if(cin.fail())
            {
                cin.clear(); //clear the flags
                cin.sync();  //clear the buffer
            }
            
        }while(ptr[i].acct < 10000 || ptr[i].acct > 99999);
        
        //user chose if has input to add
        cout << "If you have any checks to add to this account enter 'x', else anything else to skip.\n";
        cin >> x;
        
        //need to now accumulate all withdrawls and desposits
        while(x == 'x' || x =='X')
        {
            //add one to the counter
            count++;
            
            do
            {
                //set flag
                flag = true;
                cout << "Please enter the value for check " << count << ".\n";
                cout << "Must be 0 or greater(0 if you made mistake and did not want to add).\n";
                cin >> temp;
                
                //clear if cin error occurs
                if(cin.fail())
                {
                    cin.clear(); //clear the flags
                    cin.sync();  //clear the buffer
                    flag = false;
                }                
            }while(temp < 0 || flag == false);
            //assign the temp value to the array
            ptr[i].chks += temp;           
            
            //user chose if has input to add
            cout << "If you have any more checks to add to this account enter 'x', else anything else move on.\n";
            cin >> x;
            
            
        }
        
        
        
        /************************************************************************/
        /*This does the same thing as the top code but does it for the deposits*/
        /************************************************************************/
        
        //reset the counter
        count = 0;
        
         //user chose if has input to add
        cout << "If you have any deposits to add to this account enter 'x', else anything else to skip.\n";
        cin >> x;
        
        //need to now accumulate all withdrawls and desposits
        while(x == 'x' || x =='X')
        {
            //add one to the counter
            count++;
            
            do
            {
                //set flag
                flag = true;
                cout << "Please enter the value for check " << count << ".\n";
                cout << "Must be 0 or greater(0 if you made mistake and did not want to add).\n";
                cin >> temp;
                
                //clear if cin error occurs
                if(cin.fail())
                {
                    cin.clear(); //clear the flags
                    cin.sync();  //clear the buffer
                    flag = false;
                }                
            }while(temp < 0 || flag == false);
            //assign the temp value to the array
            ptr[i].dep += temp;           
            
            //user chose if has input to add
            cout << "If you have any more checks to add to this account enter 'x', else anything else move on.\n";
            cin >> x;
            
            
        }
        
        //calculate the end of month balance
        ptr[i].bal = ptr[i].dep - ptr[i].chks;
        
        //if negative add a overdraft fee and tell user
        if(ptr[i].bal < 0)
        {
            ptr[i].bal -= OVERD;
            cout << endl << endl;
            cout << "An overdraft fee has been applied to this account.\n";
            cout << "That fee is $" << OVERD <<" and will be added to the total balance.\n\n";
        }
        
        //output the information for this customer
        cout << right;
        cout << setw(25) << "ACCOUNT SUMMARY\n";
        cout << setw(25) << left << "Name:" << ptr[i].name << endl;
        cout << setw(25)<< "Address:" << ptr[i].address << endl;
        cout << setw(25) << "Account #:" << ptr[i].acct << endl;
        cout << setw(25) << "Accnt Bal :" << fixed << setprecision(2) << "$" << ptr[i].bal << endl;
        cout << setw(25) << "Ttl deposit val:" << fixed << setprecision(2) << "$" << ptr[i].dep << endl;
        cout << setw(25) << "Ttl check val:" << fixed << setprecision(2) << "$" << ptr[i].chks << endl;
        cout << endl;
        
        cout << "Press enter to continue.";
        
        //continue at user input        
        cin.get();
        
        
    }
    
    
    
    
    //free the memory
    delete [] ptr;
    ptr = 0;
    
    
    //DONT FORGET TO REMOVE WHEN PLACED INTO THE MIDERTERM COMPILATION PROJECT FOLDER
    return 0;
}

