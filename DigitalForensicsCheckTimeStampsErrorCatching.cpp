/***********************************************************************
* Author:
*    Russell Roberts
* Summary: 
*    This program will take a .txt file in the following format:
*    students.txt pricem 1441912123 . This is an example input from
*    a .txt file. It will then determine if someone accessed the 
*    file between the times you specify. It will then display the 
*    file accessed by who and at what timestamp. It will also catch
*    corrupt file names that are incorrect. 
*    
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
   int fileNum[MAX_COUNT];
   string fileName[MAX_COUNT];

};

/**********************************************************************
* parseLine will seperate the lines and save them into the struct.
***********************************************************************/
void parseLine(string fullLine,int count, info &values)
{
   // Get the full line and get ready to parse it.

   istringstream ss(fullLine);

   // Get values from parsed line.

   ss >> values.fileName[count] >> values.userName[count] 
      >> values.fileNum[count]; 

   // Conditions to catch all the errors

   if (ss.fail())
   {
      ss.ignore();
      cout << "Error parsing line: " << fullLine << endl;
   }
   else if 
      (values.fileNum[count] < 1000000000 || 
         values.fileNum[count]  > 10000000000)
   {
      cout << "Error parsing line: " << fullLine << endl;
   }
}

/**********************************************************************
* getData will open the file then pass the line into parseLine()
***********************************************************************/
void getData(string name, info &myStruct)
{
   // Declare the ifstream object to recieve the input.

   ifstream fin;

   // Open the file with the name.

   fin.open(name);
   int count = 0;
   string line;

   // Start the loop until the data is all read in and eof is false.

   while (!fin.eof())
   {
      
      getline(fin,line);

      // If you reach the end of the file break the loop do not 
      // pass next blank line into the parseLine function.
      // Producing a false error.

      if (line == "") 
      {
         break;
      }

      // Pass the values to the parseLine function.

      parseLine(line,count,myStruct);

      // Increment the count each time in the loop for the indexes.
      
      count++;
   }
   
   // Close the file.

   fin.close();
}

/**********************************************************************
* Display will output results from the program.
***********************************************************************/
void display(info &values,int start, int end)
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

   // Point to the address of the int were going to compare to get the value of the int.

   *values.fileNum; 

   // Start the output loop if conditions are met print the values.

   for (int i = 0; i < 500; i++)
   {
      if (start < values.fileNum[i]  && values.fileNum[i] < end)
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
   getData(file,Info);

   // Get the start time.

   cout << endl;
   int startTime;
   cout << "Enter the start time: ";
   cin >> startTime;

   // Get the end time.

   int endTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   cout << endl;
   
   // display the results

   display(Info,startTime,endTime);


   // Display the end of the program.

   cout << "End of records";
   cout << endl;
   return 0;
}
