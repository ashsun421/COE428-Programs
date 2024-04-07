Notes
-----
towers > junk1
This command line argument redirects everything but the stderr stream print statements.
So the stuff printed from printf("%d %d\n", from, dest) are redirected and only the
stuff printed from fprintf(stderr, "towers(%d, %d, %d)\n", n, from, dest) and
fprintf(stderr, "Move #%d: From Tower %d to Tower %d\n", ++moveNumber, from, dest) 
are kept to be displayed


towers 2> junk2 
This command line argument redirects everything but the stdout stream print statements.
So only the stuff printed from printf("%d %d\n", from, dest) are printed and the stuff
printed from fprintf(stderr, "towers(%d, %d, %d)\n", n, from, dest) and
fprintf(stderr, "Move #%d: From Tower %d to Tower %d\n", ++moveNumber, from, dest) are
redirected.


towers 2> details > pureStdout
This command line argument redirects both stderr and stdout and will write the outputs
for both on seperate files.

stdout stream
A pointer to a file stream that represents the deault output device for the application

stderr stream
A pointer to a file stream representing the deafult output device for error messages

Worked on some of the questions with Brian Mami and Zimraan Haider.

Requirement 1
-------------
1.How will the first recursive call to towers() be invoked? Answer this question in the
form: towers(x, y, z) where you give the actual values to the three parameters.

Lets say that the commandline argument towers 5 2 3 is given. 
The first recursive call to towers() will be invoked when the x parameter does not
equal 0, in this case it will invoke because the x parameter is currently equal to 5.
This recursion will continue being invoked in this manner until the x parameter equals 0, 
meaning that the number of discs needed to be moved is now 0. First recursion should look 
like towers(5-1, 2, 6-2-3) so towers (4,2,1).


2. How many recursive calls to towers() will be made before this first recursive call 
actually returns to the initial invocation?

From the example used above, there should be 31 recursive calls made after the initial call 
to the function, before it returns to the initial invocation. 2^5 - 1 = 32 - 1 = 31


3. Once towers(5, 2, 3) has invoked its first recursive call to towers() and this 
invocation has returned, what will be printed to stdout? (i.e. What actual move will 
be made by towers(5, 2, 3) ?)

The first move should be, 2 3. I think this is the first move becauase in the code
the stdout stream printf("%d %d\n", from, dest) line takes the values of from and dest 
from the towers command and prints them out as is for the first recursion.


4. How will the second recursive call to towers() be invoked? Answer this question in 
the form: towers(x, y, z) where you give the actual values to the three parameters.

After the first recursive call the value for x becomes 4, y becomes 2 and z becomes 1, 
when the second recursive call is invoked it should look like towers(4-1, 6-2-2, 3), 
so towers(3,2,3). This should continue on updating for x,y and z until the value for x becomes 0. 
Once all the possible values for stderr are printed in showRecursionDepth the program moves 
on to printing out the values for stderr of the moves that are being made, 
then prints out stdout of only the tower moves.


5. Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?

From https://www.mathscareers.org.uk/tower-of-hanoi/ I learned that there is a formula 
to solve for the minimum amount of moves necessary to solve the Tower of Hanoi problem.
The formula is (2^n) - 1. Using this formula i solved for 2^8 - 1 = 255 moves. This also
lined up with the output given by terminal when using the wc -1 someFile function and 
the regular towers function move counter.


Requirement 2
-------------
The program after my modification worked as intended. I first added #include <stdio.h>. Then I added an if statement that detects if
1 argument has been entered. When that one argument, other than the towers command, has been detected the single argument is set 
to equal n in the towers function while from and dest are predetermined. Next I added an else if statement that detects if 3 
arguments have been entered.When those 3 arguments, other than the towers comman, have been detected the first index is set to n, 
second index is set to fromand third index is set to dest. From both of these if statements so far, whenever a value is being set
from the commandline prompt it is using the atoi function to convert the string into integers. Finally there is another else if 
statement if only one argument is detects, the towers argument. In this scenario a predetermined set of values for n, dest and 
from are used in the problem. I also made two error statements that are printed out to stderr if caught. The first if statement 
prints an error if the user tells the program to move the discs to a tower that is not in the set of 3 towers. The second if statement
prints an error if the user tells the program to move a disc from one location to the same location. These two errors are given as 
they physically cannot occur in the tower of hanoi problem.

























