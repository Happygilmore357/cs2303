README for PA1.c

This is the first assignment for CS2303-C18. It is a program in C that prints a calendar for a year provided by the user provides through the command line. 


Run the program with by typing the following command in the shell:

gcc -Wall -o PA1 PA1.c
./PA1


The requirements for a given year being a leap year are the following:
-It must be evenly divisble by 4
-It must not be divisble by 100 unless it is also divisble by 400

When I determine if a year is a leap year in my program is first use an if statement to check if it meets the first condition. Then I use the following statement to determine if it meets the second condition:

((indexYear % 100) != 0) || ((indexYear % 400) == 0)

There are 4 possible cases for this statement, and it will only be false when the year is divisble by 100 but not 400. This means it will be true whenever the second condition above is true. This allows me to use 2 if statments rather than 3 to determine leap years. In hindsight I could have written it as !(((indexYear % 100) == 0) && ((indexYear % 400) != 0)) This may have been a bit easier to understand at first glance.


At first I was counting up from year 1, but I switched to year 2000 because online calendars don't go back as far as year 1, so bug fixing was difficult. With year 2000 I could easily check 20001, 2002, etc. very easily, allowing me to make sure I was correctly identifying leap years. Further, I could easily check the months themselves, making sure they each started on the correct day of the week.


----LOOP INVARIANTS----

Lines 40-42:
for (int indexYear = REFERENCE_YEAR; indexYear < year; indexYear++) {...

LOOP INVARIANT: the index year must be less than the specified year at this point. This ensures it only counts years in between the refrence and target year


Lines 58-60:
for (int indexYear = REFERENCE_YEAR - 1; indexYear >= year; indexYear--) {

LOOP INVARIANT: The inex year must always be >= to the target year. This ensures it only counts years in between the refrence and target year


Lines 98-99:
 for(int monthNumber = 0; monthNumber < 12; monthNumber++) {
 
LOOP INVARIANT: the month number must never exceed 12 as the highest month number is 11 (December)


Lines 121-123:

for(int i = 0; i < monthStartDay; i++) {

LOOP INVARIANT: i must be less than the month start day. This ensures it prints the correct number of blank spaces before the first day of the month


Lines 131-132:

for(int day = 1; day <= monthLength; day++) {

LOOP INVARIANT: The day must always be <= the month length so it only prints days within the month
