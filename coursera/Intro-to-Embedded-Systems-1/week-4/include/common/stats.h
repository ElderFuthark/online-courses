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
 * @brief Contains function prototypes for program functions found in main.c
 * @author Elder Futhark
 * @date  July, 21, 2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/*
* @func: print_statistics()
* @brief: Prints statistics of an array. These include the minimum, maximum, mean, and median.
* @params: a char array.
* @returns: void
*/

void print_statistics(unsigned char *test);

/*
* @func: print_array()
* @brief: Prints a given array.
* @params: a char array and its length in integer form.
* @returns: void
*/

void print_array(unsigned char *test, int length);

/*
* @func: find_median()
* @brief: Finds the median of a char array.
* @params: a char array and its length in integer form.
* @returns: median (cast as char)
*/

unsigned char find_median(unsigned char *test, int length);

/*
* @func: find_mean()
* @brief: Finds the mean of a char array.
* @params: a char array and its length in integer form.
* @returns: mean (cast as char)
*/

unsigned char find_mean(unsigned char *test, int length);

/*
* @func: find_maximum()
* @brief: Finds the maximum of a char array.
* @params: a char array and its length in integer form.
* @returns: maximum (largest ASCII value cast as char)
*/

unsigned char find_maximum(unsigned char *test, int length);

/*
* @func: find_minimum()
* @brief: Finds the minimum of a char array.
* @params: a char array and its length in integer form.
* @returns: minimum (smallest ASCII value cast as char)
*/

unsigned char find_minimum(unsigned char *test, int length);

#endif /* __STATS_H__ */
