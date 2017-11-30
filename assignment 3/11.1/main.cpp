/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 5, 2017, 4:53 PM
 */


#include "Structs.h";

using namespace std;

//funct proto
void opt(Mvi *,Mvi *);//Simply outputs the information for each movie

/*
 * 
 */
int main(int argc, char** argv) {

    //the structs
    Mvi A;
    Mvi B;
    
    //prompt for the first film
    
    cout << "What is the name of the first film?.\n";
    getline(cin,A.title);
    
    cout << endl;
    
    cout << "What is the director of the first film?.\n";
    getline(cin,A.director);
    
    cout << "When was the first film released?\n";
    cin >> A.year;
    
    cout << endl;
    
    cout << "What is the runtime of the first film in minutes?.\n";
    cin >> A.runt;
    
    cout << endl << endl << endl;
    
    //clear buffer
    cin.ignore(1000,'\n');
    
    //prompt for the second film
    
    cout << "What is the name of the second film?.\n";
    getline(cin,B.title);
    
    cout << endl;
    
    cout << "What is the director of the second film?.\n";
    getline(cin,B.director);
    
    cout << "When was the second film released?\n";
    cin >> B.year;
    
    cout << endl;
    
    cout << "What is the runtime of the second film in minutes?.\n";
    cin >> B.runt;
    
    cout << endl << endl << endl;
    
    //call the function to output
    opt(&A,&B);
    return 0;
}

void opt(Mvi *A,Mvi *B)//Simply outputs the information for each movie
{
    cout << "The name of the first movie is " << (*A).title << ".\n";
    cout << "The direct of the first movie is " << (*A).director << ".\n";
    cout << "The year the first movie was released in " << (*A).year << ".\n";
    cout << "The runtime of the first movie is " << (*A).runt << ".\n\n\n";
    
    cout << "The name of the second movie is " << (*B).title << ".\n";
    cout << "The direct of the second movie is " << (*B).director << ".\n";
    cout << "The year the second movie was released in " << (*B).year << ".\n";
    cout << "The runtime of the second movie is " << (*B).runt << ".\n\n\n";
}