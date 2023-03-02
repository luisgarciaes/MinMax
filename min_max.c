#include <stdio.h>
#include <stdlib.h>

int* create_array() {
    int sz = 0;
    printf("Enter the size of array::");
    scanf("%d", &sz);
    int* randArr = malloc(sz * sizeof(int));
    int i;
    for (i = 0; i < sz; i++)
        randArr[i] = rand() % 1;
    return randArr;
}

int main(){
    create_array();
}
