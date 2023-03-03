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
    srand(time(NULL)); //using the time as a random seed for picking a number
    int i;
    for (i = 0; i < sz; i++) //loop for filling the array with random numbers from 0 to 1000
        randArr[i] = (rand() % 1000) + 1;
    *pSize = sz;
    return randArr;
}
// this function takes an array and returns the maximum value and the minimum value
int* find_min_max(int arr[], int length) {
    int max_index = length - 1;
    int min = arr[0];
    int max = arr[max_index];
    printf("MINIMUM VALUE IN THE ARRAY: ");
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
    clock_t start1, end1, start2, end2, start3, end3; // these are for measuring the time it takes for the functions to execute
    double cpu_time_used1, cpu_time_used2, cpu_time_used3;
    int sz = 0;
    char input[10];

    printf("ENTER THE SIZE OF THE ARRAY: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf_s(input, "%d", &sz) != 1) { // visual studio screamed at me to use sscanf_s for security
        printf("INVALID INPUT. PLEASE ENTER AN INTEGER VALUE\n");
        return 1;
    }

    printf("\n////////////////////////////////////////////////////\n\n");

    start1 = clock();
    int* arr = create_array(sz, &sz);
    end1 = clock();

    start2 = clock();
    bubble_sort(arr, sz); // using the function we made earlier to sort the array
    end2 = clock();

    start3 = clock();
    find_min_max(arr, sz);
    end3 = clock();

    cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    cpu_time_used2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    cpu_time_used3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;

    printf("\n////////////////////////////////////////////////////\n\n");
    printf("TIME TAKEN FOR create_array FUNCTION: %f seconds\n", cpu_time_used1);//the runtime for create_array and find_min_max seem to be near zero almost every time
    printf("TIME TAKEN FOR bubble_sort FUNCTION: %f seconds\n", cpu_time_used2);//it only changes with what I can assume is hardware or software variance
    printf("TIME TAKEN FOR find_min_max FUNCTION: %f seconds\n", cpu_time_used3);// on the other hand, bubble_sort seems to increase its runtime directly related to how big the array is

    free(arr); //freeing up memory
    return 0;
}