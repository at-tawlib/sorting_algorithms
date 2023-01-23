#include "sort.h"

/**
 * insertion_sort_list - sorts a doubli linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		node = iter->prev;
		printf("node : %d, prev : %d, next : %d\n", iter->n, node->n, temp->n);
		while (node != NULL && iter->n < node->n)
		{
			swap_nodes(list, &node, iter);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - swap two nodes in a doubly-linked list
 * @head: head of node
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
