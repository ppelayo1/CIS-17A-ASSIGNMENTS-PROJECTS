/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 28, 2017, 12:45 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Chk.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const short DBBL = 30; //lower thresshold of double time(do not include 30th hour)
    const short TRP =  50; //lower thresshold of triple time(do not incldue 50th hour).
    int size; //number of employees, user choice
    const int nWord = 33; //Number of elements in the character array representing strings of numbers
    const int wSZE = 30;
    string comp;//name
    string add; //address of the compayn
    Emp *ptr; //pointer to the array of employees
    int temp; //for temporary uses thru program
    int temp2; //for temporary storage
    float cvt; //used to convert from dollars to cents and store as int
    
    
    //2d array to represent words which represent numbers
    char num[nWord][wSZE] = 
                            /*   [0]    [1]      [2]     [3]      [4]       [5]*/
                            {{"Zero"},{"One"},{"Two"},{"Three"},{"Four"},{"Five"},
                            /*   [6]    [7]      [8]     [9]      [10]       [11]*/
                             {"Six"},{"Seven"},{"Eight"},{"Nine"},{"Ten"},{"Eleven"},
                            /*   [12]    [13]           [14]         [15]       [16]       [17]*/
                             {"Twelve"},{"Thirteen"},{"Fourteen"},{"Fifteen"},{"Sixteen"},{"Seventeen"},
                            /*  [18]          [19]        [20]       [21]      [22]       [23]*/
                             {"Eighteen"},{"Nineteen"},{"Twenty"},{"Thirty"},{"Forty"},{"Fifty"},
                            /*   [24      [25]        [26]       [27]       [28]       [29]*/
                             {"Sixty"},{"Seventy"},{"Eighty"},{"Ninety"},{"Hundred"},{"Thousand"},
                            /* [30]    [31]        [32]     */
                             {"and"}, {"Cents"},{"Dollar/s"}};   
    
    
    
    
    //get company name/address
    cout <<"Please enter the name of the company.\n";
    getline(cin,comp);
    
    
    cout <<"Please enter the address of the company.\n";
    getline(cin,add);
    
    //prompt for number of employees
    cout << "Please enter the number of employees on payroll to enter.\n";
    cin >> size;
    
    //input validate
    while(cin.fail() || size <= 0)
    {
        //clear junk then get new input
        cin.clear(); //reset flags
        cin.sync();  //clear stream
        
        cout << "That is not valid input, please enter the number of employees for the payroll.\n";
        cin >> size;
    }
    
    //create the dynamic struct
    ptr = new Emp[size];
    
    //loop through all the accounts to get input
    for(int i =0; i < size; i++)
    {
        //need to clear buffer bcuz of cin
        cin.ignore(1000,'\n'); 
        
        //get the name
        cout << "What is the name of the employee " << i+1 <<"?\n";
        getline(cin,ptr[i].name);       
        
        //get the account info,must validate input
        do
        {
            cout << "Please enter the rate of pay for " << ptr[i].name << ".\n";
            cout << "It must be a positive number only.\n";
            cin >> ptr[i].rPay;
            
            //clear if cin error occurs
            if(cin.fail())
            {
                cin.clear(); //clear the flags
                cin.sync();  //clear the buffer
            }
            
        }while(ptr[i].rPay < 1);
        
        //get the account info,must validate input
        do
        {
            cout << "Please enter the number of hours worked by " << ptr[i].name << ".\n";
            cout << "It must be a postiive number.\n";
            cin >> ptr[i].hours;
            
            //clear if cin error occurs
            if(cin.fail())
            {
                cin.clear(); //clear the flags
                cin.sync();  //clear the buffer
            }
            
        }while(ptr[i].hours < 1);
        
        //calculate the gross pay
        if(ptr[i].hours >= DBBL)
        {
            ptr[i].gPay += DBBL * ptr[i].rPay;
            if(ptr[i].hours >= TRP)
            {
                ptr[i].gPay+= 2 * ptr[i].rPay * (TRP-DBBL);
                ptr[i].gPay+= 3 * ptr[i].rPay * (ptr[i].hours - TRP);          
                
            }
            else
            {
                ptr[i].gPay += 2 * ptr[i].rPay * (ptr[i].hours - DBBL);
            }
            
        }
        else
        {
            ptr[i].gPay += ptr[i].rPay * ptr[i].hours;
        }                
        
        
        //convert the gross pay into integers
        temp = ptr[i].gPay;
        cvt = ptr[i].gPay;
        
        //turn cents into int values
        cvt -= temp;
        cvt *= 100; //converts the cents to int type values
        temp2 = cvt;
        
        
        //output the check
        cout << right << comp << endl;
        cout << add << endl;
        cout << "Name:"<< ptr[i].name <<  setw(15) << fixed << "Amount:" << "$" <<temp << "." << setfill('0') << setw(2) << temp2 << endl;
        cout << "Amount:";
        
        //if blocks section to print out the numerical value as a word.
        //check for thousands and output if found
        if(ptr[i].gPay >= 1000)
        {
            cout << num[static_cast<int>(ptr[i].gPay / 1000)] <<" " << num[29];
            
        }
        
        
        
        //output the hundreds
        if((ptr[i].gPay)/100 >= 1)
        {
            temp = ptr[i].gPay/100;
            //minus 10 from the temp each time until a hundred is found or not
            while(temp >= 10)
            {
                temp-=10;
            }
            
            //output the hundred value value only when between hundred and nine hundred
            if(temp >0 && temp < 9)            
            cout << " " << num[temp] << " " << num[28];
        }
        
        
        
        //determine if their are dollars present
        temp = ptr[i].gPay;      
        
        
        //subtract off the thousands and hundreds until only dollars remain
        while(temp >= 1000)        {
            
            temp -= 1000;
            
            
        }
               
       
        while(temp >= 100)
        {
            temp -= 100;
            
        }

        
        //backup temp
        temp2 = temp;     
        
        

        //if the value is between 1-20 it can be outputed directly
        if(temp >=1 && temp <= 21)
        {
            cout << " " << num[temp];
        }
        
        

        //the element 20-27 represent the tens from twenty to ninety in the 
        //num array
        //this if is checking for when temp is 21 or greater
        if(temp>20)
        {   //need to make the tens into a single digit
            if(temp > 10)
            {
                temp /=10;
            }
            //set the temp to the tens element by adding 18
            temp+= 18;                   


            //determine the single dollar amounts and output it
            while(temp2 > 9)
            {
                temp2-=10;
            }
            
            // output the tens and dollar ammounts
            //output the tens dollar amount                    
            cout << " " << num[temp] << " " << num[temp2];
            
            
            


        }

    
            
        //output dollars
        cout << " " << num[32];
        
        
        
        //
        //do the cents now
        //
        //
        //convert the dollars into cents
        temp = ptr[i].gPay;
        cvt = ptr[i].gPay;
        
        //turn cents into int values
        cvt -= temp;
        cvt *= 100; //converts the cents to int type values
        //assign it to an integer to truncate the decimals
        temp = cvt;
        
        //now output the cent values
        cout << " " << num[30];
        
        //if the value is between 1-20 it can be outputed directly
        if(temp >=1 && temp <= 21)
        {
            cout << " " << num[temp] << " " << num[31];
        }
        


           /*reused code to find the dollar amount, being used to find the cent ammounts*/

        //backup temp
        temp2 = temp;        
         
        
        //the element 20-27 represent the tens from twenty to ninety in the 
        //num array
        //this if is checking for when temp is 21 or greater
        if(temp>20)
        {   //need to make the tens into a single digit
            if(temp > 10)
            {
                temp /=10;
            }
            //set the temp to the tens element by adding 18
            temp+= 18;                   


            //determine the single dollar amounts and output it
            while(temp2 > 9)
            {
                temp2-=10;
            }            
           
            // output the tens and dollar ammounts
            //output the tens dollar amount                    
            cout << " " << num[temp] << " " << num[temp2] << " " << num[31] << endl;
           
           
            
            


        } //account for zero cents
        if(temp == 0)
        {
            cout << " " << num[temp] << " " << num[31] << endl;
        }
        
        
        cout << endl << setfill(' ') << setw(16) << "Signature:\n";
        
    }
    
   
    
    //free memory
    delete [] ptr;
    ptr = 0;
    
    return 0;
}
