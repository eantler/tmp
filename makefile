
all: palindrome

palindrome: palindrome.h palindrome.c
	gcc -Wall -ansi -pedantic -o palindrome palindrome.c 
 