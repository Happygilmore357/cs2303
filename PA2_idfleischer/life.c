/* Game of Life
 * FILE: life.c
 * TEMPLATE WRITTEN BY: Mike Ciaraldi
 * MODIFIED BY: Isaiah Fleischer
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"
#include "twoD.h"

/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
 */
int main(int argc, char **argv) {
	printf("Game of Life\n");

	char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int rows; // Number of rows in the grid
	int columns; // Number of columns in the grid
	int boardSizeRows; // Number of rows on board (includes walls)
	int boardSizeColumns; // Number of columns on board (includes walls)
	int gens; // Number of generations to produce
	int doPrint = 0; // 1 if user wants to print each generation, 0 if not
	int doPause = 0; // 1 if user wants to pause after each generation, 0 if not
	int **new; // A 2D array to hold the pattern
	int **old; // A 2D array to hold the pattern
	int **superOld; // A 2D array to hold the pattern

	// See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}

	// Save command line arguments
	switch (argc) {
	case 7:
		if (strcmp(argv[6], "y") == 0) {
			doPause = 1;
		} else {
			doPause = 0;
		}
		//doPause = atoi(argv[6]); // Convert from character string to integer. // Should be n if no print or left out
		//doPrint = atoi(argv[5]); // should be n if left out
	case 6:
		if (strcmp(argv[5], "y") == 0) {
			doPrint = 1;
		} else {
			doPrint = 0;
			doPause = 0;
		}
	case 5:
	default:
		//printf("pause: %d, print: %d\n", doPause, doPrint);
		inputFileName = argv[4];
		gens = atoi(argv[3]);
		columns = atoi(argv[2]);
		rows = atoi(argv[1]);

		// Board size is playable area + walls on either size
		boardSizeRows = rows + 2;
		boardSizeColumns = columns + 2;
		break;

	}

	/*if(doPause) {
	 char *tempChar;
	 *tempChar = (char *) malloc(sizeof(char *));
	 }*/

	if (gens <= 0) {
		printf("Number of generations must be greater than 0");
		return 1;
	}

	// Allocate memory to hold 3 grids, checking to make sure each succeeded
	new = make2Dint(boardSizeRows, boardSizeColumns);
	if (!new) {
		printf("malloc() failed when creating new");
		return 1;
	}
	old = make2Dint(boardSizeRows, boardSizeColumns);
	if (!old) {
		printf("malloc() failed when creating old");
		return 1;
	}
	superOld = make2Dint(boardSizeRows, boardSizeColumns);
	if (!superOld) {
		printf("malloc() failed when creating superOld");
		return 1;
	}

	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	int *maxRow = (int *) malloc(sizeof(int *));
	int *maxColumn = (int *) malloc(sizeof(int *));

	int returnVal;
	returnVal = verifyFileSize(input, rows, columns, maxRow, maxColumn);
	//printf("rows: %d, columns: %d, file size fits: %d\n", *maxRow, *maxColumn,
	//returnVal);
	if (returnVal) {
		printf("File size is larger than grid defined in program arguments");
		return 1;
	}

	int rowOffset = (rows - *maxRow) / 2;
	int columnOffset = (columns - *maxColumn) / 2;
	//printf("Offsets: %d, %d\n", rowOffset, columnOffset);
	initGrid(new, boardSizeRows, boardSizeColumns);
	initGrid(old, boardSizeRows, boardSizeColumns);
	initGrid(superOld, boardSizeRows, boardSizeColumns);

	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	returnVal = parseFile(input, old, rowOffset, columnOffset);
	if (doPrint) {
		printf("\nInitial state:\n");
		print2Dint(old, rows, columns);
		printf("\n");
	}
	//playOne(new, old, rows, columns);
	//print2Dint(old, boardSizeRows, boardSizeColumns);

	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	 */

	if (checkAllDead(old, rows, columns)) {
		printf("Game ended because all organisms were dead in initial state.");
		return 1;
	}

	for (int gen = 1; gen <= gens; gen++) {

		if (doPause) {
			fgetc(stdin);
		}

		printf("Gen %d:\n", gen);
		/*superOld = old;
		 old = new;
		 new = superOld;*/

		playOne(old, new, rows, columns);

		/*print2Dint(new, rows, columns);
		 print2Dint(old, rows, columns);
		 print2Dint(superOld, rows, columns);*/

		//printf("new, old, superold\n");
		if (doPrint) {
			print2Dint(new, rows, columns);
			printf("\n");
		}
		//print2Dint(old, rows, columns);
		//print2Dint(superOld, rows, columns);

		if (checkAllDead(new, rows, columns)) {
			printf("Game ended in %d generation(s) because all organisms died.",
					gen);
			return 1;

		} else if (!compare2Dint(new, old, rows, columns)) {

			printf(
					"Game ended in %d generation(s) because it reached a steady state.\n",
					gen);
			return 1;

		} else if (!compare2Dint(new, superOld, rows, columns)) {
			printf(
					"Game ended in %d generation(s) because it reached an oscillatory state.\n",
					gen);
			return 1;
		}

		superOld = old;
		old = new;
		new = superOld;

	}

	printf("Game ended in %d generation(s)\n", gens);
	return 1;

	free(new);
	free(old);
	free(superOld);

	return EXIT_SUCCESS;
}
