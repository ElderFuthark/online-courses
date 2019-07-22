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
 * @brief Contains function definitions for prototypes in stats.h
 * @author Elder Futhark
 * @date 7/21/19
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

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char test[]) {
    // Printf array stats in a tabular form.
    printf("Mean\tMedian\tMaximum\tMedian\n"
          "%u\t%u\t%u\t%u\t",
          find_median(test, SIZE),
          find_mean(test, SIZE),
          find_maximum(test, SIZE),
          find_minimum(test, SIZE));
}
void print_array(unsigned char test[], int length) {
    int i;
    // Interate through array and print values.
    for(i = 0; i < length; i++) {
        printf("Index %d: %u\n", i, test[i]);
    }
}
unsigned char find_median(unsigned char test[], int length) {
 return '0';
}
unsigned char find_mean(unsigned char test[], int length) {
 return '0';
}
unsigned char find_maximum(unsigned char test[], int length) {
 return '0';
}
unsigned char find_minimum(char test[], int length) {
 return '0';
}
