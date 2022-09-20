#include "Functions.h"
#include <iostream>

using namespace std;

int main(void)
{
    //int arr[25] = {5, 17, 20, 19, 6, 10, 18, 13, 15, 2, 22, 8, 7, 9, 14, 24, 1, 11, 25, 4, 3, 12, 21, 16, 23};
    int arr[8] = {3, 7, 1, 1, 5, 0, 2, 3};
    int n = 8;

    countSort(arr, n);
    display(arr, n);

    return 0;
}