#include "common.h"

int flag = 0;

int main()
{
	char selection, search_name[10], change_details[20];
	int ch, choice, location;
	//Declaring structure of addressbook, array of contacts
	addressbook book;
	contact_info *contacts;
	//Reading the number of contacts already present in the file
	FILE *fl = fopen("Address_book.csv", "r");

	//Validation
	if (fl == NULL)
	{
		perror("Address_book.csv");
		return 0;
	}

	book.count = 0;
	//Getting the line count of address_book.csv
	while ((ch = getc(fl)) != EOF)
	{
		if (ch == '\n')
		{
			book.count++;
		}
	}
	
	//Declaring the variables
	int option, size, status; 

	while(1)
	{
		//Prompt + read the operation
		printf("Select an option\n1.Add Contact\n2.Search Contact\n3.Edit Contact\n4.Delete Contact\n5.List Contacts\n6.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				if (flag == 0)
				{
					book.fp = fopen("Address_book.csv", "a+");
					//Validation
					if (book.fp == NULL)
					{
						perror("Address_book.csv");
						return 0;
					}
					//Prompt to enter the number of contacts to be inserted
					printf("Enter the number of contacts to insert : ");
					scanf("%d", &size);
					contacts = malloc(size * sizeof(contact_info));
					//Calling the add contact function
					add_contact(&contacts, size, &book);
					book.list = contacts;
					//Save the contacts to the address book
					status = save_contact(&book, size);
					if (status == SUCCESS)
					{
						printf("Contact information has been added to the address book\n\n");
					}
					else
					{
						printf("Contact information has not been added to the address book\n\n");
					}
				}
				break;

			case 2:
				printf("Enter the name: ");
				scanf("%s", search_name);

				status = search_contact(book.fp, search_name);
				if (status != SUCCESS)
				{
					printf("Name not present\n");
				}
				break;
			case 3:
				printf("Enter the name of the contact: ");
				scanf("%s", search_name);
				location = search_contact(book.fp, search_name);
				printf("Select the option for change:\n1.Change name\n2.Change phone number\n3.Chnage email address\n ");
				scanf("%d", &choice);
				switch (choice)
				{
					case 1:
							printf("Enter the new name: ");
							scanf("%s", change_details);
							edit_contact(change_details, location, 0);
							break;
					case 2: 
							printf("Enter the new phone number: ");
							scanf("%s", change_details);
							edit_contact(change_details, location, 1);
							break;
					case 3: 
							printf("Enter the new email address: ");
							scanf("%s", change_details);
							edit_contact(change_details, location, 2);
							break;
					default:
							printf("Select the correct option\n");
						
				}
				break;
			case 4:
				break;
			case 5:
				if (flag == 0)
				{
					//Calling the list contact function
					list_contact();
				}
				else
				{
					printf("No data has been entered\n");
				}
				break;

			case 6:
				//Exiting the loop
				return 0;

			default:
				printf("Invalid selection\n");
		}

	}
}

