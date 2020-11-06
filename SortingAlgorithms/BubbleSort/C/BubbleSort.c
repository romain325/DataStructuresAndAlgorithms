#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapVal(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int* arr, int n){
    for (int i = 0; i < n -1 ; i++){
        int hasBeenSwapped = 0; // WORK AS A BOOL

        for (int j = 0; j < n - 1 -i; j++){
            if(arr[j] > arr[j+1]){
                swapVal(&arr[j], &arr[j+1]);
                hasBeenSwapped = 1;
            }
        }
        // If we didn't change anything then we can break and go to the next
        if(hasBeenSwapped == 0){
            break;
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
    BubbleSort(arr,length);
    end = clock();

    printf("\nSorting time = %f sec\n", (double) (end - begin) / CLOCKS_PER_SEC);
    printf("Sorted:\n");
    for(int i = 0; i < length;i++)
        printf("%d\t", arr[i]);

    return 0;
}
