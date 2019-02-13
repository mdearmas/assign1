#include "Stats.h"

Stats::Stats()
{
  mean = 0;
  variance = 0;
  standardDev = 0;
}

double Stats::probability(double count, double total)
{
  return ( (count / total ) * 100 );
}
