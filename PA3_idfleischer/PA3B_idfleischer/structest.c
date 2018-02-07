#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	srand(time(0)); // Reset rand seed so new data every run

	int n = 2; // Number of Employee structs to put into the pointer arrays

	// Initialize pointers to structs and arrays of pointers

	struct Employee *e, *i, *j;
	struct Employee** k;
	struct Employee** l;
	struct Employee** m;

	// Demonstrate makeEmployee() and makeRandEmployee()
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	i = makeEmployee(1999, 2016, "Isaiah Fleischer");
	j = makeRandEmployee();

	printf("\nFirst employee, made with makeEmployee(): \n");
	printEmployee(e);
	printf("\nSecond employee, made with makeEmployee(): \n");
	printEmployee(i);
	printf("\nThird employee, made with makeRandEmployee(): \n");
	printEmployee(j);

	// Demonstrate makeMultEmployees() and printMultEmployees()
	k = makeMultEmployees(n);
	printf("\nPrinting original employees array made with makeMultEmployees()\n");
	printMultEmployees(k, n);

	// Demonstrate dupEmployees()
	l = dupEmployees(k, n); // l is a shallow copy of k
	printf(
			"\nPrinting shallow copied array of pointers using dupEmployees()\n");
	printMultEmployees(l, n);

	// Demonstrate dupEmployeesDeep()
	m = dupEmployeesDeep(k, n); // m is a deep copy of k
	printf(
			"\nPrinting deep copied array of pointers using dupEmployeesDeep()\n");
	printMultEmployees(m, n);

	printf(
			"\nAddresses of:\nOriginal array: %p\nShallow copied array: %p\nDeep copied array: %p\n",
			k, l, m);

	printf("\nAddresses of first elements of:\nOriginal array: %p\nShallow copied array: %p\nDeep copied array: %p\n", k[0], l[0], m[0]);
	printf("\nNotice shallow copy and original point to same address, deep points to a different one.\n");

	// Free Employee structs
	free(e);
	free(i);
	free(j);

	freeStructs(k, n);
	free(l);
	freeStructs(m, n);

	return 0;
}
