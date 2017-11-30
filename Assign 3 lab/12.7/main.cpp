/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 12:45 PM
 */


#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables    
    const int ELEM = 0; //element to switch to upper case.
    string fNamein; //name of file to open also used for storing the file info temporarily for transfer
    string fNameO;  //name of file to read to
    
    
    fstream inp; //input file object
    fstream out; //output file object
    
    //prompt and open ingoing file 
    cout << "Enter the file you would like to open.\n";
    getline(cin,fNamein); 
    inp.open(fNamein.c_str(), ios::in);
    
    
    //input validation
    while(inp.fail())
    {
        cout << "That file does not exist, please enter an acceptable file name.\n";
        inp.clear();
        
        cout << "Enter the file you would like to open.\n";
        getline(cin,fNamein);   
        inp.open(fNamein.c_str(), ios::in);
    }
    
    //prompt and open outgoing file name
    cout << "Enter the output file and first characters of sentences will become higher case, all other characters small.\n";
    getline(cin,fNameO);
    out.open(fNameO.c_str(),  ios::out);
    
    //get first line and store it
    getline(inp,fNamein);   
    
    
    //perform the operation of transfering input to output and changing cases
    while(inp)
    {
        if (fNamein[ELEM] > 96 && fNamein[ELEM] < 123)
        {
            fNamein[ELEM] -= 32;
        }
        for(int i = 1; i < fNamein.length(); i++)
        {
            if(fNamein[i] < 91 && fNamein[i] > 64)
            {
                fNamein[i] += 32;
            }
            
        }
        
        //write to the file
        out << fNamein;
        //get next line
        getline(inp,fNamein);
        if(inp)
            out << endl;
        
    }

    
    //close out the files
    inp.close();
    out.close();
    
  
    
    return 0;
}

