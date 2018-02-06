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


/** Function to determine length of string
 *
 * @param *s pointer to string
 *
 * @return Number of bytes in input string
 */
size_t mystrlen1(const char *s) {

	int i = 0;

	while(s[i] != '\0') i++;

	return i*sizeof(char);
}



/** Function to determine length of string
 *
 * @param *s pointer to string
 *
 * @return Number of bytes in input string
 */
size_t mystrlen2(const char *s) {

	int i = 0;

	while(*s != '\0') {i++; s++;}

	return i*sizeof(char);
}
