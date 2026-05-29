#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns the length of a linked list
 *
 * @head: Pointer to the head of the list
 *
 * Return: Length of the list
 */
static size_t list_len(listint_t *head)
{
	size_t len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 *
 * @head: Double pointer to the head of the list
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *prev;
	listint_t *tmp;
	listint_t *second_half;
	int result;
	size_t len;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	len = list_len(*head);
	slow = *head;
	fast = *head;
	prev = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}

	if (len % 2 != 0)
		slow = slow->next;

	second_half = slow;
	result = 1;

	while (prev != NULL && second_half != NULL)
	{
		if (prev->n != second_half->n)
		{
			result = 0;
			break;
		}
		prev = prev->next;
		second_half = second_half->next;
	}

	return (result);
}
