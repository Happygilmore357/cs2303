/* Game of Life
 * FILE: life.c
 * TEMPLATE WRITTEN BY: Mike Ciaraldi
 * MODIFIED BY: Isaiah Fleischer
 */

#include <stdio.h>
#include <stdlib.h>
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
	int doPrint; // 1 if user wants to print each generation, 0 if not
	int doPause; // 1 if user wants to pause after each generation, 0 if not
	int **gridA; // A 2D array to hold the pattern
	int **gridB; // A 2D array to hold the pattern
	int **gridC; // A 2D array to hold the pattern

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
		doPause = atoi(argv[6]); // Convert from character string to integer. // Should be n if no print or left out
	case 6:
		doPrint = atoi(argv[5]); // should be n if left out
	case 5:
	default:
		inputFileName = argv[4];
		gens = atoi(argv[3]);
		columns = atoi(argv[2]);
		rows = atoi(argv[1]);

		// Board size is playable area + walls on either size
		boardSizeRows = rows + 2;
		boardSizeColumns = columns + 2;
		break;

	}

	// Allocate memory to hold 3 grids, checking to make sure each succeeded
	gridA = make2Dint(boardSizeRows, boardSizeColumns);
	if (!gridA) {
		printf("malloc() failed when creating GridA");
		return 1;
	}
	gridB = make2Dint(boardSizeRows, boardSizeColumns);
	if (!gridB) {
		printf("malloc() failed when creating GridB");
		return 1;
	}
	gridC = make2Dint(boardSizeRows, boardSizeColumns);
	if (!gridC) {
		printf("malloc() failed when creating GridC");
		return 1;
	}

	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	} /*else {
	 for (int line = 0; line < rows; line++) {
	 fgets((gridA[line]), columns, input);
	 }
	 }*/



	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	 */


	return EXIT_SUCCESS;
}
