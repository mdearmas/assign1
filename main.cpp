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
          d1.bigramTally(line);
        }
      }
      outputFile << "INDIVIDUAL NUCLEOTIDES" << endl;
      outputFile << "Total A: " << d1.getAcount() << endl;
      outputFile << "Total C: " << d1.getCcount() << endl;
      outputFile << "Total G: " << d1.getGcount() << endl;
      outputFile << "Total T: " << d1.getTcount() << endl;
      outputFile << endl;

      outputFile << "BIGRAM COUNT" << endl;
      outputFile << "Total AA: " << d1.getAAcount() << endl;
      outputFile << "Total AC: " << d1.getACcount() << endl;
      outputFile << "Total AG: " << d1.getAGcount() << endl;
      outputFile << "Total AT: " << d1.getATcount() << endl;
      outputFile << "Total CA: " << d1.getCAcount() << endl;
      outputFile << "Total CC: " << d1.getCCcount() << endl;
      outputFile << "Total CG: " << d1.getCGcount() << endl;
      outputFile << "Total CT: " << d1.getCTcount() << endl;
      outputFile << "Total GA: " << d1.getGAcount() << endl;
      outputFile << "Total GC: " << d1.getGCcount() << endl;
      outputFile << "Total GG: " << d1.getGGcount() << endl;
      outputFile << "Total GT: " << d1.getGTcount() << endl;
      outputFile << "Total TA: " << d1.getTAcount() << endl;
      outputFile << "Total TC: " << d1.getTCcount() << endl;
      outputFile << "Total TG: " << d1.getTGcount() << endl;
      outputFile << "Total TT: " << d1.getTTcount() << endl;
      outputFile << endl;

      lineCount = 0;
      d1.resetNucleotideTally();
      d1.resetBigramTally();
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
