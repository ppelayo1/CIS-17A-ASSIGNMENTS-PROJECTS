/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 10, 2017, 12:39 PM
 */

#include <cstring>
#include <iostream>
using namespace std;

//proto functions
void menu(char [], int); //builds the menu
int  con(char [], int);  //coutns the constants returns as int
int  vow(char [], int);  // counts the vowels returns as int
/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE = 200;
    char  s[SIZE];
    
    menu(s,SIZE);
    

    return 0;
}

void menu(char s[], int size) //builds the menu
{
    char e = '0'; //the exit character
    bool flag = false; //flag for first buffer clear
    int vo = 0;   //number of vowels
    int co = 0;   //number of constants
    //prompt for the intial string
    cout << "What string would you like to enter?\n";
    cin.getline(s,size);
    
    //the menu
    do
    {
        cout << "A) Count the number of vowels in the string.\n";
        cout << "B) Count the number of constants in the string.\n";
        cout << "C) Count both the vowels and constants in the string.\n";
        cout << "D) Enter another string.\n";
        cout << "E) Exit the program.\n";
        
        
        
        //get input
        cin >> e;
        
        
        switch (e)
        {
            case 'A' :
            case 'a' :
                cout << "The number of vowels is " << vow(s,size) << ".\n";
                break;
            case 'B' :
            case 'b' :
                cout << "The number of constants is " << con(s,size) << ".\n";
                break;
            case 'C' :
            case 'c':
                cout << "Both vowels and constants add up to " << con(s,size) + vow(s,size) <<".\n";
                break;
            case 'd':
            case 'D':
                cout << "Please enter the new string.\n";  
                cin.ignore(1000,'\n');
                cin.getline(s,size);  
                cout << "\n\n\n\n";
                break;
            case 'E':
            case 'e':                
                cout <<"Good bye";
                flag = true;
                break;
            default :
                cout << "That is invalid input.\n\n";
                
                
        }                      
        
    }while (flag == false);
    
}

int  con(char s[], int size)  //coutns the constants returns as int
{
    int co = 0;
    //calculat the constants
    for (int i = 0; i < size && s[i] != '\0'; i++ )
    {
        if (s[i] != 'a'         &&  s[i] != 'A' &&  s[i] != 'e' &&  s[i] != 'E' && 
            s[i] != 'i'         &&  s[i] != 'I' &&  s[i] != 'o' &&  s[i] != 'O' && 
            s[i] != 'U'         &&  s[i] != 'u' && (s[i] > 65 && s[i] < 122))        
            co++;        
    }
    
    return co;
    
}
int  vow(char s[], int size)  // counts the vowels returns as int
{
    int vo = 0; //number of vowels
    
    //calculat the vowels
    for (int i = 0; i < size && s[i] != '\0'; i++ )
    {
        if (s[i] == 'a'         || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i'         || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'U'         || s[i] == 'u')
            vo++;        
    }
    
    
    return vo;
}