#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[],int n){
    int min_indx,temp;
    for (int i = 0; i < n; i++)
    {
        min_indx=i;
        for (int j = i; j < n; j++)
        {
            if (arr[j]<arr[min_indx])
            {
                min_indx=j;
            }
            
        }
        temp=arr[min_indx];
        arr[min_indx]=arr[i];
        arr[i]=temp;
        
    }
    
}
int main(){
    int arr[100000], i;
    for(i=0;i<100000;i++){
         arr[i]=rand()%100000;
    }
    clock_t t; 
    t = clock(); 
    selectionSort(arr,100000); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("selectionSort() took when n is 100000, t = %f seconds to execute \n", time_taken);
    
}