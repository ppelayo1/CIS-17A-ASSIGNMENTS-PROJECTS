/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 5, 2017, 5:41 PM
 */

#include "Preproc.h";

//funct prototype
void inp(Soc [], short); //This function gets the input for the soccer team
int  hSre(Soc [], short); //find the highest scoring player and returns their element
void out(Soc [], short); //Prints out the info on the team
/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const short SIZE = 12;
    Soc team[SIZE];
    
    //call input funct
    inp(team,SIZE);    
    
    //call the output funct
    out(team,SIZE);
    
    return 0;
}

void inp(Soc team[], short size) //This function gets the input for the soccer team
{
    //get the data for each soccer player
    for(int i =0; i < size; i++)
    {
        cout << "What is the name of player " << i+1 <<"?\n";
        getline(cin,team[i].name);
        
        cout <<"What is the number of the player. Note any negative number will convert to positive.\n";
        cin >> team[i].numP;
        if(team[i].numP < 0)
            team[i].numP*= -1;
        
        cout << "What are the current points scored by that player? Negative numbers will convert to positive.\n";
        cin >> team[i].pts;
        if(team[i].pts < 0)
            team[i].pts*= -1;
        
        //clear buffer
        cin.ignore(1000,'\n');
    }
}

int  hSre(Soc team[], short size) //find the highest scoring player and returns their element
{
    //variables
    int hElem = 0; //current highest scored element
    
    for(int i = 1; i<size; i++)
    {
        if (team[i].pts > team[hElem].pts)
        {
            hElem = i;
        }
    }
    
    return hElem;
}

void out(Soc team[], short size) //Prints out the info on the team
{
    //variables
    int hElem; //highest scoring player element
    int sum = 0; //sum for the average
    //call function to get the highest scoring player elem
    hElem = hSre(team,size);
    
    //output the player table
    for (int i =0; i < size; i++)
    {
        cout << "Player:" << setw(20) << team[i].name << " Number:" << setw(10) << team[i].numP << setw(10) << " Score:" << team[i].pts << endl;
        sum += team[i].pts;
    }
    
    //output the average score
    cout << "The average score of the team is " << sum/size << endl;
    cout << "The player with the highest score was " << team[hElem].name << " with the number " << team[hElem].numP <<".\n\n";
        
}