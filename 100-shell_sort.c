#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate initial Knuth sequence gap */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Perform Shell sort */
    while (gap >= 1)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            array[j] = temp;
        }
        print_array(array, size);
        gap /= 3;
    }
}

