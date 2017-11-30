

//This structure will hold a size and a pointer to a collection of hangman words
#ifndef INPUTW_H
#define INPUTW_H

struct inputW
{
    std::string *ptr = 0;   //Points to an array of strings (2D array))
    int size = 0; //The number of words read in from an input file    
    
};


#endif /* INPUTW_H */

