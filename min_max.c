#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int sz, int* pSize) {
    int* randArr = malloc(sz * sizeof(int));
    srand(time(NULL));
    int i;
    for (i = 0; i < sz; i++)
        randArr[i] = rand() % 100;
    *pSize = sz;
    return randArr;
}

int main() {
    int sz = 0;
    char input[10];
    printf("Enter the size of array: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf_s(input, "%d", &sz) != 1) {
        printf("Invalid input. Please enter an integer value.\n");
        return 1;
    }
    int* arr = create_array(sz, &sz);
    int i;
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}
