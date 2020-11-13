#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { false, true } bool;

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *arr, int n){
    if (n == 1)
        return;

    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]){
            swapInt(arr + i, arr + i + 1);
            swapped = true;
        }
    }
    if (swapped){
        bubbleSort(arr, n - 1);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {6,6,7,420,32,69,45,2,789,5,46};
    int length = sizeof(arr)/sizeof(arr[0]);
    clock_t begin,end;

    begin = clock();
    bubbleSort(arr, length);
    end = clock();    

    printf("Temps de tri: %f sec\n", (double) (end - begin) / CLOCKS_PER_SEC);
    for (int i = 0; i < length; i++){
        printf("%d  ", arr[i]);
    }
    
    return 0;
}
