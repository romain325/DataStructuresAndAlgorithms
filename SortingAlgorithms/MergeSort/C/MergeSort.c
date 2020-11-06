#include <stdio.h>
#include <time.h>

void mergeSort(int arr[], int length){
    int tmp[50];
    int i, j, k;
    int lb1, lb2, ub1, ub2;
    int size;

    size = 1;
    while (size < length){
        lb1 = 0;
        k = 0;

        while (lb1 + size < length){
            lb2 = lb1 + size;
            ub1 = lb2 - 1;
            if (ub1 + size < length)
                ub2 = ub1 + size;
            else
                ub2 = length - 1;

            i = lb1;
            j = lb2;

            while (i <= ub1 && j <= ub2){
                if (arr[i] < arr[j])
                    tmp[k++] = arr[i++];
                else
                    tmp[k++] = arr[j++];
            }

            while (i <= ub1) 
                tmp[k++] = arr[i++];

            while (j <= ub2) 
                tmp[k++] = arr[j++];

            lb1 = ub2 + 1;
        }

        for (i = 0; i <= ub2; i++) 
            arr[i] = tmp[i];

        size = size * 2;
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
    mergeSort(arr, length);
    end = clock();

    printf("\nSorting time = %f sec", (double) (end - begin) / CLOCKS_PER_SEC);

    printf("\nSorted:\n");
    for(int i = 0; i < length;i++)
        printf("%d\t", arr[i]);

    return 0;
}
