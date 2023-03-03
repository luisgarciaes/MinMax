#include <stdio.h>

#include <stdlib.h>

#include <time.h>

// program for finding the maximum and minimum values on an array
// made by Luis Gerardo García Espinoza 6G
// for the Parallel Programming class
// taught by the professor Ramirez Alcaraz Juan Manuel


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
    int* randArr = malloc(sz * sizeof(int)); //allocating memory for dynamic access
    srand(time(NULL)); //using the time for a completely random seed for picking a number
    int i;
    for (i = 0; i < sz; i++) //loop for filling the array with random numbers from 0 to 1000
        randArr[i] = rand() % 1000;
    *pSize = sz;
    return randArr;
}

// this function takes an array and returns the maximum value and the minimum value
int* find_min_max(int arr[], int length) {
    int max_index = length - 1;
    int min = arr[0];
    int max = arr[max_index];
    printf("\nMINIMUM VALUE IN THE ARRAY: ");
    printf("%d\n", min);
    printf("MAXIMUM VALUE IN THE ARRAY: ");
    printf("%d\n ", max);
}
int main() {
    printf("  /\\_/\\\n"); // It's a cute cat added for aesthetics
    printf(" ( o.o ) MINMAX ARRAY PROGRAM\n");
    printf("  > ^ <  MADE BY LUIS GERARDO GARCIA ESPINOZA\n");
    printf("\n////////////////////////////////////////////////////\n\n"); 

    // code part starts here
    int sz = 0;
    char input[10];

    printf("ENTER THE SIZE OF THE ARRAY: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf_s(input, "%d", &sz) != 1) { // visual studio screamed at me to use sscanf_s for security
        printf("INVALID INPUT. PLEASE ENTER AN INTEGER VALUE\n");
        return 1;
    }
    printf("\n////////////////////////////////////////////////////\n\n");
    int* arr = create_array(sz, &sz);
    int i;
    bubble_sort(arr, sz); // using the function we made earlier to sort the array
    printf("SORTED ARRAY: ");
    printf("[ ");
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("]");
    find_min_max(arr,sz); // same thing as earlier
    free(arr); //freeing up memory
    return 0;
}