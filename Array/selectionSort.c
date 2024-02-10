#include<stdio.h>

int size;

void swap(int *value1, int *value2){
    *value1 = *value2 + *value1;
    *value2 = *value1 - *value2;
    *value1 = *value1 - *value2; 
}

void printArray(int *arr){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("\t%d", arr[i]);
    }
}

void selectionSort (int *arr){
    for(int i=0; i<size; i++){

        for(int j=0;j<size;j++){ //{5, 112, 1, 68, 3, 8} -> {112,68,1,3}
            if(arr[i]<arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
        printArray(arr);
    }
}

int main(){
    int arr[] = {5, 112, 1, 68, 3, 8};
    size = 6;

    selectionSort(arr);
    printArray(arr);

    return 0;
}