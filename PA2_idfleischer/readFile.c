/*
 * FILE: readFile.c
 * AUTHOR: Isaiah Fleischer
 */

#include <stdio.h>
#include <stdlib.h>
#include "life.h"

/** Verify grid from file is smaller or equal in size to dimensions defined in command line arguments.
 * 		 Program will run off arrays if grid is bigger than defined dimensions.
 *
 * @param input Stream for input file
 * @param givenRows Number of rows defined in command line arguments
 * @param givenColumns Number of columns defined in command line arguments
 * @param maxRow Pointer to maximum height of input file
 * @param maxColumn Pointer to maximum width of input file
 *
 * @return 0 if grid from file is smaller or equal to given dimensions, 1 if larger.
 */
int verifyFileSize(FILE *input, int givenRows, int givenColumns, int *maxRow,
		int *maxColumn) {

	*maxRow = 0;
	*maxColumn = 0;

	// Curent row and column it is reading
	int currentRow = 0;
	int currentColumn = 0;

	// Get a char from the file
	char tempChar = fgetc(input);

	// Skip all extraneous newlines and spaces
	while (tempChar == ' ' || tempChar == '\n')
		tempChar = fgetc(input);

	// LOOP INVARIANT: char read from the file must not be EOF, or it stops
	while (tempChar != EOF) {
		// If it sees an x, X, o, or O, move over 1 column
		if (tempChar == 'x' || tempChar == 'o' || tempChar == 'O'
				|| tempChar == 'X') {
			currentColumn++;
			// If it sees a newline
		} else if (tempChar == '\n') {
			// Check if this is the max column found in the file
			if (currentColumn > *maxColumn) {
				// If so, set maxColumn to the current column number
				*maxColumn = currentColumn;
			}
			// Reset column and move down 1 rows
			currentColumn = 0;
			currentRow++;
		} else {
		}

		tempChar = fgetc(input);

	}

	// Set maxRow to current row
	*maxRow = currentRow;

	// If maxRow or maxColumn are larger than their counterparts defined in the program arguments, return 1, eventually ending the program
	if (*maxRow > givenRows || *maxColumn > givenColumns) {
		return 1;
	}

	return 0;
}

/** Parses input file to generate initial game board
 *
 * @param input Stream for input file
 * @param firstGrid Grid to place first generation
 * @param rowOffset Offset to center input data vertically
 * @param columnOffset Offset to center input data horizontally
 *
 * @return 0 if successful, 1 if failed.
 */
int parseFile(FILE *input, int **firstGrid, int rowOffset, int columnOffset) {

	char tempChar = fgetc(input); // Get the first char in input file

	// Skip all extraneous newlines and spaces
	while (tempChar == ' ' || tempChar == '\n')
		tempChar = fgetc(input);

	int equivInt = 0; // equivInt is used to set each cell

	int row = rowOffset + 1; // Start counting rows after the offset to center the file
	int column = columnOffset + 1; // Start counting columns after the offset to center the file

	// LOOP INVARIANT: char read from the file must not be EOF, or it stops
	while (tempChar != EOF) {
		// If it sees an x or X, place a 1 in the corresponding cell
		if (tempChar == 'x' || tempChar == 'X') {
			equivInt = 1;
			firstGrid[row][column] = equivInt;
			// Move  over 1 column
			column++;
			// If it sees an o or O, place a 0 in the corresponding cell
		} else if (tempChar == 'o' || tempChar == 'O') {
			equivInt = 0;
			firstGrid[row][column] = equivInt;
			// Move over 1 column
			column++;
			// If it sees a newline, reset the column and move down 1 row
		} else if (tempChar == '\n') {
			row++;
			column = columnOffset + 1;
		}

		// Get a new char from the file
		tempChar = fgetc(input);
	}

	return 0;
}
