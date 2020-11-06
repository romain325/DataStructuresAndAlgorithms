#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapVal(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSort(int* arr, int n){
    for (int i = 0; i < n -1 ; i++){
        int minIndex = i;
        for (int j = i +1; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swapVal(&arr[i], &arr[minIndex]);
        }
    }
}

int main(int argc, char const *argv[]){
    int arr[] = {6,6,7,420,69,5,3,88};
    int length = sizeof(arr)/sizeof(arr[0]);
    clock_t begin,end;

    printf("Not sorted:\n");
    for(int i = 0; i < length;i++)
        printf("%d\t", arr[i]);

    begin = clock();
    SelectionSort(arr,length);
    end = clock();

    printf("\nSorting time = %f sec\n", (double) (end - begin) / CLOCKS_PER_SEC);
    printf("Sorted:\n");
    for(int i = 0; i < length;i++)
        printf("%d\t", arr[i]);

    return 0;
}
