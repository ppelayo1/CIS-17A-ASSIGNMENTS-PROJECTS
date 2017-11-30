/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on November 16, 2017, 5:18 PM
 */

#include "preProc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//variables
    float grammar;
    float spelling;
    float lenCorrect;
    float content;
    
    cout << "What was the grammar score 0-30.\n";
    cin >> grammar;
    
    cout << "What was the spelling score 0-20.\n";
    cin >> spelling;
    
    cout << "What was the score for the length 0-20.\n";
    cin >> lenCorrect;
    
    cout << "What was the content score 0-30.\n";
    cin >> content;
    
    Essay objOne(grammar,spelling,lenCorrect,content);
    
    cout << "The total score is " << objOne.getScore() << " with a grade of " << objOne.getLetterGrade() <<".\n"; 
    
    
    
    return 0;
}

