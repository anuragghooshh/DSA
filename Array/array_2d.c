#include<stdio.h>
#include<stdlib.h>


int main(){

    int arr[][4] = {{1,2,3,4},{7,8,9,10},{13,14,15,16}};

    printf("%d", sizeof(arr)/sizeof(arr[1])); //The size of the parent array is 3 consisting of 3 child arrays. (Size of array in bytes/Size of 1 array item in bytes)
    printf("\n%d\n", sizeof(arr[2])/sizeof(arr[1][0])); //The size of the child array is 3 consisting of 3 items. (Size of array in bytes/Size of 1 array item in bytes)

    int parentArrSize =  sizeof(arr)/sizeof(arr[0]);
    int childArrSize = sizeof(arr[0])/sizeof(arr[0][0]);

    for(int i=0; i<parentArrSize; i++){
        printf("\n");
        for(int j=0; j<childArrSize; j++){
            printf("%d\t", arr[i][j]);
        }
    }

    return 0;
}