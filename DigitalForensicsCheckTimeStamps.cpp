/***********************************************************************
* Author:
*    Russell Roberts
* Summary: 
*    This program will take a .txt file in the following format:
*    students.txt pricem 1441912123 . This is an example input from
*    a .txt file. It will then determine if someone accessed the 
*    file between the times you specify. It will then display the 
*    file accesed by who and at what timestamp. The max size of the
*    .txt file is 500 lines which can be easily changed by adjusting 
*    the MAX_COUNT variable.
************************************************************************/

#include <iostream>
#include <string> 
#include <iomanip>
#include <fstream>
#include <sstream>
const int MAX_COUNT = 500;
using namespace std;

// Initialize the structure.

struct info
{
   string userName[MAX_COUNT];
   string fileNum[MAX_COUNT];
   string fileName[MAX_COUNT];

};

/**********************************************************************
* getData will open the file and get all the data from it and read it 
* into our structure info.
***********************************************************************/
void getData(string name,info &myStruct)
{
   // Declare the ifstream object to recieve the input.

   ifstream fin;

   // Open the file with the name.

   fin.open(name);
   int count = 0;

   // Start the loop until the data is all read in and eof is false.

   while (!fin.eof())
   {
      fin >> myStruct.fileName[count];
      fin >> myStruct.userName[count];
      fin >> myStruct.fileNum[count];
      count++;
   }
   
   // Close the file.

   fin.close();
}

/**********************************************************************
* Display will output results from the program.
***********************************************************************/
void display(info values,int start, int end)
{
   // setup the display.

   cout << "The following records match your criteria:";
   cout << endl;
   cout << endl;
   cout << "      Timestamp";
   cout << setw(20);
   cout << "File";
   cout << setw(20);
   cout << "User";
   cout << endl;
   cout << "--------------- ------------------- -------------------";
   cout << endl;

   // start the output loop.

   for (int i = 0; i < 500; i++)
   {
      // stream the string into an int.
      stringstream num(values.fileNum[i]);
      int id;
      num >> id;

      // create the print statement enter if statement if it is true.
      if (start < id  && id < end)
      {
         cout << "     " << values.fileNum[i];
         cout << setw(20);
         cout << values.fileName[i];
         cout << setw(20);
         cout << values.userName[i];
         cout << endl;
      }
   }
}

/**********************************************************************
* Main will act as the driver of the program.
***********************************************************************/
int main()
{
   // Initialize the structure object.

   info Info;

   // Get the filename.

   string file;
   cout << "Enter the access record file: ";
   cin >> file;
   cout << endl;

   // Get the start time.

   int startTime;
   cout << "Enter the start time: ";
   cin >> startTime;

   // Get the end time.

   int endTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   cout << endl;

   // Use these two functions to do all the work.

   getData(file, Info);
   display(Info,startTime,endTime);


   // Display the end of the program.

   cout << "End of records";
   cout << endl;
   return 0;
}
