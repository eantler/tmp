/*
 * my_add program reads two operands from the user, print them, prints their binary representation
 * then adds them in a binary way one binary digit anfter the other. Then prints the sum binary representation
 * and prints the final result regularly.
 *
 */

#ifndef MY_ADD_H_
#define MY_ADD_H_

#include <stdio.h>
#include <math.h>

/*
 * function my_add(a,b) performs a simulation of add on two unsigned int operands
 * a - first operand (should be an unsigned int)
 * b - second operand
 * returns - results of adding these two operands
 * supports any operand >0 and <= 999,999
 */
unsigned int my_add(unsigned int a, unsigned int b);

/*
 * functions binary_print(n) prints an unsigned int as a binary number without a new line.
 * n - unsigned int input number
 */
void binary_print(unsigned int n);

#endif /* MY_ADD_H_ */
