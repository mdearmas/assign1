# assign1
CPSC 350 Assignment 1

Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu

Source Files Submitted:
  DNA.h //header file for DNA class
  DNA.cpp //contains out-of-class member functions for the DNA class
  Stats.h //header file for Stats class
  Stats.cpp //contains out-of-class member functions for the Stats class
  main.cpp //contains the main function
  dna.txt //test file used to test program
  dna.out //test file used to test program
  README.md //Read Me file

Errors: No known errors.

Instructions for running the assignment:
  g++ -c DNA.cpp //produces DNA.o
  g++ -c Stats.cpp //produces Stats.o
  g++ main.cpp DNA.o Stats.o -o a.out //links main.cpp with object files DNA.o and Stats.o to produce a.out
  ./a.out //to run the main program
  nano mdearmas.out //to read the file produced by the assignment
