/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on September 14, 2017, 11:49 AM
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    short size = 3;      //size of time array
    string name1;  //name of a racer
    string name2;  //name of a racer
    string name3;  //name of a racer
    int i = 0;     //current index of time array
    int time[size];   // time of racers
    
    
    //prompt for names and race times    
    //racer 1
    cout << "What is the racer's name?\n";
    getline(cin,name1);    
        
    cout << left << setw(20)<< "What is the time of" << name1 << right << setw(13) << "in seconds?\n" << left;    
    cin >> time[i];
    
  
    
    while (time[i] <= 0)
    {
        cout << setw(48) << "The time must be a number greater then zero for" << name1 << endl << endl;
        
         cout << left << setw(20)<< "What is the time of" << name1 << right << setw(13) << "in seconds?\n" << left;    
        cin >> time[i];
        cout << endl;
    }
    
    //flush buffer
    cin.ignore(1000,'\n');
    
    //inc index
    i++;
    
    //racer 2
    cout << "What is the racer's name?\n";
    getline(cin,name2);
    
    cout << left << setw(20)<< "What is the time of" << name2 << right << setw(13) << "in seconds?\n" << left;    
    cin >> time[i];
    
  
    
    while (time[i] <= 0)
    {
        cout << setw(48) << "The time must be a number greater then zero for" << name2 << endl << endl;
                
         cout << left << setw(20)<< "What is the time of" << name2 << right << setw(13) << "in seconds?\n" << left;    
        cin >> time[i];
        cout << endl;
    }
    
    //flush buffer
    cin.ignore(1000,'\n');
    
    //inc index
    i++;
    
    //racer 3    
    cout << "What is the racer's name?\n";
    getline(cin,name3);
    
    cout << left << setw(20)<< "What is the time of" << name3 << right << setw(13) << "in seconds?\n" << left;    
    cin >> time[i];
    
  
    
    while (time[i] <= 0)
    {
        cout << setw(48) << "The time must be a number greater then zero for" << name3 << endl << endl;
        
         cout << left << setw(20)<< "What is the time of" << name3 << right << setw(13) << "in seconds?\n" << left;    
        cin >> time[i];
        cout << endl;
    }

    
    //determine who is first , second, last and output
    if (time[0] < time[1] && time[1] < time[2]) 
        {
        cout << setw(24) <<  "The first place goes to" << name1 << endl;
        cout << setw(25) <<  "The second place goes to" <<name2 << endl;
        cout << setw(25) <<  "The third  place goes to" << name3 << endl;        
        }
    else
    {
        if(time[0] < time[2] && time[2] < time[1])
        {
        cout << setw(24) <<  "The first place goes to" << name1 << endl;
        cout << setw(25) <<  "The second place goes to" <<name3 << endl;
        cout << setw(25) <<  "The third  place goes to" << name2 << endl;  
        }
            else
            {
                if(time[1] < time[0] && time[0] < time[2])
                {
            cout << setw(24) <<  "The first place goes to" << name2 << endl;
            cout << setw(25) <<  "The second place goes to" <<name1 << endl;
            cout << setw(25) <<  "The third  place goes to" << name3 << endl;  
                }
                  else
                 {
                    if(time[1] < time[2] && time[2] < time[0])
                    {
                    cout << setw(24) <<  "The first place goes to" << name2 << endl;
                    cout << setw(25) <<  "The second place goes to" <<name3 << endl;
                    cout << setw(25) <<  "The third  place goes to" << name1 << endl;  
                    }
                        else
                        {
                            if(time[2] < time[0] && time[0] < time[1])
                            {
                            cout << setw(24) <<  "The first place goes to" << name3 << endl;
                            cout << setw(25) <<  "The second place goes to" <<name1 << endl;
                            cout << setw(25) <<  "The third  place goes to" << name2 << endl;  
                            }
                                else
                                {
                                   if(time[2] < time[1] && time[1] < time[0])
                                   {
                                   cout << setw(24) <<  "The first place goes to" << name3 << endl;
                                   cout << setw(25) <<  "The second place goes to" <<name2 << endl;
                                   cout << setw(25) <<  "The third  place goes to" << name1 << endl;  
                                   }
                               }
                        }
                }
            }
    }
    return 0;
}