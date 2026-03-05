/*
 * Linkedlist.c
 *
 * Created: 3/4/2026 1:57:26 PM
 *  Author: Mahmoud Ehab
 */ 

#include <stdlib.h>
#include <stdio.h>
#include "Linkedlist.h"

void Linkedlist_constructor(Linkedlist* this)
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

int is_empty(Linkedlist* this)
{
	return this->head == NULL;
}

void insert_first(Linkedlist* this, int item, int flag_op)
{
	Node* newnode = malloc(sizeof(*newnode));
	
	newnode->data = item;
	newnode->flag_op = flag_op;
	newnode->next = this->head;

	if (this->head == NULL)
	{
		this->tail = newnode;
	}

	this->head = newnode;

	this->length++;
}

int append(Linkedlist* this, int item, int flag_op)
{
	if (is_empty(this))
	{
		insert_first(this, item, flag_op);
		return -1;
	}

	Node* newnode = malloc(sizeof(*newnode));

	newnode->data = item;
	newnode->flag_op = flag_op;
	newnode->next = NULL;
	
	this->tail->next = newnode;

	this->tail = newnode;

	this->length++;

	return 0;
}

int insert_before(Linkedlist* this, int item, int flag_op, int before_this_item)
{
	if (is_empty(this))
	{
		insert_first(this, item, flag_op);
		return -1;
	}

	if (this->head->data == before_this_item)
	{
		insert_first(this, item, flag_op);
		return -1;
	}

	Node* newnode = malloc(sizeof(*newnode));

	newnode->data = item;
	newnode->flag_op = flag_op;

	Node* temp = this->head;

	while (temp->next != NULL)
	{
		if (temp->next->data == before_this_item)
		{
			newnode->next = temp->next;
			temp->next = newnode;
			this->length++;
			return 0;
		}
		temp = temp->next;
	}

	return -2;
}

int insert_after(Linkedlist* this, int item, int flag_op, int after_this_item)
{
	if (is_empty(this))
	{
		insert_first(this, item, flag_op);
		return -1;
	}

	Node* newnode = malloc(sizeof(*newnode));

	newnode->data = item;
	newnode->flag_op = flag_op;

	Node* temp = this->head;

	while (temp->next != NULL)
	{
		if (temp->data == after_this_item)
		{
			newnode->next = temp->next;
			temp->next = newnode;

			if (newnode->next == NULL)
			{
				this->tail = newnode;
			}

			this->length++;

			return 0;
		}
		temp = temp->next;
	}
	
	return -2;
}

void display(Linkedlist* this)
{
	Node* temp = this->head;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int count(Linkedlist* this)
{
	return this->length;
}

int search_item(Linkedlist* this, int search_this_item)
{
	Node* temp = this->head;
	int index = 0;

	while (temp != NULL)
	{
		if (temp->data == search_this_item)
		{
			return index;
		}
		index++;
		temp = temp->next;
	}

	return -1;
}

int del_first(Linkedlist* this)
{
	if (is_empty(this))
	{
		return -1;
	}

	if (this->head->next == NULL)
	{
		this->tail = NULL;
	}

	Node* del_ptr = this->head;

	this->head = del_ptr->next;

	free(del_ptr);

	this->length--;

	return 0;
}

int del(Linkedlist* this, int delete_this_item)
{
	if (is_empty(this))
	{
		return -1;
	}

	if (this->head->next == NULL || this->head->data == delete_this_item)
	{
		del_first(this);
		return -2;
	}
	
	Node* del_ptr = this->head;
	Node* temp = this->head;

	while (temp->next != NULL)
	{
		if (temp->next->data == delete_this_item)
		{
			del_ptr = temp->next;
			temp->next = del_ptr->next;
			free(del_ptr);
			
			if (temp->next == NULL)
			{
				this->tail = temp;
			}

			this->length--;

			return 0;
		}
		temp = temp->next;
	}
	
	return -3;
}

int del_before(Linkedlist* this, int delete_item_before_this_item)
{
	if (is_empty(this))
	{
		return -1;
	}

	if (this->length == 1)
	{
		return -2;
	}

	if (this->head->next->data == delete_item_before_this_item)
	{
		del_first(this);
		return 0;
	}
	
	Node* temp = this->head;
	Node* del_ptr = NULL;

	while (temp->next->next != NULL)
	{
		if (temp->next->next->data == delete_item_before_this_item)
		{
			del_ptr = temp->next;
			temp->next = del_ptr->next;
			
			free(del_ptr);
			this->length--;

			return 0;
		}
		
		temp = temp->next;
	}

	return -3;
}

int del_after(Linkedlist* this, int delete_item_after_this_item)
{
	if (is_empty(this))
	{
		return -1;
	}

	Node* temp = this->head;
	Node* del_ptr = NULL;

	while (temp != NULL)
	{
		if (temp->data == delete_item_after_this_item)
		{
			if (temp -> next != NULL)
			{
				
				del_ptr = temp->next;
				temp->next = del_ptr->next;

				if (del_ptr->next == NULL)
				{
					this->tail = temp;
				}

				free(del_ptr);

				this->length--;

				return 0;
			}
			else
			{
				return -2;
			}
		}

		temp = temp->next;
	}

	return -3;
}

int del_with_ptr(Linkedlist* this, Node* temp_ptr, Node* del_ptr)
{
	if (del_ptr == NULL || temp_ptr == NULL)
	{
		return -2;
	}
	else if (temp_ptr == del_ptr)
	{
		del(this, del_ptr->data);
		return 0;
	}
	else if (temp_ptr->next != del_ptr)
	{
		del(this, del_ptr->data);
		return 0;
	}

	if (is_empty(this))
	{
		return -1;
	}
	else if (this->length == 1)
	{
		del_first(this);
		return 0;
	}

	temp_ptr->next = del_ptr->next;

	if (temp_ptr->next == NULL)
	{
		this->tail = temp_ptr;
	}

	free(del_ptr);

	this->length--;

	return 0;
}

int pop(Linkedlist* this)
{
	if (is_empty(this))
	{
		return -1;
	}

	if (this->head->next == NULL)
	{
		del_first(this);
		return -2;
	}

	Node* del_ptr = this->head;
	Node* temp = this->head;

	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}

	del_ptr = temp->next;
	temp->next = NULL;
	free(del_ptr);
	this->tail = temp;

	this->length--;

	return 0;
}

void empty(Linkedlist* this)
{
	while (!is_empty(this))
	{
		del_first(this);
	}
}

int replace(Linkedlist* this, int item, int flag_op, int replace_this_item)
{
	if (is_empty(this))
	{
		return -1;
	}

	Node* temp = this->head;

	while (temp != NULL)
	{
		if (temp->data == replace_this_item)
		{
			temp->data = item;
			temp->flag_op = flag_op;
			return 0;
		}

		temp = temp->next;
	}

	return -2;
}