#include <stdio.h>

#define DAY1YEAR1 (6)

/*void printCalendar(int year, int yearStartDay);
int printMonth(int year, int month, monthStartDay);
int printMonthName(int year, int month);
*/

// Sunday = 0, Saturday = 6

int main(void) {

  // January 1st of 0001 was a Saturday

  //ask for year, figure out starting day of that year

  int year, yearStartDay;
  int daysBeforeYear = 0;

  printf("Please type in the year (YYYY): ");
  scanf("%d", &year);

  for (int indexYear = 1; indexYear < year; indexYear++) {
    if (indexYear % 4 != 0) {
      daysBeforeYear += 365;  // This is true for most years, making the loop run faster
    } else if (indexYear % 100 == 0) {
        if (indexYear % 400 == 0) {
          daysBeforeYear += 366;
          printf("Leap year: %d \n", indexYear);
        } else {
          daysBeforeYear += 365;
        }
    } else {
      printf("Leap year: %d \n", indexYear);
      daysBeforeYear += 366;
    }
  }

  yearStartDay = (daysBeforeYear + DAY1YEAR1) % 7;

  printf("%d\n", yearStartDay);

  //printCalendar(year, yearStartDay);


  return 0;
}


/*int printMonth(int year, int month, monthStartDay) {


    return nextMonthSartDay;
}


int printMonthName(int year, int month) {

  return numberOfDays;
}
*/
