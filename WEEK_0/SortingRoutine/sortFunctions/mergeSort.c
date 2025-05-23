#include <stdio.h>
#include <stdlib.h>
#include "headerFiles/mergeSort.h"

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int lArr[n1], rArr[n2];
    for (int i = 0; i < n1; i++)
        lArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        } else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void recursive_merge_sort(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
}
void iterative_merge_sort(int arr[], int n) {
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
          
            int mid = left_start + curr_size - 1;
            int right_end = ((left_start + 2 * curr_size - 1) < (n - 1)) ? (left_start + 2 * curr_size - 1) : (n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}