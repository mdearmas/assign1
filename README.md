# assign1
CPSC 350 Assignment 1

Makenzie De Armas;
ID: 2278709;
dearm102@mail.chapman.edu;

Source Files Submitted:
  DNA.h //header file for DNA class// 
  DNA.cpp //contains out-of-class member functions for the DNA class// 
  Stats.h //header file for Stats class// 
  Stats.cpp //contains out-of-class member functions for the Stats class// 
  main.cpp //contains the main function// 
  dna.txt //test file used to test program// 
  dna.out //test file used to test program// 
  README.md //Read Me file// 

Errors: No known errors.

Resources used to complete the assignment: https://www.mathsisfun.com/data/standard-deviation.html (How to compute standard deviation and variance) // https://stackoverflow.com/questions/16393583/how-to-read-same-file-twice-in-a-row (How to read a file twice in a row) // https://stackoverflow.com/questions/9878965/rand-between-0-and-1 (How to use rand() to generate a number between 0 and 1) // https://www.quantstart.com/articles/Mathematical-Constants-in-C (How to access mathematical constants like M_PI) // https://stackoverflow.com/questions/3032726/rand-generating-the-same-number-even-with-srandtimenull-in-my-main (Used to troubleshoot an error with initializing the random seed) // http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf // (How to compile and link .o files)

Instructions for running the assignment:
  g++ -c DNA.cpp //produces DNA.o// 
  g++ -c Stats.cpp //produces Stats.o// 
  g++ main.cpp DNA.o Stats.o -o a.out //links main.cpp with object files DNA.o and Stats.o to produce a.out// 
  ./a.out //to run the main program// 
  nano mdearmas.out //to read the file produced by the assignment// 
