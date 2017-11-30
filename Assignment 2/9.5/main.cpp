/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on September 24, 2017, 7:51 PM
 */

#include <iostream>

//function prototypes
int doSomething(int *x, int *y); //

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    //variables
    int x;
    int y;
    int ans; 
    
    //prompt    
    cout << "x will be assigned y * 10.\n y will be assigned x * 10.\n";
    cout << "The value of x + y will be calculated\n";
    cout << "Please enter the value of x.\n";
    cin >> x;
    cout << "Please enter the value of y.\n";
    cin >> y;
    
    ans = doSomething(&x,&y);
    
    cout << "The answer is.\n" << ans;
    return 0;
}


int doSomething(int *x, int *y)
{
int temp = *x;
*x = *y * 10;
*y = temp * 10;
return *x + *y;
}

