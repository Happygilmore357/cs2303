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
	 */
	for(int i = 0; i < count; i++) {
		e[i] = makeRandEmployee();
	}

	return e; // Return array of pointers
}



//struct Employee **dupEmployees(struct Employee** src, int count);
//struct Employee **dupEmployeesDeep(struct Employee** src, int count);

//int freeStructs(struct Employee** e, int count);


/** Prints the contents of Employee struct
 * @param e Pointer to Employee struct
 * @return 0 if successful
 */
int printEmployee(struct Employee *e) {

	printf("Birth year: %d\n", e->birth_year);
	printf("Start year: %d\n", e->start_year);
	printf("Employee name: %s\n", e->name);

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
