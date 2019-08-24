#include "common.h"

void list_contact(void)
{
	//Declaring the variables
	int i, flag;
	char ch, choice;
	FILE *fl = fopen("Address_book.csv", "r");

	//Validation
	if (fl == NULL)
	{
		perror("Address_book.csv");
		return;
	}
	Cursor *head = NULL;
	Cursor *tail = NULL;
	//Inserting the start location to the node
	insert_last(&head, &tail, ftell(fl));

	//Print first 5 contacts on the stdout
	printf("Address book: \n\n");
	for (i = 0; i < 5; i++)
	{
		while((ch = fgetc(fl))!= '\n' && ch != EOF)
		{
			if (ch == ',')
			{
				continue;
			}
			else
			{
				putc(ch, stdout);
			}
		}
		printf("\n");
	}
	printf("\n");
	//Iterate till the end of the .csv file
	while(1)
	{
		//Prompt if the previous or next page is to be displayed
		printf("Press [p] for Previous page, [n] for Next page, [e] for exit: ");
		scanf("\n%c", &choice);
		flag = 1;
		switch (choice)
		{
			case 'p':
				//Check and print data only if previous node is not NULL
				if (tail->prev != NULL)
				{	
					Cursor *temp = tail;
					tail = tail->prev;
					tail->next = NULL;
					free(temp);
				}
				else
				{
					printf("There is no previous page\n\n");
					flag = 0;
				}
				//Move the fl pointer to the location present in the node
				fseek(fl, (tail->address), SEEK_SET);
				break;

			case 'n':
				//Save the location of the page into the node and print data only if the ch variable hasn't reached NULL character
				if (ch != EOF)
				{
					insert_last(&head, &tail, ftell(fl));
				}
				else
				{
					printf("There is no next page\n\n");
					flag = 0;

				}
				break;

			case 'e':
				return;

			default: 
				printf("Please select the correct option\n\n");
		}
		printf("\n");
		//Print the page data only if flag is not zero
		if (flag)
		{
			//Print only 5 contacts on the stdout
			printf("Address book: \n\n");
			for (i = 0; i < 5; i++)
			{
				while((ch = fgetc(fl))!= '\n' && ch != EOF)
				{
					if (ch == ',')
					{
						continue;
					}
					else
					{
						putc(ch, stdout);
					}
				}
				printf("\n");
			}
			printf("\n");
		}

	}
}

