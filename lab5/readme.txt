Requirement 1.
-------------
Works with all the test cases used in the example provided on the lab document and other test cases as well.

Requirement 2
-------------
Works with the test case used in the example provided on the lab document and other test cases as well.


Question
--------
In order to implement the stand-alone tag in the algorithm already written for requirement 1, a check can be added where the program checks if there is a '/' followed by a '>'. If these two are detected then the check returns true and characters that were just pushed are immediately popped and the cehcking process continues for the stack.

eg.
if <foo/> is entered, the first a check is done to see if '<' is entered and to see if it is followed by '/'. Since the check returns false for the '/' it pushes "foo". Now another check happens that checks if there is a '/' and if '>' follows it. Since it is true the string that was just pusehd onto the stack, "foo", is now popped.



Worked on the algorithms for part1main and part2main with Brian Mami and Max Lavecchia.