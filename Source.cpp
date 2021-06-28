#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

struct Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

struct Node* delete_beginning(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
	return head_ref;
}

void delete_end(struct Node *head_ref)
{
	struct Node *curr = head_ref, *prev = head_ref;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	free(curr);
	prev->next = NULL;
}

void delete_any(struct Node *head_ref, int del)
{
	struct Node *curr = head_ref, *prev = head_ref;
	while (curr->data != del)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}

void main()
{
	struct Node *head = NULL;
	head = push(head, 18);
	head = push(head, 15);
	head = push(head, 12);
	head = push(head, 9);
	head = push(head, 6);
	head = push(head, 3);
	head = push(head, 1);
	printList(head);
	head = delete_beginning(head);
	printf("\nafter deletion from beginning : \n");
	printList(head);
	delete_end(head);
	printf("\n\nafter deletion from end : \n");
	printList(head);
	delete_any(head, 9);
	printf("\n\nafter deletion at particular position : \n");
	printList(head);
	delete_any(head, 6);
	printf("\n\nafter deletion at particular position : \n");
	printList(head);
	_getch();
}