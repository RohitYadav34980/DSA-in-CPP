#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertionSort(int arr[],int n){
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j >=0; j--)
        {
            if (arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}
int main(){
    int arr[100000], i;
    for(i=0;i<100000;i++){
         arr[i]=rand()%100000;
    }
    clock_t t; 
    t = clock(); 
    insertionSort(arr,100000); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("insertionSort() took when n is 100000, t = %f seconds to execute \n", time_taken);
}