Insertion Sort
--------------
Modified insertion sort algorithm from here https://www.geeksforgeeks.org/insertion-sort/ 
Works as intended with all the compare, swap and copy functions working as well.

For the insertion sort algorithm there are three cases for the algorithm to be tested with. The best (Ω), worst (0) and average (Θ) case. The best (Ω) case occurs when the given array is pre-sorted requiring the algorithm to use the least amount of swaps, zero, and take the least amount of time. The worst case (0) occurs when the given array is reverse pre-sorted requing the algotihm to take the most amount of time and use the most amount of swaps to sort it. Lastly the average (Θ) case occurs when the array has a mix of presorted and reverse sorted elements (ordered randomly), this requires the alogithm to take less time and swaps than the worst case but still more take more time and swaps then the best case. 

BestCase (Ω): (1,2,3,4,5,6) - Presorted
Comparisons = 5 	f(n) = n - 1
Swaps = 0 	 	f(n) = 0
Copy Operations = 6 	f(n) = n
Time complexity = 	O(n)

WorstCase (0): (6,5,4,3,2,1) - Reverse Order
Comparisons = 15 	f(n) = 1/2(n^2 - n)
Swaps = 15 		f(n) = 1/2(n^2 - n)
Copy Operations = 6	f(n) = 0
Time Complexity = 	O(n^2)

Average Case (Θ): (3,5,1,4,2,6) - Random
Comparisons = 10 	f(n) = 1/4(n^2 - n)
Swaps = 6		f(n) = 1/4(n^2 - n) 
Copy Operations = 6	f(n) = n
Time Complexity = 	O(n^2)

These equations are all approximations that may or may not be correct for all cases as they are only used to calculate the theoretical average.


Merge Sort
----------
Modified merge sort algorithm from here https://www.programiz.com/dsa/merge-sort
Works as intended with all the compare, swap and copy functions working as well.

Merge sort contains two methods, the merge method which merges the subarrys and the mySort method which recursively calls to sort entire list

For the merge sort algorithm there are three cases for the algorithm to be tested with. The best (Ω), worst (0) and average (Θ) case. The equations are all nlogn as the amount of comparisons and copies done to the array increaases exponentially because the large array is being split into n amount of subarrays. The swap equation is always 0 as merge sort doesnt swap the values but instead copies them and places them in the correct order when merging.


BestCase (Ω): (1,2,3,4,5,6) - Presorted
Comparisons = 7 	f(n) = nlgn
Swaps = 0  	 	f(n) = 0
Copy Operations = 32  	f(n) = nlgn
Time complexity = 	O(lgn)

WorstCase (0): (6,5,4,3,2,1) - Reverse Order
Comparisons = 9 	f(n) = nlgn
Swaps = 0  		f(n) = 0
Copy Operations = 32 	f(n) = nlgn
Time Complexity = 	O(nlgn)

Average Case (Θ): (3,5,1,4,2,6) - Random
Comparisons = 11 	f(n) = nlgn
Swaps = 0		f(n) = 0
Copy Operations = 32	f(n) = nlgn
Time Complexity = 	O(nlgn)

These equations are all approximations that may or may not be correct for all cases as they are only used to calculate the theoretical average.

Worked with Brian Mami when trying to find the equations
