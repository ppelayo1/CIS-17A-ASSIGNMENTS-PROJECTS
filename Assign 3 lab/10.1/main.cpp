/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 12:29 PM
 */

#include <iostream>
#include <cstring>
using namespace std;

//funct prototypes
int len(char []); //counts characters in a string
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 100;  
    char str[SIZE];
    
    cout << "Enter the string that you would like to know the number of characters including blank space that exists." << endl;
    cin.getline(str,SIZE);
    
    cout << "The number of characters in that string is " << len(str) <<".";

    return 0;
}

int len(char str[]) //counts characters in a string
{
    return strlen(str);
}
