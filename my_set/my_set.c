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
	linked_list * ls;
	ls = create_linked_list();

	if (!ls) {
		printf("Failed to allocate memory so stepping out of the program.");
		exit(-1);
	}

	read_elements_count = get_set(returned_set,ls);
	printf("Received a total input of length %d.\n", list_length(ls));
	printf("This is the input provided:\n");
	print_and_pop(ls);


	printf("Read total of %d distinct elements.\n", read_elements_count);
	printf("Distinct set elements are: ");
	print_set(returned_set, read_elements_count);

	destroy_linked_list(ls);

	return 0;

}


int get_set(int * set_array, linked_list * ls) {
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
	 * We we're later asked to print all the input values at the end of reading input, this is why we're using
	 * a linked list to store them.
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
			if (ls) push(ls,scanf_result); /* if there is a linked list provided then add the result to it */

			i = 0;
			exists_flag = 0;
			while (i < MAX_SET_SIZE && !exists_flag) { /* iterating over the array */
				if (set_array[i] == '\0' && i != zero_indicator) {
					/* if we got to an empty cell, insert our value there. */
					set_array[i] = scanf_result;
					if (scanf_result == 0) zero_indicator = i; /* set 0 indicator if that's the input. */
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
	}

	return counter;
}

void print_set(int * set_array, int length) {
	int i;
	for (i=0; i<length; i++) {
		if (i>0) printf(" ");
		if (i % 10 == 0) printf("\n"); /* newline every 10 values for beauty */
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


linked_list *create_linked_list() {
	linked_list * returned_pointer;
	returned_pointer = (linked_list *)malloc(sizeof(linked_list));
	if (!returned_pointer) return NULL; /* allocation failed */
	returned_pointer->first_node = NULL;
	returned_pointer->last_node = NULL;
	returned_pointer->length = 0;
	return returned_pointer;
}

void destroy_linked_list(linked_list * ls) {

	/* iterating over the list freeying any unfree'd nodes */
	node * next_node;
	node * current_node;
	next_node = ls->first_node;

	while (next_node != NULL) {
		current_node = next_node;
		next_node = next_node->next;
		free(current_node);
	}

	free(ls);

}

node * push(linked_list * ls, int value) {
	node * last_node;
	node * new_node;
	last_node = ls->last_node;

	new_node = (node *)malloc(sizeof(node));
	if(!new_node) return NULL; /* allocation failed */

	if (last_node == NULL) {
		/* this is the first node we're adding */
		ls->first_node = new_node;
		ls->last_node = new_node;
	} else {
		last_node->next = new_node;
		ls->last_node = new_node;
	}

	new_node->data = value;
	ls->length++;
	return new_node;
}

int pop_first(linked_list * ls) {
	node * first_node;
	int returned_value;

	first_node = ls->first_node;
	if (first_node == NULL) return -1;
	returned_value = first_node->data;

	if (ls->last_node == first_node) {
		/* list is of length 1 right now */
		ls->last_node = NULL;
		ls->first_node = NULL;
	} else {
		ls->first_node = first_node->next;
	}

	free(first_node);
	ls->length--;
	return returned_value;

}

int not_empty(linked_list * ls) {
	node *first_node;
	first_node = ls->first_node;
	if (first_node == NULL) return 0;
	return 1;
}

void print_and_pop (linked_list * ls) {
	int value;
	int print_counter;
	print_counter=0;

	while (not_empty(ls)) {
		value = pop_first(ls);
		if (print_counter>0) printf(" ");
		if (print_counter % 10 == 0) printf("\n"); /* newline for beauty */
		print_counter++;
		printf("%d", value);
	}
	printf("\n");
}

int list_length(linked_list * ls) {
	return ls->length;
}
