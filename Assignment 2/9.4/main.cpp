/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 24, 2017, 5:36 PM
 */

#include <iostream>
#include <iomanip>
#include <string>

//function prototypes
void  crtArry(short **ptr, std::string **names, int size); //creates the array
void  dstry(short **ptr,std::string **names); //frees memory
void  sort(short **ptr, std::string **names, int size); //sorts the array
short avg(short **ptr, int size);  //calculate the average score and return it
void getScrs(short **ptr, std::string **names, int size); //get the user scores
void outpt(short **ptr,std::string **names, int size, short avg); //output formated info
using namespace std;

/*
 *  
 */

int main(int argc, char** argv) {
    //variables
    int size; //size of array
    short *score = 0; //ptr to the scores dynamically created
    string *names = 0; //ptr to the names of students
    int avgScr; //Avg score
    
    //prompt for number of tests
    cout << "How many tests would you like to enter?\n";
    cin >> size;
    
    //input validation
    while (size < 1)
    {
        cout << "The number of students for scores to be entered must be 1 or more.\n\n";
        
        cout << "How many students would you like to enter?\n";
        cin >> size;
    }
    
    //create the array
     crtArry(&score,&names,size);
    
    
    
    //get the scores
    getScrs(&score, &names, size);   
    
    //sort the scores
    sort(&score,&names, size);
    
    //caclulate the avg score
    avgScr = avg(&score,size);
    
    //output the info
    outpt(&score, &names,size,avgScr);
            
    //free the memory
    dstry(&score,&names);      
    
    
    return 0;
}


//clean up the memory
void  dstry(short **ptr, string **names)
{
    delete [] *ptr;
    *ptr = 0;   
    
    delete [] *names;
    *names =0;
}

//user inputs the scores thru this function
void getScrs(short **ptr, string **names, int size)
{
    //get the scores
    for(int i = 0; i < size; i++)
    {
        //clear buffer
        cin.ignore(1000,'\n');
        
        cout << "Please enter name for the student.\n";
        getline(cin,*(*names+i));
        
        cout << "Please enter the score for that student.\n";
        cin >> *(*ptr+i);
        
        //input validate
        while(*(*ptr+i) < 0 || *(*ptr+i) > 100)
        {
            cout << "The a test score must be between 0 and 100.\n\n";
            
            cout << "Please enter the score for the student.\n";
            cin >> *(*ptr+i);
            
        }        
        
    }
}

//sort the array from smallest to largest
void  sort(short **ptr, string **names, int size)
{
    //variables
    short temp; //for the swap
    string temp2;
    
    for(int i = 0; i < size; i++)
    {
        for (int j=i; j < size; j++)
        if (*(*ptr+i) > *(*ptr+j))
        {
            temp = *(*ptr+j);
            *(*ptr+j) = *(*ptr + i);
            *(*ptr+i) = temp;     
            
            temp2 = *(*names+j);
            *(*names+j) = *(*names + i);
            *(*names+i) = temp2;  
        }
        
    }    
}

//calculates and returns the average score
short avg(short **ptr, int size) 
{
    //variables
    int sum = 0;
    
    for (int i =0; i< size; i++)
    {
        sum += *(*ptr+i);
    }
    
    //return avg
    return sum/size;
    
}

//outputs the info formated
void outpt(short **ptr,string **names, int size, short avg)
{
 cout << "|" << setw(16) << "Student|"  << "|Grade|\n";   
 
 for (int i =0; i < size; i++)
 {
     cout <<"|" << setw(15) << *(*names+i)<< "||" << setw(5) << *(*ptr+i) << "|\n";
 }
 
 //output avg
 cout <<"|----------------------|\n";
 cout <<"|Average:" << setw(3) << avg << "|";
}

//creates the array dynamically
void  crtArry(short **ptr, string **names, int size)
{    
    //create the array
    *ptr = new short[size];        
    *names = new string[size];
}