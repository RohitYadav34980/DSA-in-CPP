#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int tempSize = high - low + 1;
    int* temp = (int*)malloc(tempSize * sizeof(int));
    int k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    free(temp);
}

void merge(int arr[], int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        sort(arr, low, mid, high);
    }
}

int main() {
    int arrSize = 100000;
    int* arr = (int*)malloc(arrSize * sizeof(int));
    // srand(time(NULL)); 

    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t t;
    t = clock();
    merge(arr, 0, arrSize - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("mergeSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}