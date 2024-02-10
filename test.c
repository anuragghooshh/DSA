#include<stdio.h>

void function(int *arr){
    printf("\t%d",arr[0]);
    printf("\t%d",*(arr+1));
    printf("\t%d",*arr+1);
}

int main(){
    int arr[] = {45,81,620};
    function(arr);

    return 0;
}