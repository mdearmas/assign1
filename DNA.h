#ifndef DNA_H
#define DNA_H

#include <iostream>
using namespace std;

class DNA {
public:
  DNA();

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

  bool validDNA(const string& s);
  void nucleotideTally(const string& s);
  void bigramTally(const string& s);
  void incrementCount(int& i);

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
