/******************************************************************************
 * Copyright (C) 2020 by Pablo Castro
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief This file contains the function declarations for the stats.c file
 *
 * The functions for the stats.c file are declared here. They are find_minimum,
 * find_maximum, find_mean, find_median, sort_array, print_array and print_statistics
 *
 * @author Pablo Castro
 * @date July 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Returns the element with the lowest value in an array
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. The element whose value is the
 * lowest in the entire array is returned.
 *
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return A 32-bit integer representing the lowest element in the array
 */
int find_minimum (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Returns the element with the largest value in an array
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. The element whose value is the
 * largest in the entire array is returned.
 *
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return A 32-bit integer representing the largest element in the array
 */
int find_maximum (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Returns the mean value of an array
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. The mean of the array is returned
 * rounded down to the nearest integer.
 *
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return A 32-bit integer representing the mean of the array
 */
int find_mean (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Returns the median of an array
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. The median of the array is returned
 * rounded down to the nearest integer
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return A 32.bit integer representing the median of the array
 */
int find_median (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Sorts an array from largest to lowest value
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. The array is then ordered in descending
 * order, meaning that the first element is the one with the largest value 
 * in the array and last element is the one with the lowest value.
 *
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return This function does not return anything because the array is sorted
 * using pointers
 */
void sort_array (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Prints all the elements of an array
 *
 * This function takes as input the length of an array and a pointer 
 * to the first element of the array. Each of the elements of the 
 * array is then printed on screen.
 *
 * @param arrayLength A 32-bit integer representing the length of the array
 * @param *arrayElement A pointer to the first element of the array
 *
 * @return This function does not return anything because the array is printed 
 * using pointers
 */
void print_array (unsigned int arrayLength, unsigned char *arrayElement);

/**
 * @brief Prints the mean, median, minimum and maximum values of an array
 *
 * This function takes as input the output of the find_minimum, find_maximum, 
 * find_mean and find_median functions and proceeds to print them on screen.
 *
 * @param maximum A 32-bit integer representing the maximum value of the array
 * @param minimum A 32-bit integer representing the minimum value of the array
 * @param mean A 32-bit integer representing the mean of the array
 * @param median A 32-bit integer representing the median of the array
 *
 * @return This function does not return anything because the values are
 * printed to the screen 
 */
void print_statistics (int maximum, int minimum, int mean, int median);

#endif /* __STATS_H__ */
