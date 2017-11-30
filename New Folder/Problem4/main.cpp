/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 28, 2017, 7:38 PM
 */

#include <cstring>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 5; //size of the encrypted number
    char num[SIZE];     //The 4 digit array
    bool error = false; //the error flag
    int temp;          //holds the integer value for the swap
    
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
    
    
    
    
    
    return 0;
}

