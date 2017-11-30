

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * 
 * HangMan Game V1.0
 * 
 * Created on October 31, 2017, 11:08 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Words.h"
#include <string>
using namespace std;

//function prototypes
void disp(); //Display function, displays interface + instructions
bool disp(word *); //overloaded display function displays the game
void inp(word *); //Accepts a single character value from user
void build(word **,int ); //performs needed operations to build the word array
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    word *driver;       //ptr to a dynamic array of the structure
    const int SIZE = 1000; //temporary size value
    bool gameOn = true;   //turns false when game over
    //build array
    build(&driver,SIZE);   
    
    cout << "Nguess before doing anything is " << driver->nGuess << endl;
    
    //run display functions
    disp();
    disp(driver);
    
    do
    {
        //call a get input function
        inp(driver);
        
        cout << driver->misses << "Misses recorded" << endl;
        cout << "Stored in the length variable is " << driver->length << endl;
        cout << "Value in the nGuess variable is " << driver->nGuess << endl;

        //call the disp function again
        disp(driver);    
    }
    while(gameOn == true);
    
    return 0;
}

void disp()
{
    //display instructions to user
    cout << "Welcome to the game of Hangman.\n";
    cout << "The goal of the game is to guess the word, and avoid having a man drawn that is being hanged. You may guess a single character. If that character is in the word it will be displayed.\n";
    cout << "If that character does not exist the man being hanged will have a body part drawn.";
    cout << "You may guess the word itself but if that is wrong two body parts is drawn.\n\n";
    cout << "When the word is guessed you win, if the man is drawn you lose.\n\n";
    
    
    
}

bool disp(word *w)
{
    //variables
    int miss = 0; //keeps track of number of misses each for loop. If misses == strnlen then nothing hit
    
    //default hangman display
    cout << setw(30) << "Hang Man\n\n";
    
    cout << setw(45) << "___________\n";
    cout << setw(33) << "|";
    cout << setw(13) << "|\n" << setw(46) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
    
    
    cout << "The current word has " << w->length <<" characters.\n";
    cout << setw(35);
    for(int i = 0; i < w->length; i++)
    {
        cout << w->blnk[i];
    }
    cout << endl << endl;
    
    if(w->gameStart == true && w->misses == 0)
    {
        for(int i =0; i < w->length; i++)
        {
            if(toupper(w->guess[w->nGuess - 1]) == toupper(w->ptr[i]))
            {
                cout << "IF STATMENT RAN " << endl <<endl;
                w->blnk[i] = w->ptr[i];                
            }
            else
            {
                miss++;
            }
            
            cout << "Number of misses " << miss << endl;
        }
        
        if(miss == w->length)
        {
            w->misses++;
        }
        
        if(w->misses == 0)
        {
            //default hangman display
            cout << setw(30) << "Hang Man\n\n";

            cout << setw(45) << "___________\n";
            cout << setw(33) << "|";
            cout << setw(13) << "|\n" << setw(46) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";


            cout << "The current word has " << w->length <<" characters.\n";
            cout << setw(35);
            for(int i = 0; i < w->length; i++)
            {
                cout << w->blnk[i];
            }
            cout << endl << endl;
            
            cout << "Characters used " << setw(15) << w->guess << endl;
        }
    }
    
    //set gamestatus as true to indicate the first run is complete
    w->gameStart = true;
    
    return true;
    
}



void build(word **w,int s)
{
    //temporary version 1 created array
    *w = new word;
    (*w)->ptr = new char[s];
    (*w)->blnk = new char[s];
    
    string cow = "Cow";
    
    cow.copy((*w)->ptr,cow.length(),0);   
    (*w)->ptr[3] = '\0';
    
    cout << endl << endl << cow.length() << "    ELGNTH OF COW " << endl << endl;
    
    (*w)->length = strlen((*w)->ptr);
    
    
    
    //perform conversion for the blank array
    for(int i =0; i < (*w)->length; i++)
    {
        (*w)->blnk[i] = '-';
    }
    //assign a null char
    (*w)->blnk[(*w)->length] = '\0';
    
    //build the guess array in the struct
    (*w)->guess = new char[s];    
    
    
}

void inp(word *w)
{
    cout << "Please enter a single character(case does not matter)\n";
    cin.get(w->guess[w->nGuess]);
    w->nGuess++;    
    w->guess[w->nGuess] = '\0';

    //clear buffer
    cin.ignore(1000,'\n');
    
}
