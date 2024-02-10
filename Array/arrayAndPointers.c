#include<stdio.h>
#include<stdlib.h>


int main(){

    int arr[] = {1 ,7 ,8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *arrAddr[n];
    int *p1 = arr; //Pointer to Int
    
    printf("Integers and Addresses -\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t", arr[i]); //Printing Each Item's Integer Values
    }
    printf("\n");

    for(int i=0; i<n; i++){
        arrAddr[i] = p1+i; //Storing addresses of each array item in a pointer array.
    }

    for(int i=0; i<n; i++){
        printf("%d\t\t", arrAddr[i]);  //Printing Each Item's Address. 4 bytes each since it is an int.
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("%d\t\t", *arrAddr[i]); //Printing Each Item's Integer Value by dereferencing their addresses.
    }

    return 0;
}