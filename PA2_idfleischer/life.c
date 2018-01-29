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
	int *maxRow; // Max row number in file
	int *maxColumn; // Max column number in file

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
		if (strcmp(argv[6], "y") == 0) { // Check if doPause is "y", if so, set doPause to 1
			doPause = 1;
		} else { // All other cases set it to 0
			doPause = 0;
		}
	case 6:
		if (strcmp(argv[5], "y") == 0) { // Check if doPrint is "y", if so, set doPrint to 1
			doPrint = 1;
		} else { // All other cases set doPrint to 0 and doPause to 0
			doPrint = 0;
			doPause = 0;
		}
	case 5:
	default:
		inputFileName = argv[4]; // File name
		gens = atoi(argv[3]); // Max number of generations to run
		columns = atoi(argv[2]); // Number of columns on the board
		rows = atoi(argv[1]); // Number of rows on the board

		// Board size is playable area + walls on either size
		boardSizeRows = rows + 2;
		boardSizeColumns = columns + 2;
		break;

	}

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

	// Open the file, checking to make sure it succeeded
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	// Allocate memory for maxRow and maxColumn
	maxRow = (int *) malloc(sizeof(int *));
	maxColumn = (int *) malloc(sizeof(int *));

	//int fileSizeReturn;

	// Verify the file's board is smaller or equal in size to the grid defined in the program arguments
	int fileSizeReturn = verifyFileSize(input, rows, columns, maxRow,
			maxColumn);
	if (fileSizeReturn) {
		printf("File size is larger than grid defined in program arguments");
		return 1;
	}

	// Calculate offsets to center the file on the board
	int rowOffset = (rows - *maxRow) / 2;
	int columnOffset = (columns - *maxColumn) / 2;

	// Initialize all grids to be full of 0's
	initGrid(new, boardSizeRows, boardSizeColumns);
	initGrid(old, boardSizeRows, boardSizeColumns);
	initGrid(superOld, boardSizeRows, boardSizeColumns);

	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	// Parse the file, placing data into grid "old"
	int parseReturn = parseFile(input, old, rowOffset, columnOffset);
	if (parseReturn) {
		printf("File parsing failed\n");
		return 1;
	}

	// Free memory for maxRow and maxColumn
	free(maxRow);
	free(maxColumn);

	// If doPrint, print the initial grid
	if (doPrint) {
		printf("\nInitial state:\n");
		print2Dint(old, rows, columns);
		printf("\n");
	}

	// Check if file was all o's
	if (checkAllDead(old, rows, columns)) {
		printf("Game ended because all organisms were dead in initial state.");
		return 0;
	}

	/* Play through game of life one generation at a time
	 * LOOP INVARIANT: The generation must always be in the range: 1 to the number of generations defined
	 * PRE-CONDITION: Starts at generation 1
	 * POST-CONDITION: Finishes after it's played number of generations specified
	 */
	for (int gen = 1; gen <= gens; gen++) {

		// Wait for user input if doPause is enabled
		if (doPause) {
			fgetc(stdin);
		}

		printf("Gen %d:\n", gen);

		// Play one round of game of life
		playOne(old, new, rows, columns);

		// Print current board if doPrint enabled
		if (doPrint) {
			print2Dint(new, rows, columns);
			printf("\n");
		}

		// Check if all organisms are dead
		if (checkAllDead(new, rows, columns)) {
			printf(
					"Game ended in %d generation(s) because all organisms died.\n",
					gen);
			return 0;

			// Check if current and previous generations are the same
		} else if (!compare2Dint(new, old, rows, columns)) {

			printf(
					"Game ended in %d generation(s) because it reached a steady state.\n",
					gen);
			return 0;

			// Check if current board is same as the board 2 generations ago
		} else if (!compare2Dint(new, superOld, rows, columns)) {
			printf(
					"Game ended in %d generation(s) because it reached an oscillatory state.\n",
					gen);
			return 0;
		}

		//Shuffle the pointers so each board gets moved back a stage and "new" gets the oldest board
		int **tempArr;
		tempArr = superOld;
		superOld = old;
		old = new;
		new = tempArr;
	}

	// Max number of generations reached
	printf("Game ended in %d generation(s)\n", gens);
	return 0;

	// Free memory allocated to grids
	free(new);
	free(old);
	free(superOld);

	return EXIT_SUCCESS;
}
