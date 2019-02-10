/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  ifstream inputFile;
  string filepath;
  string line;
  ofstream outputFile("mdearmas.txt");

  int lineCount = 0;

  if( outputFile.is_open() )
  {
    outputFile << "Makenzie De Armas" << endl;
    outputFile << "ID: 2278709" << endl;
    outputFile << "dearm102@mail.chapman.edu" << endl;
    outputFile << "CPSC 350-01, Assignment 1" << endl;
    outputFile << endl;
  }

  cout << "Please enter your file name: ";
  cin >> filepath;

  inputFile.open(filepath);
  if ( inputFile.is_open() )
  {
    while ( getline(inputFile, line) )
    {
      lineCount++;
      outputFile << line << endl;
    }
    outputFile << lineCount << endl;
  }

  inputFile.close();
  outputFile.close();
}
