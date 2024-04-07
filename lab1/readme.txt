Suppose you were given an object module (with no access to source code) that sorted an
array of integers very efficiently. However, the sort function in the object module must
be invoked with the following signature: 

betterSort(int data[], first, last);

where the array to sort is data and the parameters first and last give the indices of the
portion of the array that is to be sorted.

How could you write a mySort() function with the signature used in this lab that could
exploit the better sorting function in the supplied object module?

Summary
-------
The program works as it is intended to, but there is a minor bug that I could not figure out 
how to fix. Whenever a negative number was entered in the command line the program would
convert the negative number to 0 and use that in the mySort function. This then caused
the sorted array to be wrong. This issue only occurs when a negative number is entered
in the command line, if a negative number is hard coded into the array it works fine.

Question 1
----------
The better sort function can be implemented by storing the first and last variables in temporary
variables, first and last. A new temporary variable, called length, can be made that would take 
first and last, subtract them, then add 1 to them. This should shorten the list to the desired 
amount. Then change the for loop to: for(i = first; i < length; i++). This should start from 
the first given indice and run until the last given indice. The mysort fucntion will then call 
the better sort function in itseslf


Thought Process
---------------
first = 2
last = 5
so sort array from indices 2-5
length = (5-2)+1 = 4

(1,2,3,4,5,6,7)
 0,1,2,3,4,5,6

after shortening should be (3,4,5,6)


Insertion Sort Process
----------------------
Program runs through the entered list for he length of it. Then the second element in the list is taken and compared to the element on its left. if the original element is less than the element on the left insert the original element in the place of the left element. Then continue onwards throughout the list. 

















