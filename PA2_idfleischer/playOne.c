/*
 * FILE: playOne.c
 * AUTHOR: Isaiah Fleischer
 */

#include <stdio.h>
#include <stdlib.h>
#include "life.h"

/** Play 1 turn, testing for repeats and calculating next generation
 *
 * @param superOld Board from turn before previous turn
 * @param old Board from previous turn
 * @param new New board
 * @param rows Number of rows
 * @param columns Number of columns
 * @return 1 if the game has repeated itself
 * 		in the past 2 turns. 0 if board hasn't
 * 	  	repeated itself.
 */
void playOne(int **old, int **new, int rows, int columns) {

	int score; // Number of neighbor organisms alive
	int orgState; // State of current organism, 1 = alive, 0 = dead

	/* Iterate through playable cells, calculating their new state
	 * LOOP INVARIANT: The cell must be in the playable area
	 * PRE-CONDITION: Starts with the cell at upper left of board, [1][1] in the grid
	 * POST-CONDITION: Ends with cell at the bottom right of the board, [n-2][n-2] in the grid
	 */
	for (int row = 1; row < rows + 1; row++) {
		for (int column = 1; column < columns + 1; column++) {

			score = 0; // Reset score to 0

			orgState = old[row][column]; // Get the state of the current organism

			/* Loop through neighbors on top of cell, adding their values to # of alive neighbors
			 * LOOP INVARIANT: Neighbor must be directly above or in the top corners
			 */
			for (int neighborTop = -1; neighborTop < 2; neighborTop++) {
				score += old[row - 1][column + neighborTop];
			}

			/* Loop through neighbors on bottom of cell, adding their values to # of alive neighbors
			 * LOOP INVARIANT: Neighbor must be directly below or in the bottom corners
			 */
			for (int neighborBottom = -1; neighborBottom < 2;
					neighborBottom++) {
				score += old[row + 1][column + neighborBottom];
			}

			// Add horizontal neighbors
			score += old[row][column - 1];
			score += old[row][column + 1];


			switch (score) {
			case 3:
				// Org is born if 3 neighbors
				if (orgState == 0) {
					new[row][column] = 1;
					break;
				} // Falls down to next case if org is alive
			case 2:
				// If org is alive, keep it alive
				if (orgState == 1) {
					new[row][column] = 1;
				break;
				} // If org is dead, fall through bottom
			case 0:
			case 1:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			default:
				// Org dies if it has 0,1,4,5,6,7,8 neighbors
				new[row][column] = 0;
				break;
			}

		}
	}

}

/** Checks if all organisms have died
 *
 * @param arr Board with state to be checked
 * @param rows Number of rows on the board
 * @param columns Number of columns on the board
 *
 * @return 1 if all organisms are dead, 0 at least one is alive.
 */
int checkAllDead(int **arr, int rows, int columns) {

	/* Iterate through playable cells, checking if dead
	 * LOOP INVARIANT: The cell must be in the playable area
	 * PRE-CONDITION: Starts with the cell at upper left of board, [1][1] in the grid
	 * POST-CONDITION: Ends with cell at the bottom right of the board, [n-2][n-2] in the grid
	 */
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			// If cell is alive return 0 to exit function
			if (arr[row+1][column+1] == 1)
				return 0;
		}
	}

	return 1;
}

