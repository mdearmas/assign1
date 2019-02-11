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
