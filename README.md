# Quicksort w/ ACSL Annotations

## History
Quicksort is a sorting algorithm developed in 1959 by Tony Hoare. Since its publication in 1961, the algorithm has been widely used due to its exceptional efficiency and speed. With proper implementation, Quicksort can be about two or three times faster than other popular sorting algorithms (including merge sort and heapsort).

## High-level Overview
As with all sorting algorithms, the goal of Quicksort is to take an input array and return a sorted  version of that array. The approach taken by Hoare was to:
1.	Select a pivot element (say the first element in the array)
2.	Partition the array into 3 separate parts based on that pivot
  - The first part includes all elements in the array less than the pivot
  - The second part is the pivot itself
  - The third part contains all elements greater than or equal to the pivot
3.	Recursively apply the quicksort algorithm to the first and third parts

In order to achieve a properly partitioned array we must have a separate algorithm for the partitioning step itself. Also, it’s worth noting that after the array has been partitioned, the selected pivot element is now in the correct position with respect to the sorted array.

## Partitioning
A simple way to understand how partitioning  works is to imagine all array elements are cards with one blank side and the element itself on the other side. These cards are laid out in front of you on a table in the order the array is currently in. Picking the pivot to be the left most card we can flip all other cards face down. Now we open each card from left to right comparing the current card to the pivot as we go. If the flipped card is less than the pivot, we swap that card with the leftmost open card (not including the pivot) and then flip that leftmost card that was just swapped so that it’s now face down. If the current card is not less than the pivot then we skip it and leave it face up. Once all the cards have been inspected and rearranged, swap the right most face down card with the pivot and flip all cards face up. This will result in the array being properly partitioned.

## Common Pitfalls 

### Partitioning in Place
Novice programmers may choose to implement partitioning by using a separate array to store all values less than or equal to the partition, then the partition itself, followed by all values greater than the partition. Although this may seem easy to implement, the extra cost of creating, modifying and copying the partitioned array back to the original array can drastically slow down performance.

### Staying in Bounds
Often developers may forget that the partitioning value might be the smallest or biggest value in the entire array. Certain checks must be put in place to ensure pointers do not run of the left or right ends of the array.

### Preserving Randomness
Quicksort has an issue where it is relatively slow if specific pivots are picked. For example, if the pivot is always chosen to be the first element in the array and the array is in reverse order. The most ideal pivot would be the median of all values in the array, but in order to find this we have to sort the array, which eliminates the need for the actual algorithm. A good way to avoid this problem is to randomly select the pivot each time. This can be done by randomizing the input array before selecting the pivot. Programmers must be cautious not to shuffle the already partitioned arrays.

## Variants

### Cut-off to Insertion Sort
Although overall Quicksort is significantly faster than Insertion sort, the latter happens to be faster for tiny arrays. With this knowledge we can increase the performance of Quicksort by switching over to Insertion sort once (sub) array length reaches a certain size. According to Sedgewick & Wayne the length can be anywhere between 5 and 15 to increase average performance.

### Median-of-Three Partitioning
Another way Quicksort can be modified to increase performance is to set the pivot to the median of a small sample of items during partitioning. This way a decent partitioning value is chosen at the cost of calculating the median of the sample. A sample size of 3 creates the best improvement.
