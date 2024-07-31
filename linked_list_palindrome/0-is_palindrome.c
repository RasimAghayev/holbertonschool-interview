#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	return (palindrome_check(head, *head));
}

/**
 * palindrome_check - checks is list is a palindrome recursively
 * @head: double pointer to beginning of list
 * @mover: single pointer to list to move to end
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */
int palindrome_check(listint_t **head, listint_t *mover)
{
	if (mover->next)
	{
		if (palindrome_check(head, mover->next))
			(*head) = (*head)->next;
		else
			return (0);
	}
	if ((*head)->n == mover->n)
		return (1);
	return (0);
}
