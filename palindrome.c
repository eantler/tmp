/*
 *  This program reads a string input from the user and returns an answer if this is a polindrome or not using polindrome function.
 */

#include "palindrome.h"

#define BUFFER_SIZE 80 /* Buffer size - max string length */

int main() {
	char buff[BUFFER_SIZE];
	unsigned long length;
	int scanf_value;


	printf("Please insert polindrome-suspected text:");
	scanf_value = scanf("%80[^\n]", buff);

	if (scanf_value != 1) {
		printf("Something went wrong while reading input.\n");
		return -1;
	} else {
		printf("The received text: %s\n",buff);
	}

	length = strlen(buff);
	int is_polindrome = polindrome(buff,0,length-1);

	if (is_polindrome) {
		printf("It is indeed a polindrome ! function returned TRUE");

	} else {
		printf("This is not a polindrome. function returned FALSE");
	}

	return 0;

}




int polindrome(char* buff, int start_ptr, int end_ptr) {

	if (start_ptr == end_ptr) return 1;
	if (buff[start_ptr] == ' ') return polindrome(buff, start_ptr+1,end_ptr); /* excaping spaces */
	if (buff[end_ptr] == ' ') return polindrome(buff, start_ptr,end_ptr-1);
	if (start_ptr == end_ptr - 1) return (buff[start_ptr]==buff[end_ptr]);

	return ((buff[start_ptr]==buff[end_ptr]) & (polindrome(buff,start_ptr+1,end_ptr-1)));


}
