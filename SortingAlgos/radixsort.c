#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 
   
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {

    int m = getMax(arr, n); 

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
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
    radixSort(arr, arrSize);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("radixSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}
