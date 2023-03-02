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

int main() {
    int* arr = create_array();
    int i;
    for (i = 0; i < sizeof(arr); i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}