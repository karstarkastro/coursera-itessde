/******************************************************************************
 * Copyright (C) 2020 by Pablo Castro
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. 

 *****************************************************************************/
/**
 * @file stats.c
 * @brief Performs a set of statistical analysis tools on a dataset
 *
 * Given an array of SIZE number of elements of type char, the function calculates
 * the mean, median, minimum and maximum elements of the array. Furthermore, it also
 * sorts the array in descending order. Lastly, it prints the array elements and the 
 * statistics calculated with the functions described in the beginning.
 *
 * @author Pablo Castro
 * @date July 2020
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  int max, min, median, mean;

  printf("The elements of the original array are:\n");
  print_array(SIZE, &test[0]);

  sort_array(SIZE, &test[0]);
  printf("The elements of the sorted array are:\n");
  print_array(SIZE, &test[0]); 

  max = find_maximum(SIZE, &test[0]);
  min = find_minimum(SIZE, &test[0]);
  mean = find_mean(SIZE, &test[0]);
  median = find_median(SIZE, &test[0]);

  print_statistics(max, min, mean, median);

}

int find_minimum (unsigned int arrayLength, unsigned char *arrayElement) {
  int result = (int)(*arrayElement);
  for (int i=1;i<SIZE;i++){
  	if((int)(*(arrayElement + i)) < result)
  	  result = *(arrayElement + i);
  }
  return(result);
}

int find_maximum (unsigned int arrayLength, unsigned char *arrayElement) {
  int result = (int)(*arrayElement);
  for (int i=1;i<SIZE;i++){
  	if((int)(*(arrayElement + i)) > result)
  	  result = *(arrayElement + i);
  }
  return(result);
}

int find_mean (unsigned int arrayLength, unsigned char *arrayElement) {
  int sum = 0;
  for (int i=0;i<SIZE;i++){
  	sum += (int)(*(arrayElement + i));
  }
  float diff = (float)sum/SIZE - (int)sum/SIZE;
  if(diff >= 0.5)
    return ((int)sum/SIZE + 1);
  else
    return (int)sum/SIZE;
}

int find_median (unsigned int arrayLength, unsigned char *arrayElement) {
  if(SIZE % 2 == 0){
  	int first = (int)*(arrayElement + (SIZE/2));
  	int second = (int)*(arrayElement + (SIZE/2) - 1);
    float median = (first + second)/2.0;
    if(median - (int)median >= 0.5)
      return ((int)median + 1);
    else
      return (int)median;
  }
  else{
  	return((int)*(arrayElement + (SIZE/2)));
  }
}

void sort_array (unsigned int arrayLength, unsigned char *arrayElement) {
  for(int i=0;i<SIZE-1;i++){
    int largest = (int)*(arrayElement + i);
    for(int j=i+1;j<SIZE;j++){
    	if((int)*(arrayElement + j) > largest){
    		largest = (int)*(arrayElement + j);
    		*(arrayElement + j) = *(arrayElement + i);
    		*(arrayElement + i) = largest;
    	}
    }
  }
}

void print_array (unsigned int arrayLength, unsigned char *arrayElement) {
  for(int i=0;i<SIZE;i++){
  	printf("\tElement %d --> %d\n", i, (int)(*(arrayElement + i)));
  }
}

void print_statistics (int maximum, int minimum, int mean, int median) {
  printf("The minimum element of the array is: %d\n", minimum);	
  printf("The maximum element of the array is: %d\n", maximum);	
  printf("The mean of the array is: %d\n", mean);	
  printf("The median of the array is: %d\n", median);	
}