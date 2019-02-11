#include "DNA.h"
#include <iostream>

using namespace std;

DNA::DNA()
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

bool DNA::validDNA(const string& s)
{
  bool result = true;
  for(int i = 0; i < s.length(); ++i)
  {
    if ( toupper(s[i]) != 'A'  &&  toupper(s[i]) != 'G'  &&  toupper(s[i]) != 'C'  &&  toupper(s[i]) != 'T')
    {
      result = false;
    }
  }
  return result;
}

void DNA::nucleotideTally(const string& s)
{
  for(int i = 0; i < s.length(); ++i)
  {
    switch ( toupper(s[i]) )
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

void DNA::resetNucleotideTally()
{
  Acount = 0;
  Ccount = 0;
  Gcount = 0;
  Tcount = 0;
}

void DNA::bigramTally(const string& s)
{
  for(int i = 0; i < s.length() && i + 1 < s.length(); i = i + 2)
  {
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
    else
    {
      cout << "Something went wrong." << endl;
    }
  }
}

int DNA::bigramTotal()
{
  return ( AAcount + ACcount + AGcount + ATcount + GAcount + GCcount + GGcount + GTcount + CAcount + CCcount + CGcount + CTcount + TAcount + TCcount + TGcount + TTcount );
}

void DNA::resetBigramTally()
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
