Isaiah Fleischer idfleischer@wpi.edu

This program contains a bunch of functions that maniupulate a prefedined struct called "Employee"

They most interesting functions are listed below:

makeRandEmployee() ->  Makes an Employee struct from randomly generated data.

makeMultEmployees() ->  Makes multiple Employee structs from randomly generated data. It places pointers to those structs in an easy to use array.

dupEmployees() -> Duplicates an array of pointers to Employee structs to a new array of pointers. This is a "shallow copy" because it duplicates the pointers but not the structs the pointers point to.

dupEmployeessDeep() -> Duplicates every Employee struct in an array of pointers to Employee structs, creating a new array of pointers to Employee structs with the same fields as the originals. This is a "deep copy" because it copies the structs the pointers in the array are pointing at. In the program you can see that structs pointed to in the original array, shallow copied array, and deep copied array appear to be identical. But upon inspection you will notice the original and shallow copy point to the same addresses while the deep copy points to different addresses. This is because the deep copy made entirely new structs that had the same fields, while the shallow copy points back to the original structs.

freeStructs() -> This frees the memory used by all of the structs pointed to in an array. 



To run from the command line:

-Navigate to the project folder
-run "make" this will compile and link all of the files into an executable
-run ./structest


To run from Eclipse:

-Press the hammer or right click on the project and select "Build project" to build the project
-Press the green play button to run make and then run the program
