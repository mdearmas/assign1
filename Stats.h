#ifndef STATS_H
#define STATS_H
#define _USE_MATH_DEFINES

#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

class Stats {
public:
  Stats();

  double getMean() const { return mean; }
  double getSquareDifferences() const { return square_differences; }
  double getVariance() const { return variance; }
  double getStandardDeviation() const { return standard_deviation; }

  double probability(double count, double total);

  void calculateMean(double sum, double total);
  void addSquareDifferences(double num);
  void calculateVariance(double divisor);
  void calculateStandardDeviation();

  int gaussianIntGen();

private:
  double mean;
  double square_differences;
  double variance;
  double standard_deviation;
};
#endif
