#include "Stats.h"

Stats::Stats()
{
  mean = 0;
  square_differences = 0;
  variance = 0;
  standard_deviation = 0;
}

double Stats::probability(double count, double total)
{
  return ( (count / total ) * 100 );
}

void Stats::calculateMean(double sum, double total)
{
  mean = sum / total;
}

void Stats::addSquareDifferences(double num)
{
  square_differences += pow((num - mean), 2);
}

void Stats::calculateVariance(double divisor)
{
  variance = square_differences / divisor;
}

void Stats::calculateStandardDeviation()
{
  standard_deviation = sqrt(variance);
}

int Stats::gaussianIntGen()
{
  double c;
  double d;
  //Note: Though C-type casts are generally avoided, when running tests I found that the C-type casts were much more time-efficient that static_cast.
  //Thus, given the number of strings main.cpp would need to generate, I decided to stay with the C-type casts.
  double i1 = ( (double) rand() / (RAND_MAX) );
  double i2 = ( (double) rand() / (RAND_MAX) );

  c = sqrt( -2 * log(i1) ) * cos(2 * M_PI * i2);
  d = (standard_deviation * c) + mean;

  return ( (int) d);
}
