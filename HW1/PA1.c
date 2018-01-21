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
  printf("***    CALENDAR for %4d   ***\n\n", year);
  int monthStartDay = yearStartDay;
  for(int i=0; i<12; i++) {
    int nextMonthStartDay = printMonth(year, i, monthStartDay);
    monthStartDay = nextMonthStartDay;
  }

}

int printMonth(int year, int month, int monthStartDay) {
  int monthLength = printMonthName(year, month);
  int nextMonthStartDay = (monthLength + monthStartDay) % 7;

  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  for(int i=0; i<monthStartDay; i++) {
    printf("     ");
  }

  int dayOfTheWeek = monthStartDay;

  for(int day=1; day<(monthLength+1); day++) {
    if (dayOfTheWeek >= 6) {
      printf("%3d  \n", day);
      dayOfTheWeek = 0;
    } else {
      printf("%3d  ", day);
      dayOfTheWeek += 1;
    }
  }
  if (dayOfTheWeek == 0) {
    printf("\n");
  } else {
    printf("\n\n");
  }

  return nextMonthStartDay;
}


int printMonthName(int year, int month) {
  int lengthOfMonth;

  switch (month) {
    case 0:
      printf("January %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 1:
      printf("February %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 2:
      printf("March %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 3:
      printf("April %d\n\n", year);
      lengthOfMonth = 30;
      break;
    case 4:
      printf("May %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 5:
      printf("June %d\n\n", year);
      lengthOfMonth = 30;
      break;
    case 6:
      printf("July %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 7:
      printf("August %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 8:
      printf("September %d\n\n", year);
      lengthOfMonth = 30;
      break;
    case 9:
      printf("October %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 10:
      printf("November %d\n\n", year);
      lengthOfMonth = 30;
      break;
    case 11:  default:
      printf("December %d\n\n", year);
      lengthOfMonth = 31;
      break;
  }

  return lengthOfMonth;
}
