/*
 * life.h
 *
 *  Created on: Jan 27, 2018
 *      Author: isaiah
 */

#ifndef LIFE_H_
#define LIFE_H_

int playOne(int rows, int columns, int **superOld, int **old, int **new);

int verifyFileSize(FILE *input, int givenRows, int givenColumns, int *maxRow, int *maxColumn);
int parseFile(FILE *input, int **firstGrid, int rowOffset, int columnOffset);



#endif /* LIFE_H_ */
