#include "common.h"

int main()
{
	char buffer[40];
	//	FILE *fs = fopen("address_book.csv", "r");
	//Declaring structere of addressbook, array of contacts
	addressbook book;
	contactinfo *contacts;
	book.fp = fopen("elamathi.csv", "a");

	//Getting the line count of address_book.csv
	int ch, option, size, i, flag = 0;
	book.count = 0;
	while(1)
	{
		//Prompt + read the operation
		printf("Select an option\n1.Insert data\n2.Print data\n3.Search data\n4.Edit data\n5.Delete data\n6.Save data\n7.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Enter the number of contacts to insert : ");
				scanf("%d", &size);
				contacts = malloc(size * sizeof(contactinfo));
				for (i = 0; i < size; i++)
				{
					//Enter the details of the contact
					printf("Enter the name : ");
					scanf("\n%[^\n]s", buffer);
					getchar();
					strcpy(contacts[i].name, buffer);
					printf("Enter the phone number : ");
					scanf("%[^\n]s", buffer);
					strcpy(contacts[i].phone_numbers, buffer);
					printf("Enter the email address : ");
					scanf("\n%[^\n]s", buffer);
					strcpy(contacts[i].email_addresses, buffer);
					contacts[i].si_no = i;

				}
				book.list = contacts;
				book.count = size;
				flag = 1;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				//Calling the function to append the details in addressbook
/*				if(flag)
				{
					save_data(&book);
					for(i = 0; i < size; i++)
					{
						free(&contacts[i]);
						//					free(&contacts[i].phone_numbers);
						//					free(&contacts[i].email_addresses);
					}

				}*/
				break;
			case 7:
				return 0;
			default:
				printf("Invalid selection\n");
		}

	}


}

//Defining the save data function
int save_data(addressbook *book)
{
	int i;
	for(i = 0; i < book->count; i++)
	{
		fprintf(book->fp, "%s,%s,%s,%d\n", book->list[i].name, book->list[i].phone_numbers, book->list[i].email_addresses, book->list[i].si_no);
	}
}
