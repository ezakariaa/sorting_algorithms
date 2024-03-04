#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list.
 * @head: pointer to the head of the doubly-linked list.
 * @a: pointer to the first node to swap.
 * @b: second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: Doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *x, *t;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (p = (*list)->next; p != NULL; p = t)
	{
		t = p->next;
		x = p->prev;
		while (x != NULL && p->n < x->n)
		{
			swap_nodes(list, &x, p);
			print_list((const listint_t *)*list);
		}
	}
}
