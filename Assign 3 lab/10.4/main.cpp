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
int len(char [], int); //accepts a string array and returns average length of each word
/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE = 100; //lenght of the string
    char s[SIZE];   //string
    
    cout << "Please enter the sentence you would like to know the average number of letters in words are.\n";
    cin.getline(s,SIZE);
    
    cout << "The average number of letters per word is " << len(s, SIZE) << ".";
    
    
    return 0;
}
int len(char s[], int size)
{
    int words =0;  //number of words
    int lett  = 0; //number of letters
    
    for(int i =0; i < strlen(s)+1; i++)
    {
        
        if(s[i] != ' ' && s[i] != '\0')
        {
            lett++;;
        }
        else
        {
            if((s[i] == ' ' && s[i + 1] != ' ' || s[i] == '\0'))
                words++;
        }
    }
    
    return lett/words;
}
