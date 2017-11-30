/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 5:51 PM
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables    
    fstream file; //file object
    string data; //holds the ten objects
    int count = 0;  //keep track of input grabbed
    string name;   //name of file
    
    //prompt for file name
    cout << "Enter a name of file.\n";
    getline(cin,name);
    
    
    //open the file
    file.open(name.c_str());
    
    if(!file.fail())
    {
        
        cout << "The data in the  first 10 lines of the text file is.\n";
        
        while(file >> data && count < 10)
         {            
            cout << data << endl;
            count++;
        };
    
        
        
        
    }else
        cout << "Error file does not exist program terminated.";
    file.close();
    
    return 0;
}

