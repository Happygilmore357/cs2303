/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}


/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}




/** Determines length of string using subscripts
 *
 * @param *s pointer to string to be analyzed
 * @return Number of bytes in input string
 */
size_t mystrlen1(const char *s) {

	int i = 0; // Counter for chars, used to iterate through string and record length

	/* Loops through the string.
	 * Every time it loops the current char can't be the null terminator.
	 * Increment the counter by 1 for every valid char.
	 */
	while(s[i] != '\0') i++;

	return i*sizeof(char); // Return number of bytes used by string
}



/** Determines length of string using incrementing pointers
 *
 * @param *s pointer to string
 * @return Number of bytes in input string
 */
size_t mystrlen2(const char *s) {

	int i = 0; // Counter for chars, used to record length

	/* Loops through the string.
	 * Every time it loops the current char can't be the null terminator.
	 * Increment the counter by 1 and the pointer by 1 to get to the next char.
	 */
	while(*s != '\0') {i++; s++;}

	return i*sizeof(char); // Return number of bytes used by string
}

/* Copies string pointed to by src (including null terminator) to buffer pointed to by dest.
 * dest must be large enough to hold the copy. Does not check for buffer overruns.
 *
 * @param dest Pointer to destination buffer for copied string
 * @param src Pointer to string to be copied
 * @return Pointer to destination buffer
 */
char* mystrcpy(char* dest, const char* src) {

	char* destIndex = dest; // Use this to place chars in dest
	int srcLength = strlen(src)/sizeof(char); // Calculate length of src string


	/* Iterate through source string
	 * setting value of destination to current value of src
	 * Increment src and destIndex pointers each iteration
	 * src must point to within the string or the null terminator (length+1)
	 */
	for (int i = 0; i <= srcLength; i++) {
		*destIndex = *src;
		destIndex++;
		src++;
	}

	return dest;
}
