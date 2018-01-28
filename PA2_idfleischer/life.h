/*
 * life.h
 *
 *  Created on: Jan 27, 2018
 *      Author: isaiah
 */

#ifndef LIFE_H_
#define LIFE_H_

int playOne(int rows, int columns, int **superOld, int **old, int **new);

int verifyFileSize(FILE *input, int givenRows, int givenColumns);
int parseFile(FILE *input);



#endif /* LIFE_H_ */
