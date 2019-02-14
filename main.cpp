/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review
*/
#include <cstdlib>
#include <iostream>
#include <fstream>

#include <time.h>
#include "DNA.h"
#include "Stats.h"

using namespace std;

int main(int argc, char **argv)
{
  srand(time(NULL));
  ifstream input_file;
  ofstream output_file("mdearmas.out", ios::out | ios::app);

  string filepath;
  string line;
  string new_dna = "";

  char answer;

  int line_count = 0;
  int char_count = 0;
  int generated_string_length;

  double r;

  bool read_in = true;

  DNA d1;
  Stats s1;

  if( output_file.is_open() )
  {
    output_file << "Makenzie De Armas" << endl;
    output_file << "ID: 2278709" << endl;
    output_file << "dearm102@mail.chapman.edu" << endl;
    output_file << "CPSC 350-01, Assignment 1" << endl;
    output_file << endl;
  }

  while (read_in)
  {
    cout << "Please enter your file name: ";
    cin >> filepath;

    input_file.open(filepath);
    if ( input_file.is_open() )
    {
      while ( getline(input_file, line) )
      {
        if(d1.validDNA(line))
        {
          line_count++;
          for(int i = 0; i < line.length(); ++i)
          {
            char_count++;
          }
          d1.nucleotideTally(line);
          d1.bigramTally(line);
        }
      }

      input_file.clear();
      input_file.seekg(0);

      output_file << "For " << filepath << " — " << endl;
      output_file << endl;

      output_file << "INDIVIDUAL NUCLEOTIDES STATISTICS" << endl;
      output_file << "Total A: " << d1.getAcount() << " (" << s1.probability(d1.getAcount(), char_count) << "% probability)" << endl;
      output_file << "Total C: " << d1.getCcount() << " (" << s1.probability(d1.getCcount(), char_count) << "% probability)" << endl;
      output_file << "Total G: " << d1.getGcount() << " (" << s1.probability(d1.getGcount(), char_count) << "% probability)" << endl;
      output_file << "Total T: " << d1.getTcount() << " (" << s1.probability(d1.getTcount(), char_count) << "% probability)" << endl;
      output_file << endl;

      output_file << "NUCLEOTIDE BIGRAM STATISTICS" << endl;
      output_file << "Total AA: " << d1.getAAcount() << " (" << s1.probability(d1.getAAcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total AC: " << d1.getACcount() << " (" << s1.probability(d1.getACcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total AG: " << d1.getAGcount() << " (" << s1.probability(d1.getAGcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total AT: " << d1.getATcount() << " (" << s1.probability(d1.getATcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total CA: " << d1.getCAcount() << " (" << s1.probability(d1.getCAcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total CC: " << d1.getCCcount() << " (" << s1.probability(d1.getCCcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total CG: " << d1.getCGcount() << " (" << s1.probability(d1.getCGcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total CT: " << d1.getCTcount() << " (" << s1.probability(d1.getCTcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total GA: " << d1.getGAcount() << " (" << s1.probability(d1.getGAcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total GC: " << d1.getGCcount() << " (" << s1.probability(d1.getGCcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total GG: " << d1.getGGcount() << " (" << s1.probability(d1.getGGcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total GT: " << d1.getGTcount() << " (" << s1.probability(d1.getGTcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total TA: " << d1.getTAcount() << " (" << s1.probability(d1.getTAcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total TC: " << d1.getTCcount() << " (" << s1.probability(d1.getTCcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total TG: " << d1.getTGcount() << " (" << s1.probability(d1.getTGcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << "Total TT: " << d1.getTTcount() << " (" << s1.probability(d1.getTTcount(), d1.bigramTotal()) << "% probability)" << endl;
      output_file << endl;

      s1.calculateMean(char_count, line_count);
      while ( getline(input_file, line) )
      {
        s1.addSquareDifferences(line.length());
      }
      s1.calculateVariance(line_count);
      s1.calculateStandardDeviation();

      output_file << "DNA STRING LENGTH STATISTICS" << endl;
      output_file << "Sum: " << char_count << endl;
      output_file << "Mean: " << s1.getMean() << endl;
      output_file << "Variance: " << s1.getVariance() << endl;
      output_file << "Standard Deviation: " << s1.getStandardDeviation() << endl;
      output_file << endl;

      output_file << "NEW DNA STRING GENERATION" << endl;
      output_file << endl;

      for(int i = 0; i < 1000; ++i)
      {
        do {
          generated_string_length = s1.gaussianIntGen();
        } while(generated_string_length <= 0);

        for(int j = 0; j < generated_string_length; ++j)
        {
          r = rand() % 100;
          if( r < s1.probability(d1.getAcount(), char_count))
            {new_dna += "A";}
          else if(r < (s1.probability(d1.getAcount(), char_count) + s1.probability(d1.getCcount(), char_count)))
            {new_dna += "C";}
          else if(r < (100 - s1.probability(d1.getTcount(), char_count)))
            {new_dna += "G";}
          else
            {new_dna += "T";}
        }
        output_file << new_dna << endl;
        new_dna = "";
        generated_string_length = 0;
      }

      output_file << endl;
      output_file << "End information for " << filepath << endl;
      output_file << endl;

      line_count = 0;
      d1.resetNucleotideTally();
      d1.resetBigramTally();
      input_file.close();
    }
    else
    {
      cout << "Unable to open specified file. " << endl;
    }

    cout << "Do you want to process another file? Enter Y for yes and N for no. ";
    cin >> answer;
    if( toupper(answer) == 'N' )
    {
      read_in = false;
    }
    else if ( toupper(answer) != 'Y')
    {
      cout << "Invalid answer. Program exiting. " << endl;
      read_in = false;
    }
  }

  output_file.close();
}
