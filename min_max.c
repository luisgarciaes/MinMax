#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int sz, int* pSize) {
    int* randArr = malloc(sz * sizeof(int));
    srand(time(NULL)); // seed the random number generator
    int i;
    for (i = 0; i < sz; i++)
        randArr[i] = rand() % 100; // generate random numbers between 0 and 99
    *pSize = sz; // store the size of the array in the memory location pointed to by pSize
    return randArr;
}

int main() {
    int sz = 0;
    printf("Enter the size of array: ");
    scanf("%d", &sz);
    int* arr = create_array(sz, &sz); // pass the size of the array and a pointer to sz
    int i;
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}
