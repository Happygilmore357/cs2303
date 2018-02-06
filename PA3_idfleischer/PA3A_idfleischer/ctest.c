#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * Add your own @author line below.
 * @author Isaiah Fleischer
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main() {
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char a4[MAX_CHARS + 1]; // Character array--initially empty
	char a5[MAX_CHARS + 1]; // Character array--initially empty
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;        // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	char* p4 = NULL;        // Will be a pointer to dynamically-allocated string
	char* p5 = NULL;        // Will be a pointer to dynamically-allocated string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
	 Note: this example prints
	 the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("\na1 = %s\n", a1);
	printf("\na2 = %s\n", a2);
	printf("\na3 = %s\n", a3);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("\nFor string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("\nFor string /%s/, mystrlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("\nFor string /%s/, mystrlen2() returns %ld\n", p1, mystrlen2(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup2(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = mystrdup2(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Copy a string using my function then print it
	char* string1 = "Hello"; // String to be copied
	char string2[5]; // Destination string

	printf("\nPointer to original: %p   Pointer to copied:%p\n", string1,
			mystrcpy(string2, string1));
	printf("Original string: %s   Copied string: %s\n", string1, string2);

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("\nUsing strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays using mystrcat(), then print.
	mystrcpy(a1, p3); // Reset character array
	mystrcat(a1, a2);
	printf("\nUsing mystrcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf(
			"\nUsing strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0)
		strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

	mystrcpy(a1, p3);
	// Concatenate two character arrays safely using mystrncat(), then print.
	mystrcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - mystrlen2(a1); // How much space is left?
	printf(
			"\nUsing mystrncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0)
		mystrncat(a1, a3, copy_limit);
	// Reset character arrays
	mystrcpy(a1, p3);
	mystrcpy(a4, p3);
	mystrcpy(a5, p3);

	// Use mystrncat() with all three corner cases
	mystrncat(a1, a3, mystrlen2(a3) - 1);
	printf("\nUsing mystrncat() to concatenate with n < length of src \na1 = %s\n",
			a1);
	mystrncat(a4, a3, mystrlen2(a3));
	printf("\nUsing mystrncat() to concatenate with n == length of src \na4 = %s\n",
			a4);
	mystrncat(a5, a3, mystrlen2(a3) + 1);
	printf("\nUsing mystrncat() to concatenate with n > length of src \na5 = %s\n",
			a5);

	// Copy a string safely using mystrncpy(), then print, showing corner cases
	// Reset arrays
	mystrcpy(a1, p3);
	mystrcpy(a4, p3);
	mystrcpy(a5, p3);

	mystrncpy(a1, a3, mystrlen2(a3) - 1);
	printf("\nUsing mystrncpy() to copy with n < length of src \na1 = %s\n",
			a1);
	mystrncpy(a4, a3, mystrlen2(a3));
	printf("\nUsing mystrncpy() to copy with n == length of src \na4 = %s\n",
			a4);
	mystrncpy(a5, a3, mystrlen2(a3) + 1);
	printf("\nUsing mystrncpy() to copy with n > length of src \na5 = %s\n",
			a5);

	// Duplicate a string safely, using strndup(), then print, showing corner cases
	// Reset pointer "p2" each time
	printf("\nBefore calling strndup(), pointer a2 = %p, contents = %s\n", a2,
			a2);

	p3 = NULL;
	p3 = strndup(a2, mystrlen2(a2) - 1);
	printf("\nDuplicated string with n < length of a2: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	p4 = NULL;
	p4 = strndup(a2, mystrlen2(a2));
	printf("\nDuplicated string with n == length of a2: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	p5 = NULL;
	p5 = strndup(a2, mystrlen2(a2) + 1);
	printf("\nDuplicated string with n > length of a2: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	free(p2);
	free(p3);
	free(p4);
	free(p5);


	return 0;
}
