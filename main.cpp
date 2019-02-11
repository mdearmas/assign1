/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  ifstream inputFile;
  ofstream outputFile("mdearmas.out", ios::out | ios::app);

  string filepath;
  string line;
  char answer;

  int lineCount = 0;
  int charCount = 0;

  bool readIn = true;

  if( outputFile.is_open() )
  {
    outputFile << "Makenzie De Armas" << endl;
    outputFile << "ID: 2278709" << endl;
    outputFile << "dearm102@mail.chapman.edu" << endl;
    outputFile << "CPSC 350-01, Assignment 1" << endl;
    outputFile << endl;
  }

  while (readIn)
  {
    cout << "Please enter your file name: ";
    cin >> filepath;

    inputFile.open(filepath);
    if ( inputFile.is_open() )
    {
      while ( getline(inputFile, line) )
      {
        lineCount++;
        for(int i = 0; i < line.length(); ++i)
        {
          charCount++;
        }
        outputFile << line << endl;
        outputFile << "Number of characters in this line: " << charCount << endl;
        charCount = 0;
      }
      outputFile << "Total number of lines in this file: " << lineCount << endl;
      outputFile << endl;
    }
    inputFile.close();
    lineCount = 0;

    cout << "Do you want to process another file? Enter Y for yes and N for no. ";
    cin >> answer;
    if( toupper(answer) == 'N' )
    {
      readIn = false;
    }
  }


  outputFile.close();
}
