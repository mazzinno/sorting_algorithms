#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly LL of integers in ascending order.
 *
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (index = (*list)->next; index != NULL; index = tmp)
	{
		tmp = index->next;
		insert = index->prev;

		while (insert != NULL && index->n < insert->n)
		{
			insert->next = index->next;
			if (index->next != NULL)
				index->next->prev = insert;
			index->prev = insert->prev;
			index->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = index;
			else
				*list = index;
			insert->prev = index;
			insert = index->prev;
			print_list((const listint_t *)*list);
		}
	}
}
