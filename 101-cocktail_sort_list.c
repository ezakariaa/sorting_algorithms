#include "sort.h"

/**
 * swap_node_a - Swaps a node in a listint_t doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @t: A pointer to the tail of the doubly-linked list.
 * @cocktail_sh: A pointer to the current swapping node.
 */
void swap_node_a(listint_t **list, listint_t **t, listint_t **cocktail_sh)
{
	listint_t *temp = (*cocktail_sh)->next;

	if ((*cocktail_sh)->prev != NULL)
		(*cocktail_sh)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*cocktail_sh)->prev;
	(*cocktail_sh)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *cocktail_sh;
	else
		*t = *cocktail_sh;
	(*cocktail_sh)->prev = temp;
	temp->next = *cocktail_sh;
	*cocktail_sh = temp;
}

/**
 * swap_node_b - Swap a node in a listint_t doubly-linked
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @t: A pointer to the t of the doubly-linked list.
 * @cocktail_sh: A pointer to the current swapping node.
 */
void swap_node_b(listint_t **list, listint_t **t, listint_t **cocktail_sh)
{
	listint_t *temp = (*cocktail_sh)->prev;

	if ((*cocktail_sh)->next != NULL)
		(*cocktail_sh)->next->prev = temp;
	else
		*t = temp;
	temp->next = (*cocktail_sh)->next;
	(*cocktail_sh)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *cocktail_sh;
	else
		*list = *cocktail_sh;
	(*cocktail_sh)->next = temp;
	temp->prev = *cocktail_sh;
	*cocktail_sh = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list
 * of integers in ascending order
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *cocktail_sh;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (cocktail_sh = *list; cocktail_sh != t; cocktail_sh = cocktail_sh->next)
		{
			if (cocktail_sh->n > cocktail_sh->next->n)
			{
				swap_node_a(list, &t, &cocktail_sh);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (cocktail_sh = cocktail_sh->prev; cocktail_sh != *list;
				cocktail_sh = cocktail_sh->prev)
		{
			if (cocktail_sh->n < cocktail_sh->prev->n)
			{
				swap_node_b(list, &t, &cocktail_sh);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
