<h1> Week 1 Assignment Brief </h1>


In this programming assignment you will create a simple application that performs statistical analytics on a dataset. This assignment will help you get re-oriented with c-programming syntax and host machine compilation. We begin by setting up a version control repository on your local machine. You will then develop and test your code there. When complete, you will upload a zip of your repository to Coursera. Please read through all instructions before starting.

### After completing this assignment, you will be able to:

 1. Write a simple programming assignment that prints statistics to the command line using a variety of c-programming operators and features.
 2. Perform Compilation with GCC and execute output files from the command line. 
 3. Use git Version control to create a repository to version control code.
 
 ### Environment Setup

For this course you will be using a Ubuntu Linux Virtual Machine. In order to run this machine, you will need to download Oracle’s VirtualBox software and the VM.

The VM is ready for download in our supplementary materials. Here is a link to those instructions and the new VM: https://www.coursera.org/learn/introduction-embedded-systems/resources/jDf20

### Assignment Guidelines

You are to write a couple of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set. In addition, you will need to reorder this data set from large to small. All statistics should be rounded down to the nearest integer. After analysis and sorting is done, you will need to print that data to the screen in nicely formatted presentation. You will need to submit a version controlled repository of these 3 files.

  1. stats.c - Implementation file for your C-programming code
  2. stats.h -  Header file for your C-programming code
  3. README.md -  Includes information on the author and the project
  
The assessment files will be available by using our course1 repositoriy hosted on github. You can git clone the assessments repo from github:
```
cd ~
git clone https://github.com/afosdick/ese-coursera-course1.git
```
The folder contains:   

The stats.c and stats.h files  have some premade function comment format for you to enter data into. You will need to include your name as the author, the date, and a small description of the file at the top. If you open stats.c  you will see you have been given part of a main() function. Main has defined an array of 40 characters for testing. At the top of README.md, add your name and description of the repository and project.

You will need to write eight functions in the stats.c implementation file:

 1. main() - The main entry point for your program
 2. print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 3. print_array() -  Given an array of data and a length, prints the array to the screen
 4. find_median() - Given an array of data and a length, returns the median value
 5. find_mean() -  Given an array of data and a length, returns the mean
 6. find_maximum() -  Given an array of data and a length, returns the maximum
 7. find_minimum() -  Given an array of data and a length, returns the minimum
 8. sort_array() - Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last       element (n-1) should be the smallest value.)
 
 To print data to the screen, you can use the printf function provided by the standard IO library (stdio.h). Each printed value should be nicely formatted with an indicator of the variable or index for each statistic value printed. 

Most of the functions in the stats.c file require 2 input parameters and one return value:

 * Input: A unsigned char pointer to an n-element data array
 * Input: An unsigned integer as the size of the array
 * Output: An unsigned char result from the function
 
### Header file guidelines - stats.h

The stats.h header file needs to include declarations and documentation for the functions from the stats.c file. You will add function declarations for all required functions except main. With each declaration you need to provide comments with a description of the function, the inputs, and return value. An example is provided below for a function swap32() that does a byte swap of a 32-bit data item.

```C
/**
* @brief Reverses the byte order of an unsigned 32-bit integer
*
* This function takes as an input a 32-bit integer. This will
* reverse the byte order of the full word. Instead of changing
* the parameter passed to it, it will returne a reversed unsigned
* 32-bit integer.
*
* @param word The 32-bit word to be reversed
* @return The reversed 32-bit value word
*/
unsigned int swap32(unsigned int word);
```

### Compilation Guidelines

To compile and run this code you can run the following commands:

```
gcc -o stats.out stats.c
./stats.out
```
