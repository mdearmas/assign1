/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review

  Purpose: This file contains the definitions for out-of-class member functions for the class DNA.
*/

#include "DNA.h" //provides DNA

DNA::DNA() //default constructor
{
  Acount = 0;
  Ccount = 0;
  Gcount = 0;
  Tcount = 0;

  AAcount = 0;
  ACcount = 0;
  AGcount = 0;
  ATcount = 0;

  CAcount = 0;
  CCcount = 0;
  CGcount = 0;
  CTcount = 0;

  GAcount = 0;
  GCcount = 0;
  GGcount = 0;
  GTcount = 0;

  TAcount = 0;
  TCcount = 0;
  TGcount = 0;
  TTcount = 0;
}

bool DNA::validDNA(const string& s) //checks to see if passed parameter is a vaild DNA string
{
  bool result = true;
  for(int i = 0; i < s.length(); ++i)
  {
    if ( toupper(s[i]) != 'A'  &&  toupper(s[i]) != 'G'  &&  toupper(s[i]) != 'C'  &&  toupper(s[i]) != 'T') //if a character is none of the valid DNA nucleotides, the return value is switched to false
    {
      result = false;
    }
  }
  return result;
}

void DNA::nucleotideTally(const string& s) //adds the number of nucleotides within the passed string to the individual count variables
{
  for(int i = 0; i < s.length(); ++i)
  {
    switch ( toupper(s[i]) ) //toupper ensures to account for varied capitalization
    {
      case 'A':
        Acount++;
        break;
      case 'G':
        Gcount++;
        break;
      case 'C':
        Ccount++;
        break;
      case 'T':
        Tcount++;
        break;
    }
  }
}

void DNA::resetNucleotideTally() //resets all individual nucleotide values to 0
{
  Acount = 0;
  Ccount = 0;
  Gcount = 0;
  Tcount = 0;
}

void DNA::bigramTally(const string& s) //adds the number of nucleotide bigrams within the passed string to the bigram count variables
{
  for(int i = 0; i < s.length() && i + 1 < s.length(); i = i + 2) //the condition and the increment account for any odd strings so the function will not return an index out of bounds error
  {
    //the function first uses if and else-if statements to examine the first letter of the bigram, then branches into the possibilities using a switch statement
    if ( toupper(s[i]) == 'A')
    {
      switch ( toupper(s[i+1]) )
      {
        case 'A':
          AAcount++;
          break;
        case 'G':
          AGcount++;
          break;
        case 'C':
          ACcount++;
          break;
        case 'T':
          ATcount++;
          break;
      }
    }
    else if ( toupper(s[i]) == 'G' )
    {
      switch ( toupper(s[i+1]) )
      {
        case 'A':
          GAcount++;
          break;
        case 'G':
          GGcount++;
          break;
        case 'C':
          GCcount++;
          break;
        case 'T':
          GTcount++;
          break;
      }
    }
    else if ( toupper(s[i]) == 'C' )
    {
      switch ( toupper(s[i+1]) )
      {
        case 'A':
          CAcount++;
          break;
        case 'G':
          CGcount++;
          break;
        case 'C':
          CCcount++;
          break;
        case 'T':
          CTcount++;
          break;
      }
    }
    else if ( toupper(s[i]) == 'T' )
    {
      switch ( toupper(s[i+1]) )
      {
        case 'A':
          TAcount++;
          break;
        case 'G':
          TGcount++;
          break;
        case 'C':
          TCcount++;
          break;
        case 'T':
          TTcount++;
          break;
      }
    }
    else //in the event that a string without a valid nucleotide is passed through
    {
      cout << "Something went wrong." << endl;
    }
  }
}

void DNA::resetBigramTally() //resets all nucleotide bigram values to 0
{
  AAcount = 0;
  ACcount = 0;
  AGcount = 0;
  ATcount = 0;

  CAcount = 0;
  CCcount = 0;
  CGcount = 0;
  CTcount = 0;

  GAcount = 0;
  GCcount = 0;
  GGcount = 0;
  GTcount = 0;

  TAcount = 0;
  TCcount = 0;
  TGcount = 0;
  TTcount = 0;
}

int DNA::bigramTotal() //returns the total number of bigrams
{
  return ( AAcount + ACcount + AGcount + ATcount + GAcount + GCcount + GGcount + GTcount + CAcount + CCcount + CGcount + CTcount + TAcount + TCcount + TGcount + TTcount );
}
