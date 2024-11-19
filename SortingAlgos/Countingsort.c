#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int j = 0;
    for (int i = 0; i <= max; i++)
        while (count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
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
    countingSort(arr, arrSize );
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("countingSort() took %f seconds to execute\n", time_taken);

    free(arr);
    return 0;
}