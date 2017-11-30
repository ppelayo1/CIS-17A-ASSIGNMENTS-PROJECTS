/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Patrick
 *
 * Created on October 19, 2017, 6:16 PM
 */

#include "RetailItem.h"


/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    string des;
    int    unit;
    float  price;
    bool flag = true; //flag to control the do loop
    int    con;  //control for the switch
    //prompt and get the data for the variables
    cout << "Please enter the description of the item.\n";
    getline(cin,des);
    
    cout << "Please enter the number of units available.\n";
    cin >> unit;
    
    cout << "Please enter the price of the item.\n";
    cin >> price;
    
    //build the class
    RetI item(des,unit,price);
    
    //use a switch system to control the manipulation of class data
    do
    {
        cout << "Enter 1 to change item description.\n";
        cout << "Enter 2 to change item units available.\n";
        cout << "Enter 3 to change the price of the item.\n";
        cout << "Enter 4 to get the current item description,  units, and price.\n";
        cout << "Enter 0 to end proram.\n";
        
        cin >> con;
    
    
        switch(con){
            case 1:
                //clear buffer then prompt
                cin.ignore(1000,'\n');
                cout << "Please enter the new item description.\n";
                getline(cin,des);
                item.setDes(des);
                break;
            case 2:
                cout << "Enter the number of units available.\n";
                cin >> unit;
                item.setUnit(unit);
                break;
            case 3:
                cout << "Enter the new price of the item.\n";
                cin >> price;
                item.setPrice(price);
                break;
            case 4:
                cout << "The current description of the item.\n";
                cout << item.getDes() << endl << "Available units.\n";
                cout << item.getUnit() << endl << "Item price\n$";
                cout << item.getPrice();
                cout << endl << endl;
                break;
            case 0:
                flag = false;//end program
                break;
            default:
                cout << "That is not valid.\n\n";
                break;          
        }
        
            
        
    }while (flag == true);
    
    
    return 0;
}

