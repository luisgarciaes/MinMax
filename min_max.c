#include <stdio.h>

#include <stdlib.h>

#include <time.h>
// program for finding the maximum and minimum values on an array
// made by Luis Gerardo García Espinoza 6G
// for the Parallel Programming class
// taught by the professor RAMIREZ ALCARAZ JUAN MANUEL


//function for the bubble sorting suggested in the instructions
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// this function creates a random array with custom size
int* create_array(int sz, int* pSize) {
    int* randArr = malloc(sz * sizeof(int));
    srand(time(NULL));
    int i;
    for (i = 0; i < sz; i++)
        randArr[i] = rand() % 1000;
    *pSize = sz;
    return randArr;
}

// this function takes an array and returns the maximum value and the minimum value
int* find_min_max(int arr[], int length) {
    int max_index = length - 1;
    int min = arr[0];
    int max = arr[max_index];
    printf("\nMinimum value in array: ");
    printf("%d\n", min);
    printf("Maximum value in array: ");
    printf("%d\n ", max);
}
int main() {
    printf("  /\\_/\\\n");
    printf(" ( o.o ) MINMAX ARRAY PROGRAM\n");
    printf("  > ^ <  MADE BY LUIS GERARDO GARCIA ESPINOZA\n");
    printf("\n////////////////////////////////////////////////////\n\n");
    int sz = 0;
    char input[10];

    printf("Enter the size of array:\n");
    fgets(input, sizeof(input), stdin);
    if (sscanf_s(input, "%d", &sz) != 1) {
        printf("Invalid input. Please enter an integer value.\n");
        return 1;
    }
    printf("\n////////////////////////////////////////////////////\n\n");
    int* arr = create_array(sz, &sz);
    int i;
    bubble_sort(arr, sz);
    printf("Here is the sorted array: \n");
    printf("[ ");
    for (i = 0; i < sz; i++)
        printf("%d, ", arr[i]);
    printf("]");
    find_min_max(arr,sz);
    free(arr);
    return 0;
}