Isaiah Fleischer idfleischer@wpi.edu

In this program I have written my own version of the following string functions:

strlen()  ->  mystrlen1()  [Uses subsripts]
strlen()  ->  mystrlen2()  [Uses poiner incrementation]
strcpy()  ->  mystrcpy()
strcat()  ->  mystrcat()
strncat() ->  mystrncat()
strndup() ->  mystrndup()

The functions are contained in "mystring.c"

All of my versions have the exact same behavior as the original functions, which I demonstrate in "ctest.c"


To run from the command line:

-Navigate to the project folder
-run "make" this will compile and link all of the files into an executable
-run ./ctest


To run from Eclipse:

-Press the hammer or right click on the project and select "Build project" to build the project
-Press the green play button to run make and then the program
