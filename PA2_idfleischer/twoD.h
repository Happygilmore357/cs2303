/**
 * twoD.h
 *
 * @author: Mike Ciaraldi
 */

#ifndef TWOD_H_
#define TWOD_H_

// Function prototypes:
int** make2Dint(int rows, int columns);
char** make2Dchar(int rows, int columns);

int compare2Dint(int **arr1, int **arr2, int rows, int columns);
int compare2Dchar(char **arr1, char **arr2, int rows, int columns);

#endif /* 2D_H_ */
