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

Press the green play button, this will build the code and run ./ctest
