/*
 * my_set.h
 *
 * Implementation of excersize 12 in course 20465
 * Student: 201194495
 *
 * This program use two function get_set and print_set to read an unbounded series of
 * integer elements and returns a distinct set of them ordered by its input order.
 *
 * We assume a valid input and that the maximum number of distinct values is smaller or
 * equal to 64 (marked by constant MAX_SET_SIZE in the header.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SET_SIZE 64

#ifndef MY_SET_H_
#define MY_SET_H_

/*
 * void get_set(int * set_array)
 *
 * 1. Function prompts the user to insert input.
 * 2. Reads integers from stdin seperated by ' ' or by \n (newline) until EOF.
 * 	  For every integer it prints the integer that was received.
 * 3. Changes the integer array 'set_array' with distinct elements of the set
 * 	  ordered by their insert order. If less members than the array length other
 * 	  cells will be written with 0.
 * 4. Returns the number of elements that were inserted from the function.
 *
 * Function assumes a valid input of integers other than new line or EOF chars.
 *
 * params:
 * int * set_array: integers array of length MAX_SET_SIZE
 *
 * returns: # of elements read from stdin
 *
 */
int get_set(int * set_array);

/*
 * void print_set(int * set_array, int length)
 *
 * Function prints a set array while iterating through the array
 * for length amount of elements. Seperator is space (' ') and ends with a newline.
 *
 * Function assumes valid input of integers array. len(set_array)>=length.
 *
 * params
 * int length: the set length of the array.
 *
 */
void print_set(int * set_array, int length);

/*
 * void null_array(int * array)
 *
 * Function receives an array of length MAX_SET_SIZE and iterated over it untill
 * all cells are NULL.
 *
 */
void nullify_array(int * array);

#endif /* MY_SET_H_ */
