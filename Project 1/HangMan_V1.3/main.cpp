

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
#include "InputW.h"
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//function prototypes
void disp(); //Display function, displays interface + instructions
bool disp(word *); //overloaded display function displays the game
void inp(word *); //Accepts a single character value from user
void build(word **, inputW *, int); //performs needed operations to build the word array
void inputF(inputW *);    //This function will access a file of hangman words and build it into arrays

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    word *hangMe;       //ptr to a dynamic array of the structure    
    bool gameOn = true;   //turns false when game over
    inputW input1;        //This is a single struct which will have a pointer pointing to dynamically created strings
    int index;            //This acts as the index for the input1 string arrays, it will hold a random array value
    
    //seed random gen
    srand(time(0));
    
    //call the input file function
    inputF(&input1);
    
    //determine the random word to utilize
    index = rand() % input1.size; 
    
    //build array
    build(&hangMe,&input1, index);       
    
    
    //run display functions
    disp();
    disp(hangMe);
    
    do
    {
        //call a get input function
        inp(hangMe);       

        //call the disp function again
        gameOn = disp(hangMe);          
        
        
        
    }
    while(gameOn == true);
    
    
    
    //clean up
    //delete [] input1.ptr;
    //delete [] hangMe->ptr;
    //delete [] hangMe->blnk;
    //delete [] hangMe->guess;
    //input1.ptr = 0;
    //hangMe->ptr = 0;
    //hangMe->blnk = 0;
    //hangMe->guess = 0;
    
    return 0;
}

void inputF(inputW *ptr)    //This function will access a file of hangman words and build it into arrays
{
    //variables
    fstream file; //the file object
    string  fileN; //Name of the file to open, also used to hold data temporarily for transfer    
    int count = 0; //A counter
    
    //prompt for the file name
    cout << "What is the name of the file you would like to open?\n";
    getline(cin,fileN);    
    
    
    //open object
    file.open(fileN.c_str());
    
    while(file.fail())
    {
        cout << "That is not a valid name, please enter a valid file name.\n";
        file.clear();
        
        //get file name
        getline(cin,fileN);       
    
        //open object
        file.open(fileN.c_str());
    }
    
    //get the number of lines present
    while(file >> fileN)
    {
        count++;
    }

    //go back to top / clear eof
    file.clear();
    file.seekg(0,file.beg);
    
    
    //the array of stream objects
    ptr->ptr = new string[count];
    
    //set the number of words present in the inputW object
    ptr->size = count;       
    
    
    //fill the 2d array
    for(int i = 0; file >> fileN; i++)
    {
        
        ptr->ptr[i] = fileN;
        
    }

    //cleanup
    file.close();

    
    
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
    bool gS = true; //return true if game is continuing or false to end game
    int index = 0; //an index counter
    
    //default hangman display, only when game has not ran once
    if(w->gameStart == false)
    {
        cout << setw(30) << "Hang Man\n\n";

        cout << setw(45) << "___________\n";
        cout << setw(33) << "|";
        cout << setw(13) << "|\n" << setw(46) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
        cout << setw(46) <<"|\n";
        cout << setw(46) <<"|\n";
        cout << setw(46) <<"|\n";

        cout << "The current word has " << w->length <<" characters.\n";
        cout << setw(35);
        for(int i = 0; i < w->length; i++)
        {
            cout << w->blnk[i];
        }
        cout << endl << endl;
    }
    
    //This if statement displays the game after the first run
    if(w->gameStart == true)
    {
        for(int i =0; i < w->length; i++)
        {
            if(toupper(w->guess[w->nGuess - 1]) == toupper(w->ptr[i]))            {
                
                w->blnk[i] = w->ptr[i];                
            }
            else
            {
                miss++;
            }
            
            
        }
        
        if(miss == w->length)
        {
            w->misses++;
        }
        
        //diplsays depending on number of misses, max misses is 12
        if(w->misses == 0)
        {
            //default hangman display
            cout << setw(30) << "Hang Man\n\n";

            cout << setw(45) << "___________\n";
            cout << setw(33) << "|";
            cout << setw(13) << "|\n" << setw(46) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";

            cout << "The current word has " << w->length <<" characters.\n";
            cout << setw(35);
            for(int i = 0; i < w->length; i++)
            {
                cout << w->blnk[i];
            }
            cout << endl << endl;
            
            cout << "Characters used " << setw(15) << w->guess << endl;
        }else
        {
            if(w->misses == 1)
            {
                // hangman display
            cout << setw(30) << "Hang Man\n\n";

            cout << setw(45) << "___________\n";
            cout << setw(33) << "|";
            cout << setw(13) << "|\n";
            cout << setw(31) << "(" << setw(15) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";
            cout << setw(46) <<"|\n";

            cout << "The current word has " << w->length <<" characters.\n";
            cout << setw(35);
            for(int i = 0; i < w->length; i++)
            {
                cout << w->blnk[i];
            }
            cout << endl << endl;
            
            cout << "Characters used " << setw(15) << w->guess << endl;
            }
            else
            {
                //2nd miss hang display
                if(w->misses == 2)
                {
                    // hangman display
                    cout << setw(30) << "Hang Man\n\n";

                    cout << setw(45) << "___________\n";
                    cout << setw(33) << "|";
                    cout << setw(13) << "|\n";
                    cout << setw(35) << "(   )" << setw(11) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
                    cout << setw(46) <<"|\n";
                    cout << setw(46) <<"|\n";
                    cout << setw(46) <<"|\n";

                    cout << "The current word has " << w->length <<" characters.\n";
                    cout << setw(35);
                    for(int i = 0; i < w->length; i++)
                    {
                        cout << w->blnk[i];
                    }
                    cout << endl << endl;

                    cout << "Characters used " << setw(15) << w->guess << endl;
                }else
                {
                    //3 misses display
                    if(w->misses == 3)
                    {
                            // hangman display
                        cout << setw(30) << "Hang Man\n\n";

                        cout << setw(45) << "___________\n";
                        cout << setw(33) << "|";
                        cout << setw(13) << "|\n";
                        cout << setw(35) << "(-  )" << setw(11) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
                        cout << setw(46) <<"|\n";
                        cout << setw(46) <<"|\n";
                        cout << setw(46) <<"|\n";

                        cout << "The current word has " << w->length <<" characters.\n";
                        cout << setw(35);
                        for(int i = 0; i < w->length; i++)
                        {
                            cout << w->blnk[i];
                        }
                        cout << endl << endl;

                        cout << "Characters used " << setw(15) << w->guess << endl;
                    }else
                    {
                        //fourth hanging
                        if(w->misses == 4)
                        {
                                    // hangman display
                            cout << setw(30) << "Hang Man\n\n";

                            cout << setw(45) << "___________\n";
                            cout << setw(33) << "|";
                            cout << setw(13) << "|\n";
                            cout << setw(35) << "(- -)" << setw(11) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
                            cout << setw(46) <<"|\n";
                            cout << setw(46) <<"|\n";
                            cout << setw(46) <<"|\n";
                            

                            cout << "The current word has " << w->length <<" characters.\n";
                            cout << setw(35);
                            for(int i = 0; i < w->length; i++)
                            {
                                cout << w->blnk[i];
                            }
                            cout << endl << endl;

                            cout << "Characters used " << setw(15) << w->guess << endl;      
                                                      
                            }else
                        {
                            //fifth hanging
                            if(w->misses == 5)
                            {
                                        // hangman display
                                cout << setw(30) << "Hang Man\n\n";

                                cout << setw(45) << "___________\n";
                                cout << setw(33) << "|";
                                cout << setw(13) << "|\n";
                                cout << setw(35) << "(-_-)" << setw(11) <<"|\n" << setw(46) <<  setw(46) << "|\n" << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";

                                cout << "The current word has " << w->length <<" characters.\n";
                                cout << setw(35);
                                for(int i = 0; i < w->length; i++)
                                {
                                    cout << w->blnk[i];
                                }
                                cout << endl << endl;

                                cout << "Characters used " << setw(15) << w->guess << endl;      

                                }else
                        {
                            //sixth hanging
                            if(w->misses == 6)
                            {
                                        // hangman display
                                cout << setw(30) << "Hang Man\n\n";

                                cout << setw(45) << "___________\n";
                                cout << setw(33) << "|";
                                cout << setw(13) << "|\n";
                                cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                cout << setw(33) << "|" << setw(13) << "|\n" << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";
                                cout << setw(46) <<"|\n";
                                
                                cout << "The current word has " << w->length <<" characters.\n";
                                cout << setw(35);
                                for(int i = 0; i < w->length; i++)
                                {
                                    cout << w->blnk[i];
                                }
                                cout << endl << endl;

                                cout << "Characters used " << setw(15) << w->guess << endl;    
                                
                            }else
                                {
                                    //seventh hanging
                                if(w->misses == 7)
                                {
                                            // hangman display
                                    cout << setw(30) << "Hang Man\n\n";

                                    cout << setw(45) << "___________\n";
                                    cout << setw(33) << "|";
                                    cout << setw(13) << "|\n";
                                    cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                    cout << setw(33) << "|" << setw(13) << "|\n";
                                    cout << setw(33) << "|" << setw(13) << "|\n" << setw(46) <<"|\n";
                                    cout << setw(46) <<"|\n";
                                    cout << setw(46) <<"|\n";
                                    
                                    
                                    cout << "The current word has " << w->length <<" characters.\n";
                                    cout << setw(35);
                                    for(int i = 0; i < w->length; i++)
                                    {
                                        cout << w->blnk[i];
                                    }
                                    cout << endl << endl;

                                    cout << "Characters used " << setw(15) << w->guess << endl;    

                                }
                                else
                                {
                                    //eighth handing
                                    if(w->misses == 8)
                                    {
                                                // hangman display
                                        cout << setw(30) << "Hang Man\n\n";

                                        cout << setw(45) << "___________\n";
                                        cout << setw(33) << "|";
                                        cout << setw(13) << "|\n";
                                        cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                        cout << setw(33) << "|" << setw(13) << "|\n";
                                        cout << setw(33) << "|" << setw(13) << "|\n";
                                        cout << setw(33) << "|" << setw(13) << "|\n" << setw(46) <<"|\n";
                                        cout << setw(46) <<"|\n";
                                        
                                        
                                        cout << "The current word has " << w->length <<" characters.\n";
                                        cout << setw(35);
                                        for(int i = 0; i < w->length; i++)
                                        {
                                            cout << w->blnk[i];
                                        }
                                        cout << endl << endl;

                                        cout << "Characters used " << setw(15) << w->guess << endl; 
                                    }
                                    else
                                    {
                                            //9th miss
                                            if(w->misses == 9)
                                            {
                                                        // hangman display
                                            cout << setw(30) << "Hang Man\n\n";

                                            cout << setw(45) << "___________\n";
                                            cout << setw(33) << "|";
                                            cout << setw(13) << "|\n";
                                            cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                            cout << setw(33) << "|" << setw(13) << "|\n";                                            
                                            cout << setw(33) << "--|" << setw(13) << "|\n";
                                            cout << setw(33) << "|" << setw(13) << "|\n" << setw(46) <<"|\n";
                                            cout << setw(46) <<"|\n";
                                            
                                            
                                            cout << "The current word has " << w->length <<" characters.\n";
                                            cout << setw(35);
                                            for(int i = 0; i < w->length; i++)
                                            {
                                                cout << w->blnk[i];
                                            }
                                            cout << endl << endl;

                                            cout << "Characters used " << setw(15) << w->guess << endl; 
                                            
                                        }
                                            else{
                                                //tenth miss
                                                if(w->misses == 10)
                                                {
                                                                        // hangman display
                                                    cout << setw(30) << "Hang Man\n\n";

                                                    cout << setw(45) << "___________\n";
                                                    cout << setw(33) << "|";
                                                    cout << setw(13) << "|\n";
                                                    cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                                    cout << setw(33) << "|" << setw(13) << "|\n";                                            
                                                    cout << setw(35) << "--|--" << setw(11) << "|\n";
                                                    cout << setw(33) << "|" << setw(13) << "|\n" << setw(46) <<"|\n";
                                                    cout << setw(46) <<"|\n";
                                                    
                                                    
                                                    
                                                    cout << "The current word has " << w->length <<" characters.\n";
                                                    cout << setw(35);
                                                    for(int i = 0; i < w->length; i++)
                                                    {
                                                        cout << w->blnk[i];
                                                    }
                                                    cout << endl << endl;

                                                    cout << "Characters used " << setw(15) << w->guess << endl; 
                                                }
                                                else
                                                {
                                                    //11th hanging occurs
                                                    if(w->misses == 11)
                                                    {
                                                                                    // hangman display
                                                        cout << setw(30) << "Hang Man\n\n";

                                                        cout << setw(45) << "___________\n";
                                                        cout << setw(33) << "|";
                                                        cout << setw(13) << "|\n";
                                                        cout << setw(35) << "(-_-)" << setw(11) <<"|\n" ;
                                                        cout << setw(33) << "|" << setw(13) << "|\n";                                            
                                                        cout << setw(35) << "--|--" << setw(11) << "|\n";
                                                        cout << setw(33) << "|" << setw(13) << "|\n";
                                                        cout << setw(32) << "|" << setw(14) << "|\n";        
                                                        cout << setw(46) <<"|\n";
                                                        
                                                        
                                                        
                                                        
                                                        cout << "The current word has " << w->length <<" characters.\n";
                                                        cout << setw(35);
                                                        for(int i = 0; i < w->length; i++)
                                                        {
                                                            cout << w->blnk[i];
                                                        }
                                                        cout << endl << endl;

                                                        cout << "Characters used " << setw(15) << w->guess << endl;                    
                                                        
                                                    }
                                                    else
                                                    {
                                                        //mans dead
                                                        if(w->misses == 12)
                                                        {
                                                                                            // hangman display
                                                            cout << setw(30) << "Hang Man\n\n";

                                                            cout << setw(45) << "___________\n";
                                                            cout << setw(33) << "|";
                                                            cout << setw(13) << "|\n";
                                                            cout << setw(35) << "(x_x)" << setw(11) <<"|\n" ;
                                                            cout << setw(33) << "|" << setw(13) << "|\n";                                            
                                                            cout << setw(35) << "--|--" << setw(11) << "|\n";
                                                            cout << setw(33) << "|" << setw(13) << "|\n";
                                                            cout << setw(34) << "| |" << setw(12) << "|\n";     
                                                            cout << setw(46) <<"|\n";




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
                                                }
                                            }
                                    }
                                }
                            }
                        }
                        }
                    }
                    
                }
            }
        }      
    }      
    
    
    
    for(int i = 0; w->blnk[i] == w->ptr[i] && i < w->length; i++)
    {        
        //if i is same as the length and this loop ran the strings are identical
        if(i == w->length - 1 )
        {
            cout << "The game has been won.\n";
            gS = false;
        }
    }
    
    //once the maxinum misses allowed reach return false
    if(w->misses == 12)
    {
        cout << "The game has been lost.\n";
        gS = false;
        
        cout << "The word was " << w->ptr << endl;
    }
    
    
    
    //set gamestatus as true to indicate the first run is complete
    w->gameStart = true;
    
    //debug 
      //  cout << "Word is " << w->ptr << endl;
    
    return gS;
    
}



void build(word **w, inputW *input1, int index)
{
    //variables
    int length = input1->ptr[index].length(); //length of the string
    
    //Create the array assign its string lenghts and the string itself
    *w = new word;
    (*w)->ptr = new char[length];
    (*w)->blnk = new char[length];
    (*w)->length = length;    
    (*w)->guess = new char[length];    
    input1->ptr[index].copy((*w)->ptr,length,0);
    cout << "The length is " << length;
    
    //throw a null on the end
    (*w)->ptr[length] = '\0';
    
    cout << "The string being used is "<< (*w)->ptr << endl;
    
        
    
        
        
    //perform conversion for the blank array
    for(int i =0; i < (*w)->length; i++)
    {
        (*w)->blnk[i] = '-';
    }
    //assign a null char
    (*w)->blnk[(*w)->length] = '\0';
    
    
    
    
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
