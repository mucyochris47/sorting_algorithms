#include <stdio.h>
#include "sort.h"

int main(void)
{
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    print_array(array, n);

    counting_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);

    return (0);
}

