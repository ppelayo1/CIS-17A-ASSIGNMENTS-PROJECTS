#include "preProc.h"
using namespace std;

/* Numbers array how it is set up
 
    [0] to [19] = zero to ninety
    [20] = Twenty
    [21] = Thirty
    [22] = forty
    [23] = fifty
    [24] = sixty
    [25] = seventy
    [26] = eighty
    [27] = ninety
    [28] = hundred
    [29] = thousand
 
 */
Numbers::Numbers(int n)
{
              number = n;
              
              
              
              
              numS[0] = "zero";
              numS[1] = "one";
              numS[2] = "Two";
              numS[3] = "Three";
              numS[4] = "Four";
              numS[5] = "Five";
              numS[6] = "six";
              numS[7] = "seven";
              numS[8] = "eight";
              numS[9] = "nine";
              numS[10] = "ten";
              numS[11] = "eleven";
              numS[12] = "twelve";
              numS[13] = "thirteen";
              numS[14] = "fourteen";
              numS[15] = "fifteen";
              numS[16] = "sixteen";
              numS[17] = "seventeen";
              numS[18] = "eighteen";
              numS[19] = "nineteen";
              numS[20] = "twenty";
              numS[21] = "thirty";
              numS[22] = "forty";
              numS[23] = "fifty";
              numS[24] = "sixty";
              numS[25] = "seventy";
              numS[26] = "eighty";
              numS[27] = "ninety";
              numS[28] = "hundred";
              numS[29] = "thousand";
    
    
}



void Numbers::toString()
{
    //variables
    int temp;
    int temp2;
    
  //thousands first
    if(number >= 1000 && number<= 9999)
    {
        
        cout << numS[number / 1000] << " " << numS[29] << " ";                        
    }
   
    temp = number;
    
    while(temp >= 1000)
    {
        temp-= 1000;
    }
    
    if(temp / 100 >= 1)
    {
        cout << numS[temp / 100] << " " << numS[28] << " ";
    }
    
    temp = number;
    
    while(temp >= 100)
    {
        temp-= 100;
    }
    
    if(temp > 19)
    {
        
        cout << numS[(temp / 10) + 18 ] << " ";
        temp2 = temp;
        
        while(temp2 >= 10)
        {
            temp2 -= 10;
        }
        
        if(temp2 > 0)
        {
            cout << numS[temp2] << " ";
        }
    }
    else{
        if(temp > 0)
        cout << numS[temp];
    }
    if(number == 0)
        cout << numS[0];
    
    
    
}