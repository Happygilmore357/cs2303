/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
struct Employee *makeRandEmployee(void);
struct Employee **makeMultEmployees(int count);

struct Employee **dupEmployees(struct Employee** src, int count);
struct Employee **dupEmployeesDeep(struct Employee** src, int count);

int freeStructs(struct Employee** e, int count);

int printEmployee(struct Employee *e);
int printMultEmployees(struct Employee** e, int count);

int randInt(int max);
char randChar(void);
char* randString(int length);


