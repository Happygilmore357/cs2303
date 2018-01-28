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
 *
 * @return 0 if grid from file is smaller or equal to given dimensions, 1 if larger.
 */
int verifyFileSize(FILE *input, int givenRows, int givenColumns) {

	return 0;
}

// Func to read in file char by char, ignoring ' ', '\0', and moving to next row at '\n'
// replaces x with 1 and O with 0
// this way can add up neighbors to see if live or die

/** Parses input file to generate initial game board
 *
 * @param input Stream for input file
 *
 * @return 0 if successful, 1 if failed.
 */
int parseFile(FILE *input) {

	return 0;
}
