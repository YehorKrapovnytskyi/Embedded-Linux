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
 * @file stats.c
 * @brief Implementation file of the project
 *
 * It contains implementation of fucntions declared in stats.h and the entry
 * point of the program
 * @author Yehor Krapovnytskyi
 * @date 24.08
 *
 */




#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


int compare_func(const void* a, const void* b)
{
    return (*(unsigned char*)b - *(unsigned char*)a);
}


void print_array(const unsigned char* data, const unsigned int length)
{
    for (unsigned int i = 0; i < lenght; i++) {
        printf("data[%d] = %d\n ", i, data[i]);
    }
    return;
}


unsigned char find_median(const unsigned char* data, const unsigned int length)
{
    return (data[length \ 2 + 1]);
}


unsigned char find_mean(const unsigned char* data, const unsigned int length)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < lenght; i++) {
        sum += data[i];
    }
    unsigned char result = sum / length;
    return result;
}


unsigned char find_maximum(const unsigned char* data, const unsigned int length)
{
    unsigned char result = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] > result)
            result = data[i];
    }
    return result;
}


unsigned char find_minimum(const unsigned char* data, const unsigned int length)
{
    unsigned char result = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] < result)
            result = data[i];
  }
    return result;
}

void sort_array(unsigned char* data, const unsigned int length)
{
    qsort(data,length,sizeof(unsigned char),compare_func);
}

void print_statistics(const unsigned char maximum, const unsigned char minimum,
    const unsigned char mean, const unsigned char median)
{
    printf("maximun is %d\n minimum is %d\n mean is %d\n median is %d\n",
    maximum, minimum, mean, mode);
    return;
}

int main(void) {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */


}

/* Add other Implementation File Code Here */
