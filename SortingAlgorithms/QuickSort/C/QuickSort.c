#include <stdio.h>
#include <time.h>

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// use the last element as pivot
int partition(int arr[], int lowest, int highest){
    int pivot = arr[highest];
    int index = lowest -1;

    for(int i = lowest; i <= highest; i++){
        if(arr[i] < pivot){
            index ++;
            swapInt(&arr[index], &arr[i]);
        }
    }
    swapInt(&arr[index + 1], &arr[highest]);
    return index + 1;
}


void quickSortRecursive(int arr[], int lowest, int highest){
    if(lowest < highest){
        int partIndex = partition(arr, lowest, highest);
        quickSortRecursive(arr, lowest, partIndex - 1);
        quickSortRecursive(arr, partIndex +1, highest);
    }
}

void quickSort(int arr[], int length){
    quickSortRecursive(arr,0, length-1);
}

int main(int argc, char const *argv[]){
    int arr[] = {6,7,6,420,3,69,5};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    clock_t begin,end;

    begin = clock();
    quickSort(arr, arrLength);
    end = clock();

    printf("Elasped Time: %f sec", (double)(end - begin) / CLOCKS_PER_SEC);
    printf("Result:\n");

    for(int i = 0; i < arrLength; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}
