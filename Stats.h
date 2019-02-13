#ifndef STATS_H
#define STATS_H

#include <cstdlib>
#include <time.h>

using namespace std;

class Stats {
public:
  Stats();

  double getMean() const { return mean; }
  double getVariance() const { return variance; }
  double getStandardDev() const { return standardDev; }

  double probability(double count, double total);

  double calculateMean(double sum, double total);
  double calculateVariance();
  double calculateStandardDev();

  int gaussianIntGen();

private:
  double mean;
  double variance;
  double standardDev;
};
#endif
