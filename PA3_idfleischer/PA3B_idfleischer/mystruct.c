/** mystruct.c
 * @author Mike Ciaraldi
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {

	struct Employee *e = malloc(sizeof(struct Employee));

	e->birth_year = birth;
	e->start_year = start;
	strcpy(e->name, name);

	return e; // Replace this with a pointer to the allocated struct
}


/** Make an Employee struct with random data
 * @return Pointer to struct
 */
struct Employee* makeRandEmployee(void) {

	int randBirth = randInt(1000); // Rand birth year 0-1000
	int randStart = randInt(1000); // Rand start year 0-1000
	char* randName = randString(MAX_NAME); // Rand name 100 chars long

	struct Employee* e = makeEmployee(randBirth, randStart, randName); // Make employee struct with data

	free(randName); // Free data

	return e;
}


/** Make array of pointers to Employee structs with random data
 * @param count Number of Employees to make
 * @return e Pointer to array of pointers of structs
 */
struct Employee** makeMultEmployees(int count) {

	struct Employee** e = malloc(sizeof(struct Employee*) * count); // Allocate an array for the pointers

	/* Iterate through array, generating pointer to random Employee for each element
	 * e[i] must be a valid pointer to an Employee struct because it is within the bounds of the array
	 * Increments index in array by 1 each loop
	 */
	for(int i = 0; i < count; i++) {
		e[i] = makeRandEmployee();
	}

	return e; // Return array of pointers
}


/** Duplicate array of pointers to Employee structs
 * @param src Pointer to array of pointers
 * @param count Number of pointers in the array
 * @return Pointer to duplicate array of pointers
 */
struct Employee **dupEmployees(struct Employee** src, int count) {

	struct Employee** dest = malloc(sizeof(struct Employee*) * count); // Allocate an array for the pointers

	/* Iterate through array, setting corresponding pointer in src to pointer in dest
	 * src[i] must be a valid pointer to an Employee struct because it is within the bounds of the array
	 * Increments index in array by 1 each loop
	 */
	for(int i = 0; i < count; i++) {
		dest[i] = src[i];
	}

	return dest; // Return array of pointers
}


/** Makes a deep copy of an array of pointers to Employee structs
 * @param src Pointer to array of pointers
 * @param count Number of Employee struct pointers in the array
 * @return Pointer to new array of pointers of copied Employee structs
 */
struct Employee **dupEmployeesDeep(struct Employee** src, int count) {

	struct Employee** dest = malloc(sizeof(struct Employee*) * count); // Allocate an array for the pointers

	for(int i = 0; i < count; i++) {
		struct Employee*  srcEmployee = src[i];

		int tempBirth = srcEmployee->birth_year;
		int tempStart = srcEmployee->start_year;
		char* tempName = srcEmployee->name;

		struct Employee* tempEmployee = makeEmployee(tempBirth, tempStart, tempName);

		dest[i] = tempEmployee;
	}

	return dest; // Return array of pointers to new Employee structs
}


/** Frees the memory for all of the Employee structs being pointed to by an array of pointers
 * @param e Array of pointers to structs
 * @param count Number of pointers in the array
 * @return 0 if successful
 */
int freeStructs(struct Employee** e, int count) {

	/* Iterate through array, freeing each struct
	 * e[i] must be a valid pointer to an Employee struct because it is within the bounds of the array
	 * Increments index in array by 1 each loop
	 */
	for(int i = 0; i < count; i++) {
		free(e[i]); // Free Employee struct pointed to by e[i]
		//free(e[i]);
	}

	return 0;
}


/** Prints the contents of Employee struct
 * @param e Pointer to Employee struct
 * @return 0 if successful
 */
int printEmployee(struct Employee *e) {

	printf("\nBirth year: %d\n", e->birth_year); // Print birth year
	printf("Start year: %d\n", e->start_year); // Print start year
	printf("Employee name: %s\n", e->name); // Pritn name

	return 0;
}


/** Print each employee in an array of pointers to employee structs
 * @param e Array of pointers to Employee structs
 * @param count Number of employees in e
 * @return 0 if successful
 */
int printMultEmployees(struct Employee** e, int count) {

	/* Iterate through employees array, printing each employee
	 * e[i] must be a valid pointer to an Employee struct because it is within the bounds of the array
	 */
	for(int i = 0; i < count; i++)
		printEmployee(e[i]);

	return 0;
}


/** Generate a random int with a maximum bound
 * @param max Max int to generate
 * @return Generated int
 */
int randInt(int max) {
	int i = rand() % (max + 1); // Rand int from 0 to max
	return i;
}


/** Generates random printable character
 * @return Generated char
 */
char randChar(void) {
	char c = randInt(93) + 33; // Cast random int from 33-126 to ASCII char
	return c;
}


/** Generates a random string of a given length
 * @param length Length of string to generate
 * @return Pointer to string
 */
char* randString(int length) {
	char* c; // Pointer to string

	c = (char*) malloc(sizeof(char) * (length + 1)); // Allocate memory for length chars + '\0'

	char* cIndex = c; // Pointer to use as index

	/*Generate length random chars, putting them into the string
	 * The index will always be within the bounds of the string because it goes from 0 to length
	 * Increment i and the indexing pointer every loop
	 */
	for (int i = 0; i < length; i++, cIndex++)
		*cIndex = randChar();

	*cIndex = '\0'; // Make sure final char is null terminator

	return c;
}
