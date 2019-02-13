#ifndef STATS_H
#define STATS_H

#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

class Stats {
public:
  Stats();

  double getMean() const { return mean; }
  double getSquareDiffs() const { return squareDiffs; }
  double getVariance() const { return variance; }
  double getStandardDev() const { return standardDev; }

  double probability(double count, double total);

  void calculateMean(double sum, double total);
  void addSquareDiffs(double num);
  void calculateVariance(double divisor);
  void calculateStandardDev();

  int gaussianIntGen();

private:
  double mean;
  double squareDiffs;
  double variance;
  double standardDev;
};
#endif
