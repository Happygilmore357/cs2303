#include <stdio.h>

// Sunday = 0, Monday = 1, ... Saturday = 6
// January = 0, February = 1, ... December = 11

#define DAY1YEAR1 (6)  // January 1st of 2000 was a Saturday
#define REFERENCE_YEAR (2000) // Reference days of the week from this year. Count down or up from here.

void printCalendar(int year, int yearStartDay, int leapYear);
int printMonth(int year, int month, int monthStartDay, int leapYear);
int printMonthName(int year, int month, int leapYear);

/**
* Takes a year from the use and prints that year's calendar
* @return returns 0 if no errors, 1 if errors
*/
int main(void) {


  int year;  // The calendar will be for this year
  int yearStartDay;  // The first day of the year
  int daysBeforeYear = 0; // Days before the start of the year whose calendar will be printed
  int leapYear = 0; // 1 if leap year, 0 if not leap year

  printf("Please enter year for this calendar:- ");
  scanf("%d", &year);

  if(year <= 0) {  // Exit the program if the user enters an invalid year
    printf("Error: Please enter a year greater than 0, you entered %d.\n", year);
    return 1;

  } else if (year == REFERENCE_YEAR) {  // If the user enters the year 2000
    leapYear = 1;  // 2000 was a leap year
    yearStartDay = DAY1YEAR1;  // The first day of year is the first day of 2000, a Saturday

  } else if (year > REFERENCE_YEAR) {  // If the user enters a year > 2000

    // Counts up from year 2000 to the specified year, adding up the days in between
    // Sets the indexing year to 2000, stops once indexing year reaces specifies year, inceases by 1 each time
    for (int indexYear = REFERENCE_YEAR; indexYear < year; indexYear++) {
      // LOOP INVARIANT: the index year must be less than the specified year at this point.
      // This ensures it only counts years in between the refrence and target year

      // Determines if the index year is a leap year so it knows to add 365 or 366 days to daysBeforeYear
      // See readme for more detail
      if(indexYear % 4 == 0) {  // Year is divisble by 4
        if( ((indexYear % 100) != 0) || ((indexYear % 400) == 0) ) {  // This codition is only false if divisible by 100 but not 400
          daysBeforeYear += 366;  // Add 366 because index year is a leap year
        } else {daysBeforeYear += 365;}  // Add 365 because index year is not a leap year
      } else {daysBeforeYear += 365;}  // Add 365 because index year is not a leap year
    }

    yearStartDay = (daysBeforeYear + DAY1YEAR1) % 7;  // Calculate the day of the week the year starts on

  } else if (year < REFERENCE_YEAR) {  // If the user enters a year < 2000 count down to the year

    // Counts down from refence year to target year, adding the number of days in each year to daysBeforeYear each time
    for (int indexYear = REFERENCE_YEAR - 1; indexYear >= year; indexYear--) {
      // LOOP INVARIANT: The inex year must always be >= to the target year
      // This ensures it only counts years in between the refrence and target year

      // Determines if the index year is a leap year so it knows to add 365 or 366 days to daysBeforeYear
      // See readme for more detail
      if(indexYear % 4 == 0) {  // Year is divisble by 4
        if( ((indexYear % 100) != 0) || ((indexYear % 400) == 0) ) {  // This codition is only false if divisible by 100 but not 400
          daysBeforeYear += 366;  // Add 366 because index year is a leap year
        } else {daysBeforeYear += 365;}  // Add 365 because index year is not a leap year
      } else {daysBeforeYear += 365;}  // Add 365 because index year is not a leap year
    }

    yearStartDay = 7 + (DAY1YEAR1 - daysBeforeYear) % 7;  // Calculate the day of the week the year starts on
  }

  // Set the leapyear variable to 1 if year meets leapyear conditions
  if(year % 4 == 0) {  // Year must be divisible by 4
    if( ((year % 100) !=0 ) || ((year % 400) == 0) ) { // This condition is false if the year is divisible by 100 but not 400, the exception to general rule
      leapYear = 1;  // Loop will only reach here if it's a leap year. Else set leap year false
    } else {leapYear = 0;}
  } else {leapYear = 0;}

  printCalendar(year, yearStartDay, leapYear);  // Make the calendar

  return 0;  // Return 0 if no errors
}

/**
* Prints the calendar for the given year
* @param year year whose calendar to print
* @param yearStartDay the first day of the year
* @param leapYear flag to mark year as a leap year, 1 if leap year, 0 if not
*/
void printCalendar(int year, int yearStartDay, int leapYear) {
  printf("***    CALENDAR for %4d   ***\n\n", year);
  int monthStartDay = yearStartDay;  // Initialzies first month start day to first of the year

  // Prints calendars for individual months
  // Starts with January (0), incrments by 1 until it's printed all 12 months
  for(int monthNumber = 0; monthNumber < 12; monthNumber++) {
    // LOOP INVARIANT: the month number can never exceed 12 as the highest month number is 11 (December)
    // Gets start dy of the next month from printMonth function
    int nextMonthStartDay = printMonth(year, monthNumber, monthStartDay, leapYear);
    monthStartDay = nextMonthStartDay;  // Sets up start day for the next month in the next loop iteration
  }
}

/**
* Prints one month of the year to the console
* @param year year to print
* @param monthNumber month to print (see numbering convention at top)
* @param monthStartDay day of the week the curret month starts on
* @param leapYear flag to mark year as a leap year, 1 if leap year, 0 if not
* @return nextMonthStartDay day of the week the next month starts on
*/
int printMonth(int year, int monthNumber, int monthStartDay, int leapYear) {
  int monthLength = printMonthName(year, monthNumber, leapYear); // Get month length from printMonth function

  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  // Prints blank spaces in the week to compensate for not starting on a Sunday
  // Initialzies i to 0, increments by 1 until it reaches the start day of the current month
  for(int i = 0; i < monthStartDay; i++) {
    // LOOP INVARIANT: i must be less than the month start day.
    //This ensures it prints the correct number of blank spaces before the first day of the month
    printf("     ");
  }

  int dayOfTheWeek = monthStartDay; // Initialzies dayOfTheWeek to the first day of the month

  // Iterates through month, printing days formatted as weeks
  // Starts off with day 1, increments by 1 until it has printed the whole month
  for(int day = 1; day <= monthLength; day++) {
    // LOOP INVARIANT: The day must always be <= the month length so it only prints days within the month

    // Checks if it needs to start a new week
    if (dayOfTheWeek >= 6) {  // The current day is Saturday
      printf("%3d  \n", day);  //Print a newline after the day so the next week is on a new line
      dayOfTheWeek = 0;  // Reset the day to Sunday
    } else {  // The current day isn't saturday
      printf("%3d  ", day);  // Print the day number as usual
      dayOfTheWeek += 1;  // Increment the day by 1
    }
  }

  int nextMonthStartDay = dayOfTheWeek;//(monthLength + monthStartDay) % 7; // Calculate the start day of the next month

  // Checks if the next month starts on a Sunday
  // If it does that meas the previous month ended on a Sarturday, and printed a newline
  // In order to keep formatting consistent it should only print 1 newline if this is the case
  if (nextMonthStartDay == 0) {  // Prvious month ended on Saturday
    printf("\n");
  } else {  // Previous moth didn't end on a Saturday, print 2 newlines
    printf("\n\n");
  }

  return nextMonthStartDay;
}

/**
* Prints the month name with the year number at the top of the calendar. Also figures out the length of the month.
* @param year year to print
* @param month month to print (see numbering convention at top)
* @param leapYear flag to mark year as a leap year, 1 if leap year, 0 if not
* @return lengthOfMonth length of current month
*/
int printMonthName(int year, int monthNumber, int leapYear) {
  int lengthOfMonth; // Variable to hold the month length to be returned

  // Switch cases determine what  month to print and month length using the month number
  // Defaults to december if monthNumber isn't found as a case
  switch (monthNumber) {
    case 0:
      printf("January %d\n\n", year);
      lengthOfMonth = 31;
      break;
    case 1:
      printf("February %d\n\n", year);
      if (leapYear == 1){
        lengthOfMonth = 29;
      } else {
        lengthOfMonth = 28;
      }
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
