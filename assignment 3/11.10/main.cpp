/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick Pelayo
 *
 * Created on October 2, 2017, 12:47 PM
 */

#include "Structure.h"
#include "PreProp.h"

//function proto
void SOut(SpkB *,std::string, int); //searches for a string then outputs found speaker

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int size;   //size of dynamic array
    short inp = 0; //controls the switch
    int elem = 0;   //current element active in switch
    string tpc;     //a topic to search for
    
    //prompt user for the number of records
    cout << "How many records of speakers would you like to enter?\n";
    cin  >> size;
    
    //input validate
    while (size < 1)
    {
        cout << "There muse be at least one record to be entered.\n\n";
        
        //prompt user for the number of records
        cout << "How many records of speakers would you like to enter?\n";
        cin  >> size;
    }
    
    //create the array
    SpkB *dataB = new SpkB[size];
    
    
    cout << "You will now have " << size << " speakers for the data base.\n\n";
    
    //collect data for the speakers
    for(int i =0; i < size; i++)
    {
        
        getline(cin,dataB[i].name);           
        
        cout << "Please enter the name for speaker " << i+1 << ".\n";
        getline(cin,dataB[i].name);       
        
        cout << "Please enter the phone number.\n";
        cin >> dataB[i].tele;
        cin.ignore(1000,'\n');
        
        cout <<"Please enter that speaker's topic.\n";
        getline(cin,dataB[i].spk_top);  
        
        
        cout <<"Please enter that speakers fee, it must be zero or greater.\n";
        cin >> dataB[i].fee;
        
        while(dataB[i].fee < 0)
        {
            cout << "The fee must be zero or greater.\n\n";
            cout <<"Please enter that speakers fee, it must be zero or greater.\n";
            cin >> dataB[i].fee;
        }        
    }
    
    //menu
    do
    {        
        
        cout << endl << endl;
        cout << "Currently speaker " << elem+1 << " is active.\n";
        cout << "Enter 1" << " To change the speaker's name.\n";
        cout << "Enter 2" << " To change the speaker's telephone number.\n";
        cout << "Enter 3" << " To change the speaker's fee.\n";
        cout << "Enter 4" << " To change the speaker's topic.\n";
        cout << "Enter 5" << " To view information on the current record " << elem+1 << endl;
        cout << "Enter 6" << " To search by topic for a speaker.\n";
        cout << "Enter 0" << " To change to a different stored record.\n";
        cout << "Enter -1" << " When you are finished with the program.\n";
        
        cout << endl;
        cin >> inp;       
        
        cin.ignore(1000,'\n');

        switch(inp){
            case 1 :
                cout << "Please enter the name for the speaker.\n";
                getline(cin,dataB[elem].name);    
                
                break;
            case 2 :
                cout << "Please enter the phone number.\n";
                getline(cin,dataB[elem].tele);
                
                break;
            case 3 :
                cout <<"Please enter the speakers fee, it must be zero or greater.\n";
                cin >> dataB[elem].fee;

                while(dataB[elem].fee < 0)
                {
                    cout << "The fee must be zero or greater.\n\n";
                    cout <<"Please enter that speakers fee, it must be zero or greater.\n";
                    cin >> dataB[elem].fee;
                }   
                break;
            case 4 :
                cout <<"Please enter that speaker's topic.\n";
                getline(cin,dataB[elem].spk_top); 
                
            case 5 :
                cout << "The name of the current speaker is " <<  dataB[elem].name <<".\n";
                cout << "The phone number is " << dataB[elem].tele << ".\n";
                cout << "The fee is " << dataB[elem].fee << ".\n";
                cout << "The topic of the current speaker is " <<  dataB[elem].spk_top <<".\n";
                break;
            case 6:
                cout << "Please enter a topic(case sensitive), the speaker will be searched for.\n";
                getline(cin,tpc); 
                SOut(dataB,tpc,size);
                break;                        
            case 0 :
                cout << "Enter the numerical value of the record you would like to go to.\n";
                cin  >> elem;
                elem--;

                while (elem < 0 || elem >= size)
                {
                    cout << "That record does not exist. \n\n";
                    cout << "Enter the numerical value of the record you would like to go to.\n";
                    cin  >> elem;
                    elem--;
                }
                break;
            case -1 :            
                break;

            default:
                cout << "You did not enter a valid option.\n\n";

        }
            
    
    }while(inp != -1);
    
    
    
    
    //free mem
    delete [] dataB;
    dataB = 0;
    
    
    return 0;
}

//searches for a string then outputs found speaker
void SOut(SpkB *array,std::string topic, int size)
{
    bool found = false; //flag for no speaker found
    int count = 1;      //counter for current speaker
    
    //search the array for the topic and output the found speakers
    for (int i = 0; i < size; i++)
    {
        if(array[i].spk_top==topic)
        {
            if(found == false)
            {
                cout << "The name of the speakers with that topic are.\n";
                found = true;
            }
            
            cout << count << ") " << array[i].name << " and is speaker #" << i + 1 << "." << endl;
            count++;
        }
    }
    
    //if none are found output appropriatly
    if (found == false)
    {
        cout << "No speakers with that topic were found.\n";
    }
}
