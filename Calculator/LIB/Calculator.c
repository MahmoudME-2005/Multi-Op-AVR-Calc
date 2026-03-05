/*
 * Calculator.c
 *
 * Created: 3/4/2026 6:29:11 PM
 *  Author: Mahmoud Ehab
 */ 

#include "Calculator.h"

int powME(int base, int exponent)
{
    int result = 1;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

int parse_int(Linkedlist* list)
{
    Node* temp = list->head;
    int result = 0;

    for (int i = list->length - 1; i >= 0; i--)
    {
        result += (temp->data - 48) * powME(10, i);
        temp = temp->next;
    }

    return result;
}

int handle_order_2(Linkedlist* list)
{
    Node* temp = list->head;
    Node* extra = 0;
    Node* del_ptr1 = 0;
    Node* del_ptr2 = 0;

    while (temp->next != 0)
    {
        if (temp->next->next->data == '-')
        {
            temp->next->next->next->data = -temp->next->next->next->data;
            del_ptr1 = temp->next->next;
            del_with_ptr(list, temp->next, del_ptr1);
        }

        if (temp->next->data == 'X')
        {
            temp->data = temp->data * temp->next->next->data;
            del_ptr1 = temp->next;
            del_ptr2 = temp->next->next;
            del_with_ptr(list, temp, del_ptr1);
            del_with_ptr(list, temp, del_ptr2);
        }
        else if (temp->next->data == '/')
        {
            if (temp->next->next->next != 0)
            {
                if (temp->next->next->next->data == 'X')
                {
                    extra = temp->next->next;

                    if (extra->next->next->data == '-')
                    {
                        extra->next->next->next->data = -extra->next->next->next->data;
                        del_ptr1 = extra->next->next;
                        del_with_ptr(list, extra->next, del_ptr1);
                    }

                    temp->data = temp->data * extra->next->next->data;
                    del_ptr1 = extra->next;
                    del_ptr2 = extra->next->next;
                    del_with_ptr(list, extra, del_ptr1);
                    del_with_ptr(list, extra, del_ptr2);
                }
            }
            temp->data = temp->data / temp->next->next->data;
            del_ptr1 = temp->next;
            del_ptr2 = temp->next->next;
            del_with_ptr(list, temp, del_ptr1);
            del_with_ptr(list, temp, del_ptr2);
        }
        else if (temp->next->data == '-' || temp->next->data == '+')
        {
            temp = temp->next->next;
            continue;
        }
        else
        {
            return -1;
        }
    }
}

int handle_order_1(Linkedlist* list)
{
    Node* temp = list->head;
    Node* del_ptr1 = 0;
    Node* del_ptr2 = 0;

    while (temp->next != 0)
    {
        if (temp->next->next->data == '-')
        {
            temp->next->next->next->data = -temp->next->next->next->data;
            del_ptr1 = temp->next->next;
            del_with_ptr(list, temp->next,del_ptr1);
        }

        if (temp->next->data == '+')
        {
            temp->data = temp->data + temp->next->next->data;
            del_ptr1 = temp->next;
            del_ptr2 = temp->next->next;
            del_with_ptr(list, temp, del_ptr1);
            del_with_ptr(list, temp, del_ptr2);
        }
        else if (temp->next->data == '-')
        {
            temp->data = temp->data - temp->next->next->data;
            del_ptr1 = temp->next;
            del_ptr2 = temp->next->next;
            del_with_ptr(list, temp, del_ptr1);
            del_with_ptr(list, temp, del_ptr2);
        }
        else
        {
            return -1;
        }
    }
}

int calculate(Linkedlist* list)
{
	if (list->head->data == '-')
	{
		list->head->next->data = -list->head->next->data;
		del_first(list);
	}
    if (list->length > 1 && list->length < 3)
    {
        return -1;
    }

    handle_order_2(list);

    if (list->head->data == '-')
    {
        list->head->next->data = -list->head->next->data;
        del_first(list);
	}
    if (list->length > 1 && list->length < 3)
    {
        return -1;
    }

    handle_order_1(list);

    return list->head->data;
}