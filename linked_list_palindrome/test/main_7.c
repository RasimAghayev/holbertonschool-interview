#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - create long even numbered list not palindrome and check
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	listint_t *current;
	int i;

	head = NULL;
	for (i = 0; i < 1001; i++)
		add_nodeint_end(&head, i);
	for (i = 1000; i >= 0; i--)
		add_nodeint_end(&head, i);

	current = head;
	for (i = 0; i < 727; i++)
		current = current->next;
	current->n = -98;

	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(head);

	return (0);
}
