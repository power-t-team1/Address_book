#include "common.h"

int insert_last(Cursor **head, Cursor **tail, int data)
{
	//Create a node
	Cursor *new = malloc (sizeof(Cursor));

	//Validation
	if (new == NULL)
	{
		return FAILURE;
	}

	//Assigning the data value and the addesses to the node
	new->address = data;
	new->prev = *tail;
	new->next = NULL;
	
	//If first node, then head value is also set to the address of the new node
	if(*head == NULL)
	{
		*head = new;
	}
	//If tail is not NULL, assigning the adddress of the current node to the next pointer of the previous node
	if (*tail != NULL)
	{
		new->prev->next = new;
	}
	//Assigning the address of the created node to the tail pointer
	*tail = new;
	return SUCCESS;
}
