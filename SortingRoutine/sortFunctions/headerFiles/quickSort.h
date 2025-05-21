#ifndef QuickSort_H
#define QuickSort_H

void quick_sort(int arr[], int low, int high);
void recursive_quick_sort(int arr[], int n);
void iterative_quick_sort(int arr[], int n);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

#endif