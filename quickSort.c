/*
C implementation of QuickSort with added ACSL annotations

Base algorithm taken from: https://www.geeksforgeeks.org/quick-sort/

Modifications by: Paul Warnick (https://github.com/PaulWarnick21/Quicksort-with-ACSL-Annotations)
*/
#include<stdio.h>
 
// A utility function to swap two elements
/*
    Valid: Checks if *a and *b can hold ints in memory
    Assigns: Makes sure only pointers a and b are modified
    Ensures: A post condition to check to see if the pointers have been swapped
    Old: Refers to the state before the function has been run
*/
/*@
    requires \valid(a) && \valid(b);
    assigns *a, *b;
    ensures *a == \old(*b) && *b == \old(*a);
*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/*
    This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot
*/
/*
    Precondition:
        - low cannot be less than 0
        - At this stage in the execution low must be less than high
        - high cannot be greater than the length of the input array
    Assigns: Prevents any unwanted value modifications
    Loop Invariants:
        - i can never be less then low - 1 (initally it starts off equal to low - 1)
        - i is never greater then j (j is starts off greater and is incremented more frequently)
        - j can be at most high (the loop should not execute if j > high)
    Postcondition:
        - Ensures the final position of the current pivot is between low and high
        - All values to the left of the pivot index must be less than or equal to the pivot
        - All values to the right of the pivot index must be greater than the pivot
        - The pivot has been swapped to the correct location
*/
/*@
    requires 0 <= low && low < high && high <= \length(arr);
    assigns arr, pivot, i, j;
    ensures low <= \result && \result < high;
    ensures \forall integer i; 0 <= i <= \result ==> arr[i] <= arr[\result];
    ensures \forall integer i; \result < i < \length(arr) ==> arr[\result] < arr[i];
    ensures arr[\result] == arr[pivot];
*/
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
 
    for (int j = low; j <= high - 1; j++)
    {
        //@ loop invariant low - 1 <= i && i <= j && j <= high;
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/*
    The main function that implements QuickSort
    arr[] --> Array to be sorted
    low   --> Starting index
    high  --> Ending index 
*/
/*
    Precondition:
        - low cannot be less than 0
        - high cannot be greater than the length of the input array
    Assigns: Only the array, low, high and partitioning index values can be modified
    Postcondition: The array is sorted in ascending order
*/
/*@
    requires 0 <= low && high <= \length(arr);
    assigns arr, low, high, pi;
    ensures \forall integer i, j; 0 <= i < j < \length(arr) ==> arr[i] <= arr[j];
*/
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
// Function to print an array
/*
    Forall: Checks to ensure each subsequent value is greater than or equal to the previous
    Assigns: Makes sure the array is not actually modified by the below function
*/
/*@
    requires \forall integer i, j; 0 <= i < j < size ==> arr[i] <= arr[j];
    assigns \nothing;
*/
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
