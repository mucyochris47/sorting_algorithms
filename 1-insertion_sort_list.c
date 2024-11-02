#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        tmp = current;
        while (tmp->prev && tmp->n < tmp->prev->n)
        {
            /* Swap nodes */
            tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            tmp->next = tmp->prev;
            tmp->prev = tmp->prev->prev;
            tmp->next->prev = tmp;
            if (tmp->prev)
                tmp->prev->next = tmp;
            else
                *list = tmp;
            print_list(*list);
        }
        current = current->next;
    }
}

