

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int pivot, int* comparisons) {
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int* comparisons) {
    if (low < high) {
        int pivot = arr[high];
        int pi = partition(arr, low, high, pivot, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    srand(time(NULL));
    int arr[MAX_SIZE];
    int comparisons[3] = { 0, 0, 0 }; // To store the number of comparisons for each input size

    // Input size of 10,000
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }
    quickSort(arr, 0, 9999, &comparisons[0]);
    printf("Number of comparisons for input size 10,000: %d\n", comparisons[0]);

    // Input size of 100,000
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100000;
    }
    quickSort(arr, 0, 99999, &comparisons[1]);
    printf("Number of comparisons for input size 100,000: %d\n", comparisons[1]);

    // Input size of 1,000,000
    for (int i = 0; i < 1000000; i++) {
        arr[i] = rand() % 1000000;
    }
    quickSort(arr, 0, 999999, &comparisons[2]);
    printf("Number of comparisons for input size 1,000,000: %d\n", comparisons[2]);

    return 0;
}

