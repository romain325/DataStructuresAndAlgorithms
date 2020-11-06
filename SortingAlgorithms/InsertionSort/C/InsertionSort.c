#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int* arr, int n){
    int j,pivot;

    for (int i = 0; i < n; i++){
        j = i -1;
        pivot = arr[i];

        while (j >= 0 && pivot < arr[j]){
            arr[j +1] = arr[j];
            j = j-1;
        }
        arr[j +1] = pivot;
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
    InsertionSort(arr,length);
    end = clock();

    printf("\nSorting time = %f sec\n", (double) (end - begin) / CLOCKS_PER_SEC);
    printf("Sorted:\n");
    for(int i = 0; i < length;i++)
        printf("%d\t", arr[i]);

    return 0;
}
