/*
 *  Palindrome header file
 *
 *  This program reads a string input from the user and returns an answer if that string is a polindrome or not.
 *  The program uses polindrome function.
 *
 */

#ifndef PALINDROME_H_
#define PALINDROME_H_

#include <stdio.h>
#include <string.h>


/*
 * function polindrome(buff,start_ptr,end_ptr) performs a recursive test if a string is a polindrome
 * buff - pointer to buffer
 * start_ptr - value of string starting point
 * end_ptr - value of ending point
 *
 * returns 1 if polidrome and 0 otherwise
 * an empty string is a polindrome
 */

int polindrome(char* buff, int start_ptr, int end_ptr);



#endif /* PALINDROME_H_ */
