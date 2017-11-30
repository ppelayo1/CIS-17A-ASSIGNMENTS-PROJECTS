 // This program shows the donations made to the United Cause
 // by the employees of CK Graphics, Inc. It displays
 // the donations in order from lowest to highest
 // and in the original order they were received.
 #include <iostream>
 using namespace std;

 // Function prototypes
 void arrSelectSort(int *[], int);
 void showArray(const int [], int);
 void showArrPtr(int *[], int);
 

 int main()
 {
 // Number of donations
 int size; //size of array user 
 
 //prompt for number of donations to be entered
 cout << "How many donations would you like to enter?";
 cin >> size;
 
 //input validate
 while(size < 0 || size > 1000)
 {
     cout << "The number of donations must be between 0 and 1000.\n\n";
     
     cout << "How many donations would you like to enter?";
    cin >> size;
 }
 
 //create the dynamic array
 int *donations = new int[size];
 
 //let user enter the donation values
 for(int i= 0;i<size; i++)
 {
     cout << "What is the donation amount?\n";
     cin >> donations[i];
     
     while (donations[i] <= 0)
     {
         cout << "The donations must be greater than zero.\n\n";
         
         cout << "What is the donation amount?\n";
         cin >> donations[i];
         
     }
             
 }
 
 // An array of pointers to int.
 int *arrPtr[size];

 // Each element of arrPtr is a pointer to int. Make each
 // element point to an element in the donations array.
 for (int count = 0; count < size; count++)
 arrPtr[count] = &donations[count];

 // Sort the elements of the array of pointers.
 arrSelectSort(arrPtr, size);

 // Display the donations using the array of pointers. This
 // will display them in sorted order.
 cout << "The donations, sorted in descending order, are: \n";
 showArrPtr(arrPtr, size);

 // Display the donations in their original order.
 cout << "The donations, in their original order, are: \n";
 showArray(donations, size);
 
 //free memory
 delete [] donations;
 donations =0;
 return 0;
 }

 //****************************************************************
 // Definition of function arrSelectSort. *
 // This function performs an ascending order selection sort on *
 // arr, which is an array of pointers. Each element of arr *
 // points to an element of a second array. After the sort, *
 // arr will point to the elements of the second array in *
 // ascending order. *
 //****************************************************************

 void arrSelectSort(int *arr[], int size)
 {
 int startScan, minIndex;
 int *minElem;

 for (startScan = 0; startScan < (size - 1); startScan++)
 {
 minIndex = startScan;
 minElem = arr[startScan];
 for(int index = startScan + 1; index < size; index++)
 {
 if (*(arr[index]) > *minElem)
 {
 minElem = arr[index];
 minIndex = index;
 }
 }
 arr[minIndex] = arr[startScan];
 arr[startScan] = minElem;
 }
 }

 //*************************************************************
 // Definition of function showArray. *
 // This function displays the contents of arr. size is the *
 // number of elements. *
 //*************************************************************

 void showArray(const int arr[], int size)
 {
 for (int count = 0; count < size; count++)
 cout << arr[count] << " ";
 cout << endl;
 }

 //**************************************************************
 // Definition of function showArrPtr. *
 // This function displays the contents of the array pointed to *
 // by arr. size is the number of elements. *
 //**************************************************************

 void showArrPtr(int *arr[], int size)
 {
 for (int count = 0; count < size; count++)
 
      cout << *(arr[count]) << " ";
      cout << endl;
 
 }