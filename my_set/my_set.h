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
 *  We we're later asked to print all of the input also at the end of the program.
 *  Because input in not limited in length we need to have a dynamic datastructure.
 *  Here we define the linked list structure and interface which will be used for that.
 *
 *  Because most insertions always happen at the end of array, I choose to hold a pointer
 *  to that as well.
 */

typedef struct node {
   int data;
   struct node *next;
} node;

typedef struct {
	 node *first_node;
	 node *last_node;
	 int length;
} linked_list;

/*
 * Functions that will be used to manage that list.
 */

/*
 * linked_list *create_liked_list()
 * Allocates a new linked_list datastruncture and returns a pointer to in.
 * If memory allocation fails, returns null.
 *
 */
linked_list *create_linked_list();

/*
 * destory_linked_list(linked_list * ls)
 * @param ls - the linked list pointer to be destoryed.
 *
 * This function expect ls to be an initiated linked_list.
 * It frees all memory related to that linked_list.
 *
 */

void destroy_linked_list(linked_list * ls);


/*
 * int push(linked_list * ls, int value);
 *
 * Function pushes a new value into the linked list.
 *
 * @params
 * linked_list * ls - pointer to the linked list we need to push into
 * int value - the value we need to push into the list
 *
 * @return
 * If succesful then a pointer to the node that was added.
 * Else NULL.
 *
 */

node * push(linked_list * ls, int value);


/*
 * int pop_first(linked_list * ls);
 *
 * Functions pops out the first item in the linked list ls.
 * If frees memory related to that node.
 *
 * @param
 * linked_list * ls - pointer to the linked list
 *
 * @return
 * the value stores in the first place.
 * If first place is null returns -1 (expects there to be a real value.
 *
 */

int pop_first(linked_list * ls);

/*
 * int not_empty(linked_list * ls)
 *
 * Returns 1 if list is not empty, else returned 0
 *
 * @param
 * linked_list * ls - pointer to list
 */

int not_empty(linked_list * ls);

/*
 * void print_and_pop
 *
 * Functions prints linked_list elements start to end poping them out of the array list.
 *
 * @params
 * linked_list * ls - the list to be printed
 */

void print_and_pop(linked_list * ls);

/*
 * int list_length(linked_list * ls)
 *
 * Functions returns the list length
 *
 * @params
 * linked_list * ls - the list
 *
 */

int list_length(linked_list * ls);

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
 * We we're later asked to print all input also at the end of everything so we will be recording
 * all  input using a linked list.
 *
 * params:
 * int * set_array: integers array of length MAX_SET_SIZE
 * linked_list * ls: linked_list that will hold all the inputs to print in the end (OPTIONAL)
 *
 * returns: # of elements read from stdin
 *
 */
int get_set(int * set_array, linked_list * ls);

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
