/*
 * Linkedlist.h
 *
 * Created: 3/4/2026 1:57:40 PM
 *  Author: Mahmoud Ehab
 */ 


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct Node
{
	int data;
	int flag_op;
	struct Node* next;
} Node;

typedef struct  
{
	Node* head;
	Node* tail;
	int length;
} Linkedlist;

void Linkedlist_constructor(Linkedlist* this);

int is_empty(Linkedlist* this);

void insert_first(Linkedlist* this, int item, int flag_op);

int append(Linkedlist* this, int item, int flag_op);

int insert_before(Linkedlist* this, int item, int flag_op, int before_this_item);

int insert_after(Linkedlist* this, int item, int flag_op, int after_this_item);

void display(Linkedlist* this);

int count(Linkedlist* this);

int search_item(Linkedlist* this, int search_this_item);

int del_first(Linkedlist* this);

int del(Linkedlist* this, int delete_this_item);

int del_before(Linkedlist* this, int delete_item_before_this_item);

int del_after(Linkedlist* this, int delete_item_after_this_item);

int del_with_ptr(Linkedlist* this, Node* temp_ptr, Node* del_ptr);

int pop(Linkedlist* this);

void empty(Linkedlist* this);

int replace(Linkedlist* this, int item, int flag_op, int replace_this_item);

#endif /* LINKEDLIST_H_ */