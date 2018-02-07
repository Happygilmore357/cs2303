#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	srand(time(0));

	struct Employee *e, *i, *j;
	struct Employee** k;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	i = makeEmployee(1999, 2016, "Isaiah Fleischer");
	j = makeRandEmployee();

	printEmployee(e);
	printEmployee(i);
	printEmployee(j);

	k = makeMultEmployees(10);
	printMultEmployees(k, 10);

	//printf("%c\n", randChar());

	//printf("%s\n", randString(10));
	return 0;
}
