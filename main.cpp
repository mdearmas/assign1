/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "DNA.h"
#include "Stats.h"

using namespace std;

int main(int argc, char **argv)
{
  srand(time(NULL));
  ifstream inputFile;
  ofstream outputFile("mdearmas.txt", ios::out | ios::app);

  string filepath;
  string line;
  char answer;

  int lineCount = 0;
  int charCount = 0;

  bool readIn = true;

  DNA d1;
  Stats s1;

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

      inputFile.clear();
      inputFile.seekg(0);

      outputFile << "For " << filepath << " — " << endl;
      outputFile << endl;

      outputFile << "INDIVIDUAL NUCLEOTIDES STATISTICS" << endl;
      outputFile << "Total A: " << d1.getAcount() << " (" << s1.probability(d1.getAcount(), charCount) << "% probability)" << endl;
      outputFile << "Total C: " << d1.getCcount() << " (" << s1.probability(d1.getCcount(), charCount) << "% probability)" << endl;
      outputFile << "Total G: " << d1.getGcount() << " (" << s1.probability(d1.getGcount(), charCount) << "% probability)" << endl;
      outputFile << "Total T: " << d1.getTcount() << " (" << s1.probability(d1.getTcount(), charCount) << "% probability)" << endl;
      outputFile << endl;

      outputFile << "NUCLEOTIDE BIGRAM STATISTICS" << endl;
      outputFile << "Total AA: " << d1.getAAcount() << " (" << s1.probability(d1.getAAcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total AC: " << d1.getACcount() << " (" << s1.probability(d1.getACcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total AG: " << d1.getAGcount() << " (" << s1.probability(d1.getAGcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total AT: " << d1.getATcount() << " (" << s1.probability(d1.getATcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total CA: " << d1.getCAcount() << " (" << s1.probability(d1.getCAcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total CC: " << d1.getCCcount() << " (" << s1.probability(d1.getCCcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total CG: " << d1.getCGcount() << " (" << s1.probability(d1.getCGcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total CT: " << d1.getCTcount() << " (" << s1.probability(d1.getCTcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total GA: " << d1.getGAcount() << " (" << s1.probability(d1.getGAcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total GC: " << d1.getGCcount() << " (" << s1.probability(d1.getGCcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total GG: " << d1.getGGcount() << " (" << s1.probability(d1.getGGcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total GT: " << d1.getGTcount() << " (" << s1.probability(d1.getGTcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total TA: " << d1.getTAcount() << " (" << s1.probability(d1.getTAcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total TC: " << d1.getTCcount() << " (" << s1.probability(d1.getTCcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total TG: " << d1.getTGcount() << " (" << s1.probability(d1.getTGcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << "Total TT: " << d1.getTTcount() << " (" << s1.probability(d1.getTTcount(), d1.bigramTotal()) << "% probability)" << endl;
      outputFile << endl;

      s1.calculateMean(charCount, lineCount);
      while ( getline(inputFile, line) )
      {
        s1.addSquareDiffs(line.length());
      }
      s1.calculateVariance(lineCount);
      s1.calculateStandardDev();

      outputFile << "DNA STRING LENGTH STATISTICS" << endl;
      outputFile << "Sum: " << charCount << endl;
      outputFile << "Mean: " << s1.getMean() << endl;
      outputFile << "Variance: " << s1.getVariance() << endl;
      outputFile << "Standard Deviation: " << s1.getStandardDev() << endl;
      outputFile << endl;

      outputFile << "NEW DNA STRING GENERATION" << endl;
      outputFile << endl;
      for(int i = 0; i < 100; ++i)
      {
        double r;
        int length;
        string newDNA = "";
        do {
          length = s1.gaussianIntGen();
        } while(length <= 0);

        for(int j = 0; j < length; ++j)
        {
          r = rand() % 100;
          if( r < s1.probability(d1.getAcount(), charCount))
            {newDNA += "A";}
          else if(r < (s1.probability(d1.getAcount(), charCount) + s1.probability(d1.getCcount(), charCount)))
            {newDNA += "C";}
          else if(r < (100 - s1.probability(d1.getTcount(), charCount)))
            {newDNA += "G";}
          else
            {newDNA += "T";}
        }
        outputFile << newDNA << endl;
      }

      outputFile << endl;
      outputFile << "End information for " << filepath << endl;
      outputFile << endl;

      lineCount = 0;
      d1.resetNucleotideTally();
      d1.resetBigramTally();
      inputFile.close();
    }
    else
    {
      cout << "Unable to open specified file. " << endl;
    }

    cout << "Do you want to process another file? Enter Y for yes and N for no. ";
    cin >> answer;
    if( toupper(answer) == 'N' )
    {
      readIn = false;
    }
    else if ( toupper(answer) != 'Y')
    {
      cout << "Invalid answer. Program exiting. " << endl;
      readIn = false;
    }
  }

  outputFile.close();
}
