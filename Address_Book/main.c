#include "common.h"

int flag = 0;

int main()
{
	char selection;
	//Declaring structere of addressbook, array of contacts
	addressbook book;
	contact_info *contacts;
	book.fp = fopen("Address_book.csv", "a");

	//Validation
	if (book.fp == NULL)
	{
		perror("Address_book.csv");
		return 0;
	}

	//Getting the line count of address_book.csv
	int option, size, status; 
	book.count = 0;

	while(1)
	{
		//Prompt + read the operation
		printf("Select an option\n1.Add Contact\n2.Search Contact\n3.Edit Contact\n4.Delete Contact\n5.List Contacts\n6.Save Contacts\n7.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				if (flag)
				{
					printf("Do you want to save previous contacts.. Press[ y | n ]: ");
					scanf("\n%c", &selection);

					switch(selection)
					{
						case 'y':
							//Calling the save contact function
							status = save_contact(&book);
							if (status == SUCCESS)
							{
								printf("Address book data has been saved\n\n");
							}
							else
							{
								printf("Unable to save address book data\n\n");
							}

						case 'n': 
							//Reseting the flag to zero
							flag = 0;
					}
				}
				if (flag == 0)
				{
					//Prompt to enter the number of contacts to be inserted
					printf("Enter the number of contacts to insert : ");
					scanf("%d", &size);
					contacts = malloc(size * sizeof(contact_info));
					//Calling the add contact function
					status = add_contact(&contacts, size);
					book.list = contacts;
					book.count = size;
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
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				if (flag)
				{
				//Calling the list contact function
				list_contact(&book);
				}
				else
				{
					printf("No data has been entered\n");
				}
				break;

			case 6:
				//Calling the save contact function to append the details in addressbook
				if(flag)
				{
					status = save_contact(&book);
					if (status == SUCCESS)
					{
						printf("Address book data has been saved\n\n");
					}
					else
					{
						printf("Unable to save address book data\n\n");
					}
				}
				else
				{
					printf("No data has been entered\n");
				}
				break;

			case 7:
				//Exiting the loop
				return 0;

			default:
				printf("Invalid selection\n");
		}

	}


}

