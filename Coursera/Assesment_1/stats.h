/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
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
 * @brief This file contains declaration of functions used in stats.c
 *
 * It contains declaration of print_array(),print_statistics(), find_median(),
 * find_mean(),find_maximum(),find_minimum() and sort_array().
 *
 * @author Yehor Krapovnytskyi
 * @date 24.08.2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief This function prints the content of unsigned char array
 *
 * It takes an unsigned char array as an input and prints its content using
 * the for loop
 *
 * @param An unsigned char array and its length
 *
 * @return void
 */
 void print_array(const unsigned char* data, const unsigned int length);

 /**
  * @brief Given an array of data and a length, returns the median value
  *
  *
  * Finds the median of unsigned char array by simply returning the element
  * under index (length / 2)
  *
  * @param An unsigned char array and its length
  *
  * @return unsigned char median data of array
  */
 unsigned char find_median(const unsigned char* data, const unsigned int length);

 /**
  * @brief Given an array of data and a length, returns the mean value
  *
  *
  * Finds the mean of unsigned char array by summing all the element , dividing
  * by array length and convering result to unsigned char
  *
  * @param An unsigned char array and its length
  *
  * @return unsigned char mean of array
  */
 unsigned char find_mean(const unsigned char* data, const unsigned int length);

 /**
  * @brief Given an array of data and a length, returns the maximum value
  *
  *
  * Finds maximum of unsigned char array by comparing nearest values in for
  * loop
  *
  * @param An unsigned char array and its length
  *
  * @return unsigned char maximum of array
  */
 unsigned char find_maximum(const unsigned char* data,
    const unsigned int length);

 /**
  * @brief Given an array of data and a length, returns the minumum value
  *
  *
  * Finds minimum of unsigned char array by comparing nearest values in for
  * loop
  *
  * @param An unsigned char array and its length
  *
  * @return unsigned char minumum of array
  */
 unsigned char find_minimum(const unsigned char* data,
    const unsigned int length);

 /**
  * @brief Sorts the array from maximum to minumum
  *
  *
  * The given array is sorted using quick sort algorithm
  *
  *
  * @param An unsigned char array and its length
  *
  * @return void
  */
 void sort_array(unsigned char* data, const unsigned int length);

 /**
  * @brief A compare function for qsort
  *
  *
  * Takes two void pointers as an input, converst into two unsigned char
  * pointers and dereference them to compare two values
  *
  * @param two const void pointers
  *
  * @return integer 1 or 0 value
  */
  int compare_func(const void* a, const void* b);

 /**
  * @brief A function that prints the statistics of an array: minimum,
  * maximum, mean, and median
  *
  * The statistics is printed by using printf with params as atguments
  *
  *
  * @param An unsigned char array's  mean, median,max and min
  *
  * @return void
  */

 void print_statistics(const unsigned char maximum, const unsigned char minimum,
    const unsigned char mean, const unsigned char median);


#endif /* __STATS_H__ */
