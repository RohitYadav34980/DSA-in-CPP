#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    float max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    float range = (max - min) / n;
    int* bucket = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] - min) / range);
        if (index == n) index--;
        bucket[index]++;
    }

    for (int i = 1; i < n; i++) {
        bucket[i] += bucket[i - 1];
    }

    float* temp = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] - min) / range);
        if (index == n) index--;
        temp[bucket[index] - 1] = arr[i];
        bucket[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(bucket);
    free(temp);
}

int main() {
    int arrSize = 100000;
    int* arr = (int*)malloc(arrSize * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t t;
    t = clock();
    bucketSort(arr, arrSize );
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("bucketSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}