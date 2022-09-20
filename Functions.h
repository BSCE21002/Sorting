#ifndef SORTING_FUNCTIONS_H
#define SORTING_FUNCTIONS_H

void display(int arr[], int n);
void swap(int *x, int *y);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int first, int last);
void quickSort(int arr[], int first, int last);
void countSort(int arr[], int n);

#endif //SORTING_FUNCTIONS_H