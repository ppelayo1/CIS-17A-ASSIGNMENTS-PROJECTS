/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 12:33 PM
 */

#include <iostream>
#include <cstring>
using namespace std;

//funct prototypes
void rev(char []); //displays a string backwards
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE = 100;  
    char str[SIZE];
    
    cout << "Enter the string that you would like to see printed backwards." << endl;
    cin.getline(str,SIZE);
    
    rev(str);

    return 0;
}

void rev(char str[]) //counts characters in a string
{
    
    for(int i = strlen(str); i >= 0; i--)
    {
        cout << str[i];
    }
}
