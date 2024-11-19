#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int arrSize = 100000;
    int* arr = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t t;
    t = clock();
    quicksort(arr, 0, arrSize - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("quickSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}