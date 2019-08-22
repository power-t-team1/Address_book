#include "common.h"

extern int flag;

int save_contact(addressbook *book)
{
	//Declare the variables
	int i;

	for(i = 0; i < book->count; i++)
	{
		fprintf(book->fp, "%s,%s,%s,%d\n", book->list[i].name, book->list[i].phone_numbers, book->list[i].email_addresses, book->list[i].sl_no);
	}
	flag = 0;
	return SUCCESS;
}

