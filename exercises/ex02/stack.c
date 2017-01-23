/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
1.  Read `stack.c`, which should be in this directory.  What is it
intended to do?  What would the output be if the program worked as
expected?

It seems to be intending to generate an integer array and assign the values twice, but instead it does nothing.
It does nothing because it attempts to access an array that is generated in one of the functions, which is created
in the stack memory, so as soon as the function ended, the pointer would likely no longer point to the array. Therefore
iterating through the array is pointless. 
If the program worked as expected, the output would be: [0,1,2,3,4]


2.  Compile it.  Do you get a warning?  What does it mean?

The warning was that foo() returned the address of the local variable array, which would be deleted shortly after the
function ended. It means there could be problems with interactions with the array.

3.  Run it.  What happens?  Can you explain it?  You might find it
helpful to draw a stack diagram.

I got some crazy numbers back, which makes sense because of what is discussed above with memory.

4.  Comment out the `print` statements in `foo()` and `bar()` and run
it again.  What happens now?

The program now works as intended, though I'm not sure why. I theorize it has to do with how the array is stored after 
being printed, but I'm not sure.
*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
