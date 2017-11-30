#include "preProc.h"
using namespace std;

 char Essay::getLetterGrade() const
{
     if(score > 89)
         return 'A';
     if(score > 79 && score < 90 )
         return 'B';
     if(score > 69 && score < 80)
         return 'C';
     if(score > 59 && score < 70)
         return 'D';
     
     return 'F';
}

 Essay::Essay(float g,float s ,float cL,float cnt)
 {    
     //set the score maxinum by category
     gramPts = 30; 
     spellPts = 20; 
     corLPts = 20; 
     contPts = 30;
     
     while(g < 0 || g > gramPts)
     {
         cout << "The score for grammar must be between 0 and 30.\n";
         cin >> g;
     }
     
     while(s < 0 || s > spellPts)
     {
         cout << "The score for spelling must be between 0 and 20.\n";
         cin >> s;
     }
     
     while(cL < 0 || cL > corLPts)
     {
         cout << "The score for the length must be between 0 and 20.\n";
         cin >> cL;
     }
     
     while(cnt < 0 || cnt > contPts)
     {
         cout << "The score for content must be between 0 and 30.\n";
         cin >> cnt;
     }
     
     //sum up the scores then set them
     score = g+s+cL + cnt;     
     
     
 }