/*
 * my_add program reads two operands from the user, print them, prints their binary representation
 * then adds them in a binary way one binary digit anfter the other. Then prints the sum binary representation
 * and prints the final result regularly.
 *
 */


#include "my_add.h"

#define MAX_BINARY_LENGTH 20 // maximal binary representation of 999999 * 2


int main() {
	unsigned int first_operand;

	unsigned int second_operand;
	int scanf_value;


	printf("Please insert first operand:\n");
	first_operand = 0;
	scanf_value = scanf("%u", &first_operand);
	if (scanf_value != 1) {
		printf("The user has not entered a valid unsigned integer\n");
		return -1;
	}
	else {
		printf("First operand received: %u\n",first_operand);
	}

	printf("Please insert second operand:\n");
	second_operand = 0;
	scanf_value = scanf("%u", &second_operand);
	if (scanf_value != 1) {
		printf("The user has not entered a valid unsigned integer\n");
	}
	else {
		printf("Second operand received: %u\n",second_operand);
	}

	printf("Now call the my_add function.\n");
	unsigned int added_value = my_add(first_operand,second_operand);

	printf("Finally: I've added %u and %u and got the result of %u.\n",first_operand,second_operand, added_value);
	return 0;

}


unsigned int my_add(unsigned int a, unsigned int b) {
	unsigned int result = 0;
	unsigned int bit_a = 0;
	unsigned int bit_b = 0;
	unsigned int new_bit = 0;
	unsigned int carry = 0;

	/* printing the numbers values in binary representation */
	printf("(my_add function) first operand binary representation: ");
	binary_print(a);
	printf("\n(my_add function) second operand binary representation: ");
	binary_print(b);
	printf("\n");


	for (int i=0; i<MAX_BINARY_LENGTH; i++) { /* iterating over numbers right to left */
		bit_a = (a & (1 << i)) >> i;
		bit_b = (b & (1 << i)) >> i;

		if (bit_a & bit_b) {
			new_bit =carry;
			carry = 1;
		} else if (bit_a | bit_b) {
			if (carry) {
				new_bit = 0;
				carry = 1;
			} else {
				new_bit = 1;
			}
		} else {
			new_bit = carry;
			carry = 0;
		}

		result = result | (new_bit << i);
	}

	printf("(my_add function) the added value (returned) in binary representation: ");
	binary_print(result);
	printf("\n");

	return result;
}


void binary_print(unsigned int n) {
	for (int i=MAX_BINARY_LENGTH; i>=0; i--) { // iterating left to right printing each char
		printf("%u", (n & (1 << i))>>i);
	}

}
