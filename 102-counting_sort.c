#include "sort.h"
#include <stdlib.h>  /* Include stdlib.h for malloc and free */

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max;
    int i;  // Change to int for loop variable

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for count and output arrays */
    count = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));
    if (count == NULL || output == NULL)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Store the count of each number */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Change count[i] so that it contains the actual position of
       this number in output[] */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i < size; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements into the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free allocated memory */
    free(count);
    free(output);
}

