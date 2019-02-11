/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
*/

#include <iostream>
#include <fstream>
#include "DNA.h"

using namespace std;

int main(int argc, char **argv)
{
  ifstream inputFile;
  ofstream outputFile("mdearmas.txt", ios::out | ios::app);

  string filepath;
  string line;
  char answer;

  int lineCount = 0;
  int charCount = 0;

  bool readIn = true;

  DNA d1;

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
        if(d1.validDNA(line))
        {
          lineCount++;
          for(int i = 0; i < line.length(); ++i)
          {
            charCount++;
          }
          d1.nucleotideTally(line);
        }
      }
      outputFile << "Total A: " << d1.getAcount() << endl;
      outputFile << "Total C: " << d1.getCcount() << endl;
      outputFile << "Total G: " << d1.getGcount() << endl;
      outputFile << "Total T: " << d1.getTcount() << endl;
      outputFile << endl;

      lineCount = 0;
      d1.resetNucleotideTally();
    }
    else
    {
      cout << "Unable to open specified file. " << endl;
    }
    inputFile.close();


    cout << "Do you want to process another file? Enter Y for yes and N for no. ";
    cin >> answer;
    if( toupper(answer) == 'N' )
    {
      readIn = false;
    }
  }

  outputFile.close();
}
