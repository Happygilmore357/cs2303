#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

/** Make a 2D array of integers
 *
 * @param rows Number of rows
 * @param columns Number of columns
 * @return Pointer to the array of pointers to the rows.
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Mike Ciaraldi
 */

int** make2Dint(int rows, int columns) {

	int **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (int **) malloc(rows * sizeof(int *));
	if (!a) { // Unable to allocate the array
		return (int **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < rows; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(columns * sizeof(int));
		if (!a[i]) {
			return (int **) NULL; // Unable to allocate
		}
	}
	return a;
}

/** Make a 2D array of ints
 *
 * @param rows Number of rows
 * @param columns Number of columns
 * @return Pointer to the array of pointers to the rows
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Mike Ciaraldi
 */
char** make2Dchar(int rows, int columns) {

	char **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (char **) malloc(rows * sizeof(char *));
	if (!a) { // Unable to allocate the array
		return (char **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < rows; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(columns * sizeof(char));
		if (!a[i]) {
			return (char **) NULL; // Unable to allocate
		}
	}
	return a;
}

/** Compare 2 2D arrays of ints
 *
 * @param arr1 Pointer to first array
 * @param arr2 Pointer to second array
 * @param rows Number of rows
 * @param columns Number of columns
 * @return 0 if arrays are identical, 1 if they are different.
 */
int compare2Dint(int **arr1, int **arr2, int rows, int columns) {

	if (!arr1) {
		printf("Invalid pointer to first array");
		return 1;
	}
	if (!arr2) {
		printf("Invalid pointer to second array");
		return 1;
	}

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			if (arr1[row][column] != arr2[row][column]) {
				printf("Arrays different at [%d, %d]\n", row, column);
				return 1;
			}
		}
		//printf("\n");
	}

	return 0;
}

/** Print a 2D array of ints
 *
 * @param arr Pointer to array
 * @param rows Number of rows
 * @param columns Number of columns
 * @return 0 if success, 1 if invalid pointer.
 */
int print2Dint(int **arr, int rows, int columns) {

	if (!arr) {
		printf("Invalid pointer to array for printing");
		return 1;
	}

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			printf("%d", arr[row][column]); //][%d, %d]", arr[row][column], row, column);
		}
		printf("\n");
	}
	printf("Finished printing\n");

	return 0;
}

/** Initialize grid to be all 0's
 *
 * @param arr Pointer to array
 * @param rows Number of rows
 * @param columns Number of columns
 * @return 0 if success, 1 if invalid pointer.
 */
int initGrid(int **arr, int rows, int columns) {

	if (!arr) {
		printf("Invalid pointer to array for printing");
		return 1;
	}

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			arr[row][column] = 0;
		}
	}
	printf("Finished grid init\n");

	return 0;

}

