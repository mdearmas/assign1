/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review

  Purpose: This file contains the definitions for out-of-class member functions for the class Stats.
*/

#include "Stats.h" //provides Stats

Stats::Stats() //default constructor
{
  mean = 0;
  square_differences = 0;
  variance = 0;
  standard_deviation = 0;
}

double Stats::probability(double count, double total)//calculates the probability of the former parameter occuring
{
  return ( (count / total ) * 100 ); //outputs probability as a percentage value
}

void Stats::calculateMean(double sum, double total) //calculates and stores the mean
{
  mean = sum / total;
}

void Stats::addSquareDifferences(double num) //calculates and stores the squared differences of values from the stored mean
{
  square_differences += pow((num - mean), 2);
}

void Stats::calculateVariance(double divisor) //calculates and stores the variance based on the stored square differences and the input divisor
{
  variance = square_differences / divisor; //Source: https://www.mathsisfun.com/data/standard-deviation.html
}

void Stats::calculateStandardDeviation()  //calculates and stores the standard deviation based on the stored variance
{
  standard_deviation = sqrt(variance); //Source: https://www.mathsisfun.com/data/standard-deviation.html
}

void Stats::resetAll() //resets all values to the default 0
{
  mean = 0;
  square_differences = 0;
  variance = 0;
  standard_deviation = 0;
}

int Stats::gaussianIntGen() //uses the Box-Mueller transform to generate an integer value based on the Gaussian distribution given by the stored mean and standard deviation
{
  //since we initialize the random seed in the main program, we don't need to initialize it in this function
  double c;
  double d;
  //Note: Though C-type casts are generally avoided, when running tests I found that the C-type casts were much more time-efficient that static_cast.
  //Thus, given the number of strings main.cpp would need to generate, I decided to stay with the C-type casts.
  double i1 = ( (double) rand() / (RAND_MAX) ); //Source: https://stackoverflow.com/questions/9878965/rand-between-0-and-1
  double i2 = ( (double) rand() / (RAND_MAX) );

  c = sqrt( -2 * log(i1) ) * cos(2 * M_PI * i2);
  d = (standard_deviation * c) + mean;

  return ( (int) d);
}
