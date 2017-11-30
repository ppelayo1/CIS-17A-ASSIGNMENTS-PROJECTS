


//This is a structure that has a pointer to a word for the hangman game,and the size of that word in the size variable
#ifndef WORDS_H
#define WORDS_H

struct word{
   char *ptr;  //ptr to that word
   int  length;  //this is the length of the word
   char *blnk; //blank array same size as the word, it will be compared to the word
   int nGuess = 0; //number of guesses currently made
   bool gameStart = false; //gamestart Status
   char *guess; //array to store the attempted guesses by the user
   int misses = 0; //the number of misses so far, keeps track of the hanged man graphic
    
};

#endif /* WORDS_H */

