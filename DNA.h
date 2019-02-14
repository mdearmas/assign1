/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review

  Purpose: This is the header file for the DNA class.
*/
#ifndef DNA_H //prevents repeated expansion
#define DNA_H

#include <iostream> //provides iostream

using namespace std; //makes std accessible

class DNA {
public:
  DNA(); //default constructor

  //accessors
  int getAcount() const {return Acount;}
  int getCcount() const {return Ccount;}
  int getGcount() const {return Gcount;}
  int getTcount() const {return Tcount;}

  int getAAcount() const {return AAcount;}
  int getACcount() const {return ACcount;}
  int getAGcount() const {return AGcount;}
  int getATcount() const {return ATcount;}

  int getCAcount() const {return CAcount;}
  int getCCcount() const {return CCcount;}
  int getCGcount() const {return CGcount;}
  int getCTcount() const {return CTcount;}

  int getGAcount() const {return GAcount;}
  int getGCcount() const {return GCcount;}
  int getGGcount() const {return GGcount;}
  int getGTcount() const {return GTcount;}

  int getTAcount() const {return TAcount;}
  int getTCcount() const {return TCcount;}
  int getTGcount() const {return TGcount;}
  int getTTcount() const {return TTcount;}

  //other functions
  bool validDNA(const string& s); //checks to see if passed parameter is a vaild DNA string

  void nucleotideTally(const string& s); //adds the number of nucleotides within the passed string to the individual count variables
  void resetNucleotideTally(); //resets all individual nucleotide values to 0
  void bigramTally(const string& s); //adds the number of nucleotide bigrams within the passed string to the bigram count variables
  void resetBigramTally(); //resets all nucleotide bigram values to 0

  int bigramTotal(); //returns the total number of bigrams

private:
  int Acount;
  int Ccount;
  int Gcount;
  int Tcount;

  int AAcount;
  int ACcount;
  int AGcount;
  int ATcount;

  int CAcount;
  int CCcount;
  int CGcount;
  int CTcount;

  int GAcount;
  int GCcount;
  int GGcount;
  int GTcount;

  int TAcount;
  int TCcount;
  int TGcount;
  int TTcount;
};
#endif
