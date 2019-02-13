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
