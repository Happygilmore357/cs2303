/*
 * readFile.c
 *
 *  Created on: Jan 27, 2018
 *      Author: isaiah
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

	int currentRow = 0;
	int currentColumn = 0;

	char tempChar = fgetc(input);

	while (tempChar == ' ' || tempChar == '\n')
		tempChar = fgetc(input);

	while (tempChar != EOF) {

		if (tempChar == 'x' || tempChar == 'o' || tempChar == 'O'
				|| tempChar == 'X') {
			currentColumn++;
			//printf("%d", tempChar == 'x');
			printf("%c", tempChar);
		} else if (tempChar == '\n') {
			if (currentColumn > *maxColumn) {
				*maxColumn = currentColumn;
				currentColumn = 0;
				currentRow++;
				printf("%c", tempChar);
			}
		} else {
			printf("Weird type: %c", tempChar);
		}

		tempChar = fgetc(input);

	}
	*maxRow = currentRow + 1;
	printf("\n");

	if (*maxRow > givenRows || *maxColumn > givenColumns) {
		return 1;
	}

	return 0;
}

// Func to read in file char by char, ignoring ' ', '\0', and moving to next row at '\n'
// replaces x with 1 and O with 0
// this way can add up neighbors to see if live or die

/** Parses input file to generate initial game board
 *
 * @param input Stream for input file
 * @param rowOffset Offset to center input data vertically
 * @param columnOffset Offset to center input data horizontally
 *
 * @return 0 if successful, 1 if failed.
 */
int parseFile(FILE *input, int **firstGrid, int boardSizeRows, int boardSizeColumns, int rowOffset, int columnOffset, int *maxRow) {

	char tempChar = fgetc(input);
	int equivInt = 0;
	printf("%d\n", rowOffset+1);
	for (int row = (rowOffset + 1); (row < boardSizeRows - 1) || (row < *maxRow); row++) {
		printf("Row: %d", row);
		for (int column = columnOffset + 1; (column < boardSizeColumns - 1) || (tempChar == '\n'); column++) {
			if (tempChar == EOF)
				return 0;
			else if (tempChar == 'x' || tempChar == 'X')
				equivInt = 1;
			else
				equivInt = 0;
			printf("char: %c, int: %d", tempChar, equivInt);
			firstGrid[row][column] = equivInt;
			tempChar = fgetc(input);
		}

	}


	return 0;
}
