#include <stdio.h>

#define DAY1YEAR1 (6)
#define REFERENCE_YEAR (2000)

void printCalendar(int year, int yearStartDay);
int printMonth(int year, int month, int monthStartDay);
int printMonthName(int year, int month);


// Sunday = 0, Saturday = 6

int main(void) {

  // January 1st of 2000 was a Saturday

  //ask for year, figure out starting day of that year

  int year, yearStartDay;
  int daysBeforeYear = 0;

  printf("Please enter year for this calendar:- ");
  scanf("%d", &year);

  if (year >= REFERENCE_YEAR) {

    for (int indexYear = REFERENCE_YEAR; indexYear < year; indexYear++) {
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
  } else {
    for (int indexYear = REFERENCE_YEAR - 1; indexYear >= year; indexYear--) {
      //printf("%d\n", indexYear);
      if (indexYear % 4 != 0) {
        daysBeforeYear += 365;  // This is true for most years, making the loop run faster
      } else if (indexYear % 100 == 0) {
        if (indexYear % 400 == 0) {
          daysBeforeYear += 366;
          //printf("Leap year: %d \n", indexYear);
        } else {
          daysBeforeYear += 365;
        }
      } else {
        //printf("Leap year: %d \n", indexYear);
        daysBeforeYear += 366;
      }
    }
    yearStartDay = 7 + (DAY1YEAR1 - daysBeforeYear) % 7;
  }



  printf("%d\n", yearStartDay);

  printCalendar(year, yearStartDay);


  return 0;
}

void printCalendar(int year, int yearStartDay) {
  printf("***    CALENDAR for %4d   ***", year);
  int monthStartDay = yearStartDay;
  for(int i=0; i<12; i++) {
    int monthStartDay = printMonth(year, i, monthStartDay);
  }

}

int printMonth(int year, int month, int monthStartDay) {
  int nextMonthStartDay = (printMonthName(year, month) + monthStartDay) % 7;

  return nextMonthStartDay;
}


int printMonthName(int year, int month) {
  int lengthOfMonth;

  switch (month) {
    case 0:
      char monthName[] = "January";
      lengthOfMonth = 31;
      break;
    case 1:
      char monthName[] = "February";
      lengthOfMonth = 31;
      break;
    case 2:
      char monthName[] = "March";
      lengthOfMonth = 31;
      break;
    case 3:
      char monthName[] = "April";
      lengthOfMonth = 30;
      break;
    case 4:
      char monthName[] = "May";
      lengthOfMonth = 31;
      break;
    case 5:
      char monthName[] = "June";
      lengthOfMonth = 30;
      break;
    case 6:
      char monthName[] = "July";
      lengthOfMonth = 31;
      break;
    case 7:
      char monthName[] = "August";
      lengthOfMonth = 31;
      break;
    case 8:
      char monthName[] = "September";
      lengthOfMonth = 30;
      break;
    case 9:
      char monthName[] = "October";
      lengthOfMonth = 31;
      break;
    case 10:
      char monthName[] = "Novemebr";
      lengthOfMonth = 30;
      break;
    case 11:  default:
      char monthName[] = "December";
      lengthOfMonth = 31;
      break;
  }

  printf("%s %4d\n", monthName, year);
  return lengthOfMonth;
}
