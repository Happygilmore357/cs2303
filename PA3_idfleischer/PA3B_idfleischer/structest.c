#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");

	printEmployee(e);

	return 0;
}
