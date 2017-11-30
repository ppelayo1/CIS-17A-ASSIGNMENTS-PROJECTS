/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on October 10, 2017, 12:08 PM
 */

#include <iostream>
#include <cstring>
using namespace std;


//funct proto
int len(char [], int); //accepts a string array and returns length of words
/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE = 100; //lenght of the string
    char s[SIZE];   //string
    
    cout << "Please enter the sentence you would like to know the number of words of.\n";
    cin.getline(s,SIZE);
    
    cout << "The number of words of what you typed is " << len(s, SIZE) << ".";
    
    
    return 0;
}
int len(char s[], int size)
{
   

    int words =0;  //number of words    
    
    for(int i =0; i < strlen(s); i++)
    {
        
        
        
            if((s[i] == ' ' && s[i + 1] != ' ' || s[i+1] == '\0') && i != 0)
                words++;
        
    }
    
    
    return words;
}


