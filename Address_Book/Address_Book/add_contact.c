#include "common.h"

extern int flag;

int add_contact(contact_info **contacts, int size, addressbook *book)
{
	//Declare the variables
	int i;

	//Populate the address book info
	for (i = 0; i < size; i++)
	{
		//Declaring a buffer variable 
		char *buffer = malloc (32 * sizeof(char));
		printf("Enter contact name: ");
		scanf("\n%[^\n]s", buffer);
		getchar();
		strcpy((*contacts)[i].name, buffer);
		printf("Enter phone number: ");
		scanf("%s", buffer);
		getchar();
		strcpy((*contacts)[i].phone_numbers, buffer);
		printf("Enter email address: ");
		scanf("%s", buffer);
		strcpy((*contacts)[i].email_addresses, buffer);
		(*contacts)[i].sl_no = ++(*book).count;
	}
	flag = 1;
	return SUCCESS;

}
