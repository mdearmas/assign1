#include "Stats.h"

Stats::Stats()
{
  mean = 0;
  squareDiffs = 0;
  variance = 0;
  standardDev = 0;
}

double Stats::probability(double count, double total)
{
  return ( (count / total ) * 100 );
}

void Stats::calculateMean(double sum, double total)
{
  mean = sum / total;
}

void Stats::addSquareDiffs(double num)
{
  squareDiffs += pow((num - mean), 2);
}

void Stats::calculateVariance(double divisor)
{
  variance = squareDiffs / divisor;
}

void Stats::calculateStandardDev()
{
  standardDev = sqrt(variance);
}

int Stats::gaussianIntGen()
{
  double i1;
  double i2;
  double c;
  double d;

  i1 = ( (double) rand() / (RAND_MAX) );
  i2 = ( (double) rand() / (RAND_MAX) );

  c = sqrt( -2 * log(i1) ) * cos(2 * M_PI * i2);
  d = (standardDev * c) + mean;

  return ( (int) d);
}
