/** pex2.c
 * ===========================================================
 * Name:
 * Section:
 * Project: PEX2
 * Purpose: Sorting algoritms
 * Documentation:
 * =========================================================== */

#include <stdio.h>
#include <string.h>

#include "pex2setup.h"
#include "pex2sorts.h"

/**
 * @brief Main function for the PEX 0
 * @param argc number of arguments
 * @param argv the array of arguments (as strings)
 * @pre user inputs three arguments
 */
int main(int argc, char *argv[]) {
    int sortID = 0;
    int size = 0;
    int isOrdered = 0;
    int *arrayOfNumbers;

    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        size = 40;
        printf("Testing all sorting algorithms...\n");
        arrayOfNumbers = generateRandomArray(size);

        selectionSort(arrayOfNumbers, 40);
        isOrdered = testSorted(arrayOfNumbers, size, 1);

        int allCorrect = 1;
        if (!isOrdered) {
            printf("Selection Sort - INCORRECT\n");
        }
        allCorrect = allCorrect && isOrdered;

        arrayOfNumbers = generateRandomArray(size);
        insertionSort(arrayOfNumbers, size);
        isOrdered = testSorted(arrayOfNumbers, size, 1);
        if (!isOrdered) {
            printf("Insertion Sort - INCORRECT\n");
        }
        allCorrect = allCorrect && isOrdered;

        arrayOfNumbers = generateRandomArray(size);
        bubbleSort(arrayOfNumbers, size);
        isOrdered = testSorted(arrayOfNumbers, size, 1);
        if (!isOrdered) {
            printf("Bubble Sort - INCORRECT\n");
        }
        allCorrect = allCorrect && isOrdered;

        arrayOfNumbers = generateRandomArray(size);
        mergeSort(arrayOfNumbers, size);
        isOrdered = testSorted(arrayOfNumbers, size, 1);
        if (!isOrdered) {
            printf("Merge Sort - INCORRECT\n");
        }
        allCorrect = allCorrect && isOrdered;

        if (allCorrect) {
            printf("All sorts were successful!");
        }
    } else {
        if (argc == 3) {
            sortID = atoi(argv[1]);
            size = atoi(argv[2]);
        }

        // read in three items from the command line
        if (argc == 3 && sortID > 0 && sortID <= 4 && size > 0 && size <= 20000) {
            arrayOfNumbers = generateRandomArray(size);

            // Print the array for debugging
            printf(" ********** Initial Array *********\n");
            printArray(arrayOfNumbers, size);
            printf("\n");

            switch (sortID) {
                case 1:
                    printf("Running Selection Sort\n");
                    selectionSort(arrayOfNumbers, size);
                    break;
                case 2:
                    printf("Running Insertion Sort\n");
                    insertionSort(arrayOfNumbers, size);
                    break;
                case 3:
                    printf("Running Bubble Sort\n");
                    bubbleSort(arrayOfNumbers, size);
                    break;
                case 4:

                    printf("Running Merge Sort\n");
                    mergeSort(arrayOfNumbers, size);
                    break;
            }

            // Test if the array is ordered and report accordingly

            isOrdered = testSorted(arrayOfNumbers, size, 1);
            if (isOrdered) {
                printf("The array is sorted in descending order\n");
            } else {
                printf("The array is NOT sorted in descending order\n");
            }
            printf("\n ********** Final Array *********\n");
            printArray(arrayOfNumbers, size);
            printf("\n");
        } else {
            printf("usage pex2.exe sort_id size\n");
            printf("  sort_id can be 1: selection, 2: insertion, 3: bubble, 4: merge");
            printf("  size must be between 0 and 20000");
        }
    }
}