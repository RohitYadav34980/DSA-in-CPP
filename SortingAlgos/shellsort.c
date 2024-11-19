#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arrSize = 100000;
    int* arr = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t t;
    t = clock();
    shellSort(arr, arrSize);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("shellSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}