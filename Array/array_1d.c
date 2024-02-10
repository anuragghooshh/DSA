#include<stdio.h>
#include<stdlib.h>


int main(){

    int arr[] = {1,5,9,14,23,78,3,5,6,1,91,2};
    int n = sizeof(arr)/sizeof(arr[0]); //The sizeof() operator gives the size of array in bytes.
    
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}