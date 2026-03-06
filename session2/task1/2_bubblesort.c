#include <stdio.h>

#include "2_bubblesort.h"

int main(void) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90, 91};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, n);

  printf("After sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

/**
 * @brief Sorts an array of integers in ascending order using the bubble sort algorithm.
 * 
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int array[], int n) {
  // code goes here
  for (int z=0;z<n;z++) {
    int swapped = 0;
    for (int i=1;i<n-z;i++) {
      if (array[i] < array[i-1]) {
        int temp = array[i];
        array[i] = array[i-1];
        array[i-1] = temp;
        swapped = 1;
      }
    }
    if (!swapped) {
      break;
    }
  }
}