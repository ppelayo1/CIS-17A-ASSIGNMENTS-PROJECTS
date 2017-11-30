/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 1:51 PM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
//funct prototypes
void arrayToFile(std::string ,int [], int); //takes an array and copies its contents to a file
void fileToArray(std::string ,int [], int); //takes a file and pulls its data from binary to the array


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    string name = "default.bin"; //file name
    int SIZE = 15; //size of array
    int arry[50]; //array    
    
    srand(time(0)); //seed
    
    cout << "Values in the array are.\n";
    
    // populate array and output contents
    for (int i = 0; i < SIZE; i++)
    {
        arry[i] = rand();
        cout << arry[i] << " ";
        
        if (i == 9 || i == 19 || i == 29 || i == 39)
            cout << endl;
    }
    
    //write file
    arrayToFile(name,arry,SIZE);
    
    cout << "\nFile was created.\n";
    cout << "Array is now filled with this. \n";
    
    //clear the array to 0
     for (int i = 0; i < SIZE; i++)
    {
        arry[i] = 0;
        cout << arry[i] << " ";
        
        if (i == 9 || i == 19 || i == 29 || i == 39)
            cout << endl;
    }
    
    //read from file
    fileToArray(name,arry,SIZE);
    
    cout << "\nThe file has been read from.\nThe array is now filled with this.\n";
     //clear the array to 0
     for (int i = 0; i < SIZE; i++)
    {        
        cout << arry[i] << " ";
        
        if (i == 9 || i == 19 || i == 29 || i == 39)
            cout << endl;
    }
    return 0;
}


void arrayToFile(std::string name ,int arry[], int size) //takes an array and copies its contents to a file
{
    //variables
    fstream out;//the outbound object
    
    out.open(name.c_str(),ios::out | ios::binary); 
    
    out.write(reinterpret_cast<char *>(arry),size*sizeof(arry));
    
    out.close();
}

void fileToArray(std::string name ,int arry[], int size) //takes a file and pulls its data from binary to the array
{
    //variables
    fstream in; //inbound file object    
 
    in.open(name.c_str(), ios::in | ios::binary);
    
    in.read(reinterpret_cast<char *>(arry),size*sizeof(arry));
    
    in.close();
}