#include "Functions.h"
#include <iostream>

using namespace std;

void display(int arr[], int n) //display function
{
    cout << "\n\n";
    for(int i = 0; i < n; i++) //display elements
    {
        cout << arr[i] << " ";
    }
}

void swap(int *x, int *y) //swap function
{
    int *temp = x; //x and y swap
    x = y;
    y = temp;
}

////////////////////////////////////////////////////////////////////////////////////
void selectionSort(int arr[], int n) //selection sort function
{
    if(n == 0) //check if array is already empty
        cout << "\nArray is empty so no elements can be sorted";
    else
    {
        for(int i = 0; i < n - 1; i++) //check and compare each element
        {
            int ref = i; //set reference element
            for(int j = i + 1; j < n; j++) //compare with next element
            {
                if (arr[j] < arr[ref]) //find smallest element
                    ref = j;
            }

            if(ref != i) //if reference element is not the smallest
            {
                int temp = arr[ref]; //swap smallest element with the reference
                arr[ref] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////

void bubbleSort(int arr[], int n) //bubble sort function
{
    if(n == 0) //check if array is already empty
        cout << "\nArray is empty so no elements can be sorted";
    else
    {
        for(int i = 0; i < n - 1; i++) //loop minus last element
        {
            for (int j = 0; j < n - i - 1; j++) //loop from second to first, minus last element
            {
                if(arr[j] > arr[j + 1])
                {
                    int temp = arr[j]; //swap elements
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////

void insertionSort(int arr[], int n) //insertion sort function
{
    if(n == 0) //check if array is already empty
        cout << "\nArray is empty so no elements can be sorted";
    else
    {
        int ref, unsorted;
        for(int i = 1; i < n; i++)
        {
            unsorted = arr[i]; //second element is the first unsorted element
            ref = i - 1; //reference element is the first

            while(ref >= 0 and unsorted < arr[ref]) //until condition becomes false
            {
                arr[ref + 1] = arr[ref]; //elements swapped and shifted to right until position of unsorted element
                ref--;
            }

            arr[ref + 1] = unsorted; //unsorted element inserted in correct position
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////

void merge(int arr[], int first, int mid, int last) //function to merge 2 arrays
{
    int i1, i2, k;
    int n1 = mid - first + 1; //no of elements in left array
    int n2 = last - mid; //no of elements in right array

    int *leftArr = new int[n1]; //allocate memory of respective arrays
    int *rightArr = new int[n2];

    for(int i = 0; i < n1; i++) //copying elements into left array
    {
        leftArr[i] = arr[first + i];
    }
    for(int i = 0; i < n2; i++) //copying elements into right array
    {
        rightArr[i] = arr[mid + i + 1];
    }

    i1 = 0; //first index of left array
    i2 = 0; //first index of right array
    k = i1; //index of output sorted array

    while(i1 < n1 and i2 < n2)
    {
        if(leftArr[i1] < rightArr[i2]) //if element of left is smaller
        {
            arr[k] = leftArr[i1]; //insert left element into new array
            i1++; //increment left index
        }
        else //if element of left is bigger
        {
            arr[k] = rightArr[i2]; //insert right element into new array
            i2++; //increment right index
        }
        k++; //increment sorted array index
    }

    while(i1 < n1) //elements remaining in left array are placed
    {
        arr[k] = leftArr[i1];
        i1++;
        k++;
    }

    while(i2 < n2) //elements remaining in right array are placed
    {
        arr[k] = rightArr[i2];
        i2++;
        k++;
    }
}

void mergeSort(int arr[], int first, int last) //merge sort function
{
    if(first < last)
    {
        int mid = first + (last - first) / 2; //calculate midpoint

        mergeSort(arr, first, mid); //merge sort first half of array recursively
        mergeSort(arr, mid + 1, last); //merge sort second half of array recursively

        merge(arr, first, mid, last); //merge the 2 sorted arrays together into a final sorted array
    }
    else
        return;
}

////////////////////////////////////////////////////////////////////////////////////

int partition(int arr[], int first, int last) //function to get partition point
{
    int pivot = arr[last]; //declare pivot as last element

    int i = first - 1; //helpful index
    int ref;

    for(int j = first; j < last; j++)
    {
        if(arr[j] <= pivot) //elements smaller than pivot are placed at left
        {
            i++;

            int temp = arr[i]; //swap new element smaller than pivot with element at j
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1]; //swap pivot with i++
    arr[i + 1] = arr[last];
    arr[last] = temp;

    ref = i + 1; //get index at partition

    return ref; //return index at partition
}

void quickSort(int arr[], int first, int last) //quicksort function
{
    if(first < last) //recursive call until condition becomes false
    {
        int ref = partition(arr, first, last); //get index of partition point in array

        quickSort(arr, first, ref - 1); //quicksort elements left of pivot
        quickSort(arr, ref + 1, last); //quicksort elements right of pivot
    }
    else //end recursive call
        return;
}

////////////////////////////////////////////////////////////////////////////////////

void countSort(int arr[], int n) //count sort function
{
    int max = arr[0]; //set max to arr[0]
    for(int i = 1; i < n; i++)
    {
        if (arr[i] > max) //find the largest element in array
            max = arr[i]; //update max
    }

    int *countArr = new int[max + 1]; //allocate memory for countArr with max no of elements
    for(int i = 0; i <= max; i++)
    {
        countArr[i] = 0; //initialize members of countArr to zero
    }

    for(int i = 0; i < n; i++)
    {
        countArr[arr[i]]++; //count all the occurrences of each element at index
    }

    for(int i = 1; i <= max; i++)
    {
        countArr[i] = countArr[i] + countArr[i - 1]; //modifies array into cumulative count at each index
    }

    int *sortedArr = new int[n];
    for(int i = n - 1; i >= 0; i--)
    {
        sortedArr[countArr[arr[i]] - 1] = arr[i]; //sort the array by each index of element in count array
        countArr[arr[i]]--;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = sortedArr[i]; //copy sorted array back to original array
    }

    delete[] countArr; //deallocate memory for both temporary arrays
    delete[] sortedArr;
}