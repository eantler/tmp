/*
 * my_set.c
 *
 * Implementation of excersize 12 in course 20465
 * Student: 201194495
 *
 * This program use two function get_set and print_set to read an unbounded series of
 * integer elements and returns a distinct set of them ordered by its input order.
 *
 * We assume a valid input and that the maximum number of distinct values is smaller or
 * equal to 64 (marked by constant MAX_SET_SIZE in the header file.
 *
 */


#include "my_set.h"


int main() {

	int returned_set[MAX_SET_SIZE];
	int read_elements_count;
	read_elements_count = get_set(returned_set);

	printf("Read total of %d distinct elements.\n", read_elements_count);
	printf("Elements are: ");

	print_set(returned_set, read_elements_count);

	return 0;

}


int get_set(int * set_array) {
	/*
	 * In order to implement the set I am using here a plain integer array and another array to indicate which
	 * fields are occupied.
	 * It is easier to use it and meets the performance requirements because:
	 *    1. We know the number of distinct elements is limited by M distinct values (here M=MAX_SET_SIZE=64).
	 *    2. It means that for every operation we make no more than M actions, meaning O(1).
	 *    3. for N inputs we make O(N) operations (or O(M*N) but for a fixed M it's O(1 * N)).
	 *    4. Iterating over a fixed set is easy access w/o the need to interate through like in array list
	 *
	 * I need the indicating array because NULL is like 0 in C;
	 *
	 * If distinct values were'nt fixed I would use a hash table with the appropriate hash function and a
	 * linked list or alternatevly a balances binary tree (like red-black tree) to keep what's in the set
	 * and another array list to keep their order (always keeping a pointer to the last and
	 * only iterating through in order to print).
	 *
	 */
	int scanf_value, scanf_result, i, exists_flag;
	int zero_indicator = -1; /* we want to allow 0 as an input. */
	int counter = 0; /* counter of number of input elements */

	nullify_array(set_array); /* clean the array */

	printf("Please start inserting integers seperated by ' ' or by a newline '\\n':\n");
	scanf_value = scanf("%d",&scanf_result);

	while (scanf_value != -1) {

		if (scanf_value == 1) {
			printf("Successful read of integer: %d\n",scanf_result);
			i = 0;
			exists_flag = 0;
			while (i < MAX_SET_SIZE && !exists_flag) { /* iterating over the array */
				if (set_array[i] == '\0' && i != zero_indicator) {
					/* if we got to an empty cell, insert our value there. */
					set_array[i] = scanf_result;
					if (scanf_result == 0) zero_indicator = i; // set 0 indicator if that's the input.
					exists_flag = 1;
					counter++;
				} else if (set_array[i] == scanf_result) {
					/* if we are on a non-empty cell that equals out input, step out of loop. */
					exists_flag = 1 ;
				} else {
					/* else we are on a non empty cell != input so we need to move forward in the array. */
					i++;
				}
			}

			/* If we see too many distinct values that we can't store, we just let the user know. */
			if (i==MAX_SET_SIZE && !exists_flag) printf("Too many distinct values in the set so far, so skipping this one"
					" out.\nCan't support more than %d distinct values\n", MAX_SET_SIZE);
		}

		scanf_value = scanf("%d", &scanf_result);
		printf("Scanf value = %d\n",scanf_value);
	}

	return counter;
}

void print_set(int * set_array, int length) {
	int i;
	for (i=0; i<length; i++) {
		if (i>0) printf(" ");
		printf("%d",set_array[i]);
	}
	if (length==0) printf("{} (empty) ");
	printf("\n");
}
void nullify_array(int * array) {
	int i;
	for (i=0; i<MAX_SET_SIZE; i++) {
		array[i] = '\0';
	}
}


