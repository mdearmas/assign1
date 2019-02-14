/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 1: C++ Review

  Purpose: This is the header file for the Stats class.
*/
#ifndef STATS_H //prevents repeated expansion
#define STATS_H
#define _USE_MATH_DEFINES //allows the class to access mathematical constants like M_PI

#include <cstdlib> //provides RAND_MAX
#include <time.h> //provides time() for random seeding
#include <cmath> //provides mathematical operations like pow() and sqrt()

using namespace std; //makes std accessible

class Stats {
public:
  Stats(); //constructor

  //accessors
  double getMean() const { return mean; }
  double getSquareDifferences() const { return square_differences; }
  double getVariance() const { return variance; }
  double getStandardDeviation() const { return standard_deviation; }

  //other functions
  double probability(double count, double total); //calculates the probability in percentage of the former parameter occuring

  void calculateMean(double sum, double total); //calculates and stores the mean
  void addSquareDifferences(double num); //calculates and stores the squared differences of values from the stored mean
  void calculateVariance(double divisor); //calculates and stores the variance based on the stored square differences and the input divisor
  void calculateStandardDeviation(); //calculates and stores the standard deviation based on the stored variance
  void resetAll(); //resets all values to the default 0

  int gaussianIntGen(); //uses the Box-Mueller transform to generate an integer value based on the Gaussian distribution given by the stored mean and standard deviation

private:
  double mean;
  double square_differences;
  double variance;
  double standard_deviation;
};
#endif
