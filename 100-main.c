#include <stdio.h>
#include "sort.h"

/**
 * main - Entry point to test shell_sort
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting:\n");
    print_array(array, n);

    shell_sort(array, n);

    printf("Array after sorting:\n");
    print_array(array, n);
    return (0);
}
