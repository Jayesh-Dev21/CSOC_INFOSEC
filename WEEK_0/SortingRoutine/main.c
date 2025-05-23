#include <stdio.h>
#include <stdlib.h>

#include "sortFunctions/headerFiles/bubbleSort.h"
#include "sortFunctions/headerFiles/insertionSort.h"  
#include "sortFunctions/headerFiles/mergeSort.h"
#include "sortFunctions/headerFiles/quickSort.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int chooseSortingAlgorithm(){
    int n;
    printf("choose sorting algorithm:\n");
    printf("1. Bubble Sort\n"); 
    printf("2. Insertion Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &n);
    return n;
}

int choosedSortingAlgorithm(int choice, int array[], int n) {
    switch (choice) {
        case 1:
            bubble_sort(array, n);
            break;
        case 2:
            insertion_sort(array, n);
            break;
        case 3:
            merge_sort(array, 0, n - 1);
            break;
        case 4:
            quick_sort(array, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return -1;
    }
    return 0;
}

int main(){
    int array[] = {72, 11, 13, 5, 6, 89, 3, 45, 23, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    printArray(array, n);

    int choice = chooseSortingAlgorithm();
    
    int result = choosedSortingAlgorithm(choice, array, n);
    if (result == -1) {
        printf("Error in sorting\n");
        return -1;
    }

    printf("Sorted array: \n");
    printArray(array, n);
    printf("Sorting algorithm %d completed successfully.\n", choice);

    return 0;
}