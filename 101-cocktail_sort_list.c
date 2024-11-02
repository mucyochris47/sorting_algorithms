#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: The left node to swap
 * @right: The right node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    if (right->next)
        right->next->prev = left;
    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;

    if (!right->prev)
        *list = right;
    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the
 * Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (!list || !*list || !(*list)->next)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                swapped = 1;
            } else {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        while (current->prev) {
            if (current->n < current->prev->n) {
                swap_nodes(list, current->prev, current);
                swapped = 1;
            } else {
                current = current->prev;
            }
        }
    } while (swapped);
}

