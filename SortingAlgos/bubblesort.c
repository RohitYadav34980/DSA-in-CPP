#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int n,int arr[]){
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
}
int main(){
    int arr[100000], i;
          for(i=0;i<100000;i++){
             arr[i]=rand()%100000;
          }
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    bubbleSort(100000,arr); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("bubbleSort() took when n is 100000, t = %f seconds to execute \n", time_taken);    
}