#include<stdio.h>
#include<stdlib.h>


int main(){

    int arr[][4] = {{16,2,3,4},{7,8,9,10},{13,14,15,16}};
    int *p1 = &arr[0][0]; //Or &arr[0]
    int *p2 = &arr[1][2];

    printf("Pointer p1 : %d", p1); //Printing value of pointer pointing to the first element of the first child array. 
    printf("\nPointer p2 : %d", p2); //Printing value of pointer pointing to the 3rd element of the second child array. 

    printf("\n\nPointer p1 : %d", *p1); //Printing de-referenced value of pointer pointing to the first element of the first child array. 
    printf("\nPointer p2 : %d", *p2); //Printing de-referenced value of pointer pointing to the 3rd element of the second child array.

    return 0;
}