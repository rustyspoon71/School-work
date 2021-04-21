/***********************************************************************
* Author:
*    Russell Roberts
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: getSize
 * Purpose: This will get the size of the array
 ***********************************************************************/
int getSize()
{
   // intialize the variable
   int size;

   // get the value from the user.
   cout << "Enter the size of the list: ";
   cin >> size;

   // return it.
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: This will get the list values.
 ***********************************************************************/

int* getList(int values[] , int count)
{
   // get the values of the array 
   int arrayValue;
   int i;
   for(i = 0; count > i; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> arrayValue;
      values[i] = arrayValue;

   } 
   cout << endl;
   // return the array
   return values;
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: This will be the display.
 ***********************************************************************/

void displayMultiples(int values[], int size)
{
   // initialize the trackers of the values
   int divisibles [size];
   
   // intialize the count of the number of values in the array
   int count = 0;
   
   // initialize the iterators for both loops
   int i;
   int x;
   
   // begin the loop and comparing
   for(i = 0; size > i; i++)
   {
      if(values[i] % 3 == 0)
      {
         divisibles[count] = values[i];
         count++;
      }
   }
   
   // display
   cout << "The following are divisible by 3:" << endl;
   // display the values by looping through the array where they are contained.
   for(x = 0; x < count; x++)
   {
      if (count != 0)
      {
      cout << divisibles[x] << endl;
      } 
   }
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/

int main()
{
   // driver of the program

   int sizeOfList = getSize();
   int arr [sizeOfList] = {};
   
   // point to the array

   int *valuesMain = getList(arr,sizeOfList);

   // display the values

   displayMultiples(valuesMain,sizeOfList);

   return 0;
}
