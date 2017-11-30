/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 28, 2017, 10:40 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "CustChk.h"
#include "Chk.h"
#include <cstring>

//prototypes
void problem1();
void problem2();
void problem4();
void problem5();
void problem6();
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int inN;
    
        do{
            cout << "Enter the value for the number set desired.\n";
            cout << "1 problem 1\n 2 problem 2\n 4 problem 4\n 5 problem 5\n 6 problem 6\n";
            cout << "Enter 8 or greater to exit.\n";
            cin >> inN;           
         
         switch(inN){
          case 1:    problem1();
                  break;
          case 2:    problem2();
          break;          
          case 4:    problem4();
          break;
          case 5:    problem5();
          break;
          case 6:    problem6();
          break;          
             
         }
        }while(inN<8);
    
    
    return 0;
}

void problem1(){
    
/* 
 * File:   problem 1
 * Author: Patrick
 *
 * Created on October 28, 2017, 11:22 AM
 */



/*
 * 
 */
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



}
void problem2(){
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
    
    //clear buffer
    cin.ignore(1000,'\n');
    
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
    
}
void problem4(){
    //variables
    const int SIZE = 5; //size of the encrypted number
    char num[SIZE];     //The 4 digit array
    bool error = false; //the error flag
    int temp;          //holds the integer value for the swap
    
    //clear buffer
    cin.ignore(1000,'\n');
    
    //prompt for the 4 digit number
    cout << "Please enter the 4 integers for encryption.\n";
    cin.get(num,5);    
    
    
    //check if the error occured
    for(int i = 0; i < SIZE-1; i++)
    {
        if((num[i] == '8' || num[i] == '9') && error == false)
        {
        cout << "An error has been flagged with this input. An 8 or 9 was entered.\n";
        error = true;
        }
    }
    
    //reset error for output
    error = false;
    
    //perform the encryption
    for(int i = 0; i < SIZE-1; i++)
    {
        //encrpt
        temp = num[i] - 48;
        temp += 5;
        temp = temp % 8;
        
        //assign
        num[i] = temp + 48;      
        
    }   
    
    //now do a swap for encryption
    temp = num[0];
    num[0] = num[2];
    num[2] = temp;
    temp = num[1];
    num[1] = num[3];
    num[3] = temp;
    
    //output the encrpted value, and check for output error
    //check if the error occured
    for(int i = 0; i < SIZE-1; i++)
    {
        if((num[i] == '8' || num[i] == '9') && error == false)
        cout << "An error has been flagged with the encrypted value. An 8 or 9 appeared.\n\n";
        error = true;
    }
    
    //reset error flag
    error = false;
    
    cout << "The encrypted value is " << num << endl << endl;
    
    //clear buffer
    cin.ignore(1000,'\n');
    
    //perform the decryption
    cout << "Please enter the value you would like to decrypt.\n";
    cin.get(num,5); 
    
    //check if the error occured
    for(int i = 0; i < SIZE; i++)
    {
        if((num[i] == '8' || num[i] == '9') && error == false)
        {
        cout << "An error has been flagged with this input. An 8 or 9 was entered.\n";
        error = true;
        }
    }
    
    //reset error for output
    error = false;
  
    //now do a swap for decryption
    temp = num[0];
    num[0] = num[2];
    num[2] = temp;
    temp = num[1];
    num[1] = num[3];
    num[3] = temp;    
    
    
    //Finish decryption
    for(int i = 0; i < SIZE-1; i++)
    {
        //decrypt
        temp = num[i] - 48;
        
        //check if modulus did nothing if does only -5, else add 8 - 5 to get original value
        if(temp == 6 || temp == 7)
        {
            temp -=5;
        }
        else
        {
            temp +=3;
        }
        
        //set for ascii
        temp+= 48;
        
        //assign
        num[i] = temp;      
        
    }   
    
    //check if the error occured
    for(int i = 0; i < SIZE-1; i++)
    {
        if((num[i] == '8' || num[i] == '9') && error == false)
        {
        cout << "An error has been flagged with the decrypted  value. An 8 or 9 appeared.\n\n";
        error = true;
        }
    }
    
    cout << "That value decrypted is " << num << endl;
    
    //reset error for output
    error = false;
    
    
    
    
    
}
void problem5(){
    //variables
    int fact = 1; //current factorial    
    const int SIZE = 2; // two arrays, the current value and the last value, last value if > overflowed
    unsigned int            i = 1; // The collection of numerous data types
             int            ii = 1; //
    unsigned short          s = 1; //
             short          ss = 1; //      //fact 0 = 1
    unsigned long           l = 1; //
             long           ll = 1; //
    unsigned long long      L = 1; //         //using this as a large data type accumulator
             long long      LL = 1; //
    
             float          ff = 1;
    
             double         dd = 1;
    
    long double             llD = 1;
    
    bool flag = true;      //flag for the while loop, breaks when largest factorial reached
    
    //temp double double variable for holding last value
    long double temp2 = 1;
    //temp long long for holding last variables value
        unsigned long temp = 1;
    
    //calculate the largest fact for each data type starting with int ,then unsigned int    
    while(flag)
    {
        i = L * fact;          
        
        
        //check if overflowed
        if(i < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = i;      
        
    }
    
    cout << "Largest factorial that can fit in a 4 byte int unsigned is !" << fact - 1 << endl;

    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //int
    while(flag)
    {
        ii = L * fact;       
        
        
        //check if overflowed
        if(ii < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = ii;      
        
    }
    
    cout << "Largest factorial that can fit in a 4 byte int signed is !" << fact - 1 << endl;
    
     //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //short unsigned
    while(flag)
    {
        s = L * fact;       
        
        
        //check if overflowed
        if(s < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = s;      
        
    }
    
    cout << "Largest factorial that can fit in a unsigned short!" << fact - 1 << endl;
    
     //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //short unsigned
    while(flag)
    {
        ss = L * fact;       
        
        
        //check if overflowed
        if(ss < (L * fact))
            flag = false;
        
        if(flag)           
            fact++;
        
        L = ss;      
        
    }
    
    cout << "Largest factorial that can fit in a signed short! " << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //long long unsigned
    while(flag)
    {
        
        
        
        L = temp * fact;          
        
        
        //check if overflowed
        if(L < temp)
            flag = false;
        
        if(flag)           
            fact++;
        
        temp = L;      
        
    }
    
    cout << "Largest factorial that can fit in a unsigned long long!" << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    temp = 1;
    
    //long long signed
    while(flag)
    {
        LL = L * fact;              
        
        
        
        //check if overflowed
        if(LL < 0)
            flag = false;
        
        if(flag)           
            fact++;
        
        L = LL;      
        
    }
    
    cout << "Largest factorial that can fit in a signed long long !" << fact - 1 << endl;
    
    //reset for the next data type
    L = 1;
    flag = true;
    fact = 1;
    
    //float
    while(flag)
    {
        ff = llD * fact;     
        
        
        
        //check if overflowed
        if(ff < llD * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        llD = ff;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a float is !" << fact - 1 << endl;    
    
     //reset for the next data type
    L = 1;
    llD = 1;
    flag = true;
    fact = 1;
    
    //double
    while(flag)
    {
        dd = llD * fact;     
        
        
        
        //check if overflowed
        if(dd < llD * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        llD = dd;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a double  is !" << fact - 1 << endl;    
    
    //reset for the next data type
    L = 1;
    llD = 1;
    flag = true;
    fact = 1;
    
    //double
    while(flag)
    {
        
        dd = temp2 * fact;     
        
        
        
        //check if overflowed
        if(dd < temp2 * fact)
            flag = false;
        
        if(flag)           
            fact++;
        
        temp2 = dd;     
        
             
        
    }
    
    cout << "Largest factorial that can fit in a long double is !" << fact - 1 << endl;    
    //clear buffer
    cin.ignore(1000,'\n');
    
    //pause    
    cout << "Press enter to continue.\n";
    cin.get();
    
}
void problem6()
{
    cout << "            a)                \n";
    
    cout << "2.875 as base 2  is 10.1110\n";
    cout << "2.875 as base 8  is 2.7\n";
    cout << "2.875 as base 16 is 2.14\n";
    
    cout << endl << "0.1796875 as base 16 is 0.214\n";
    cout <<         "0.1796875 as base 2  is 0.0010-1110\n";
    cout <<         "0.1796875 as base 8  is 0.134\n";
    
    
    
    //clear buffer
    cin.ignore(1000,'\n');
    
    //pause    
    cout << "Press enter to continue.\n";
    cin.get();

}

