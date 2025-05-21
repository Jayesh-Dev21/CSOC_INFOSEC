#include <stdio.h>
#include <stdlib.h>

#include "headerFiles/insertionSort.h"

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void recursive_insertion_sort(int arr[], int n) {
    if (n <= 1)
        return;
    recursive_insertion_sort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = last;
}