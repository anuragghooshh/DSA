#include <stdio.h>

int size;

void swap(int *value1, int *value2){
    *value1 = *value2 + *value1;
    *value2 = *value1 - *value2;
    *value1 = *value1 - *value2; 
}

void bubbleSort(int *arr){
    int trig;

    do{
        trig = 0;

        for(int i = 0; i < size - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                trig = 1;
            }
        }
        
    } while(trig == 1);
}

void printArray(int *arr){
    for (int i = 0; i < size; i++){
        printf("\t%d", arr[i]);
    }
}

int main(){
    int arr[] = {5, 112, 1, 68, 3, 8};
    size = 6;

    bubbleSort(arr);
    printArray(arr);

    return 0;
}
