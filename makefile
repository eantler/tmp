
all: palindrome

palindrome: palindrome.h palindrome.c
	gcc -Wall -ansi -pedantic -o palindrom palindrome.c 

clean:
	rm *.o 