#include <stdio.h>
#include <time.h>

// return the max of an array
int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (max < arr[i]) 
            max = arr[i];
    return max;
}

// Count Sorting
void countSort(int* arr, int n, int exp) { 
    int output[n];
    int i, count[10] = { 0 }; 

    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    // Change count[i] so that count[i] now contains actual 
    // position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

// Radix Sorting
void RadixSort(int arr[], int n){
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 

    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

int main(){
    int arr[] = {6,6,7,420,32,69,45,2,789,5,46};
    int length = sizeof(arr)/sizeof(arr[0]);
    clock_t begin,end;

    begin = clock();
    RadixSort(arr, length);
    end = clock();    

    printf("Sorting time: %f sec\n", (double) (end - begin) / CLOCKS_PER_SEC);
    for (int i = 0; i < length; i++){
        printf("%d  ", arr[i]);
    }
    
    return 0;
}
