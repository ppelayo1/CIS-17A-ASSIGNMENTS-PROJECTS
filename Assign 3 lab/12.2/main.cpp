/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 6:46 PM
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    fstream file;//file object
    string name; //file name and holds input data
    int counter = 0; //counter for formating
    int index = 0;   //format counter
    int pause = 24; //Line to pause at
    cout << "Enter the file name to open.\n";
    getline(cin,name);
    
    file.open(name.c_str());
    
    //get data and output it
    if(!file.fail())
    {
        while(getline(file,name))
        {
            counter++;
            index++;
            cout << index << ") ";
            cout << name << endl;
            
            if(counter == pause)
            {
                cout << "Press enter to continue.\n";
                cin.get();
                counter = 0;
            }
        }
    }
    
    
    file.close();
    return 0;
}

