/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 12, 2017, 4:03 PM
 */

#include <iostream>
#include <string>
#include "Struct.h"
#include <fstream>
using namespace std;

//funct proto
void inp(Division [] , int);//gets the input for the division
void out(Division [],  std::string, int); //outputs to a file
void in(Division [], std::string , int);   //reads in a file and outputs the data read in
//global constants
const int QUARTERS = 4; //number of quarters in a year

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int SIZE = 4; //number of divisions
    Division div[SIZE]; //The four divisions
    string name;  //name of output file  
    
    
    //initialize data
    div[0].name = "North";
    div[1].name = "South";
    div[2].name = "West";
    div[3].name = "East";    
    
    
    for (int i = 0; i <SIZE; i++)
    {
        int q = 1;
        for (int j = 0; j <QUARTERS; j++)
        {
            div[i].qtr[j] = q; 
            q++;
        }
    }
    
    //call the input function
    inp(div,SIZE);
    
    //get output file name
    cout << "Enter the name of the file you wish to read to.\n";
    getline(cin,name);
    
    
    
    //write out to
    out(div,name, SIZE);
    
    //read in
    in(div,name, SIZE);
    
    return 0;
}

//funct proto
void inp(Division data[] , int size)//gets the input for the division
{
    
    
    //prompt and fill the the divison info
    for (int i = 0; i < size; i++)
    {
        for(int j =0; j < QUARTERS ; j++)
        {
            cout << "Please enter the sales for " << data[i].name <<" division quarter " << data[i].qtr[j] << ".\n";
            cin >> data[i].sale[j];
            
            //input validate
            while (data[i].sale[j] < 0)
            {
                cout << "The sale must be zero or greater.\n\n";
                cout << "Please enter the sales for " << data[i].name <<" division quarter " << data[i].qtr[j] << ".\n";
                cin >> data[i].sale[j];               
            }
            
        }
        
        //assign the data size 
            data[i].dataSize = sizeof(data[i].qtr) + sizeof(data[i].sale) + sizeof(data[i].dataSize) + data[i].name.length() + 1;
            
        
        
    }
    //clear buffer
    cin.ignore(1000,'\n');
}

void out(Division div[], std::string name , int size) //outputs to a file
{
    //variables
    fstream out; //output file
    int sizeTTL = 0; //total data size of the div array
    
    //calculate total size of data
    for(int i = 0; i < size; i++)
    {
        sizeTTL += div[i].dataSize;
    }
    
    out.open(name.c_str(), ios::out | ios::binary);
    
    //write out
    out.write(reinterpret_cast<char *>(div),sizeTTL);
    
    out.close();
}

void in(Division div[], string name, int size)   //reads in a file and outputs the data read in
{
    fstream in;//input file
    int sizeTTL = 0;
    
    
    //calculate total size of data
    for(int i = 0; i < size; i++)
    {
        sizeTTL += div[i].dataSize;
    }
    
    //read in the file
    in.open(name.c_str(), ios::in | ios::binary);
    in.read(reinterpret_cast<char *>(div), sizeTTL );
    
    //output the file info
    for(int i = 0; i < size; i++)
    {
        
        cout << "Division " << div[i].name  << endl;
        for (int j =0; j < QUARTERS; j++)
        {
            
            cout << "Quarter " << div[i].qtr[j] << endl;
            cout << "Sales "   << div[i].sale[j] << endl;
            
        }
        cout << endl << endl;
    }
    
    
}