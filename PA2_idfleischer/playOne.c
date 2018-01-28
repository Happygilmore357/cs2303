/*
 * PlayOne.c
 *
 *  Created on: Jan 25, 2018
 *      Author: isaiah
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

	for (int row = 1; row < rows + 1; row++) {
		for (int column = 1; column < columns + 1; column++) {

			score = 0;
			orgState = old[row][column];

			for (int neighborTop = -1; neighborTop < 2; neighborTop++) {
				score += old[row - 1][column + neighborTop];
			}

			for (int neighborBottom = -1; neighborBottom < 2;
					neighborBottom++) {
				score += old[row + 1][column + neighborBottom];
			}

			score += old[row][column - 1];
			score += old[row][column + 1];


			switch (score) {
			case 3:
				if (orgState == 0) {
					new[row][column] = 1;
					//printf("State: %d Coords: %d, %d Score: %d, New State: Alive\n", orgState, row, column, score);
					break;
				}
			case 2:
				if (orgState == 1) {
					new[row][column] = 1;
				//printf("State: %d Coords: %d, %d Score: %d, New State: Alive\n", orgState, row, column, score);
				break;
				}
			case 0:
			case 1:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			default:
				new[row][column] = 0;
				//sprintf("State: %d Coords: %d, %d Score: %d, New State: Dead\n", orgState, row, column, score);
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

	for (int row = 1; row < rows + 1; row++) {
		for (int column = 1; column < columns + 1; column++) {
			if (arr[row][column] == 1)
				return 0;
		}
	}

	return 1;
}

