#include "common.h"

int search_contact(FILE * f1, char *serch_name)
{
	Cursor *head = NULL, *ptr;
	Cursor *tail = NULL;
	char ch, previous;
	int flag;
	char serial_number[4] = {'\0'}, temp[4] = {'\0'};
	int position, status, count, i;

	//	printf("name: %s", serch_name);

	FILE *fs = fopen("Address_book.csv", "r");

	if (fs == NULL)
	{
		perror("Address_book.csv");
		return FAILURE;
	}


	while(1)
	{
		//		printf("\nentry1");
		position = ftell(fs);
		previous = '\n';
		count = 1;
		while((ch = fgetc(fs)) != '\n' && ch != EOF)
		{


			if (((ch == serch_name[0]) == 1) /*&& count == 3*/ && previous == '\n')
			{
				//	printf("match");
				insert_last(&head, &tail, position);
			}
			previous = ch;		
		}

		if (ch == EOF)
		{
			//	printf("exit try\n");
			status = display_m_names(head);
			if (status != SUCCESS)
			{
				return FAILURE;
			}
			else
			{
				printf("Enter the serial number: ");
				//Here enter the serial number serial_number
				scanf("%s", serial_number);
				//	printf("serial_no= %s\n", serial_number);
				ptr = head;
				while(ptr)
				{
					fseek(fs, ptr->address, SEEK_SET);
					i = 0;
					int loc = 0;

					while ((ch = fgetc(fs)) != '\n')
					{
						if (loc == 3)
						{
							//	printf("ch = %c ", ch);
							temp[i] = ch;
							i++;
						}
						if (ch == ',')
						{
							++loc;
						}
					}
					//printf("temp = %s\n", temp);
					if (strcmp(serial_number, temp) == 0)
					{
						//	printf("match\n");
						printf("Contact Deteils\n");
						fseek(fs, ptr->address, SEEK_SET);
						while((ch = fgetc(fs)) != '\n')
						{
							if (ch == ',')
							{
								printf("\t");
								continue;
							}
							printf("%c", ch);
						}
						printf("\n");
						return ptr->address;						
					}
					ptr = ptr->next; 
				}

			}
			return SUCCESS;
		}

	}
	return SUCCESS;
}

int display_m_names(Cursor *head)
{
	if (head == NULL)
	{
		return FAILURE;
	}
	FILE *fs = fopen("Address_book.csv", "r");
	char ch;
	int count;
	while(head) 
	{
		fseek(fs, head->address, SEEK_SET);
		count = 0;
		while((ch = fgetc(fs)) != '\n')
		{
			if (ch == ',')
			{
				count++;
				if (count == 3)
				{
					printf("\t");
				}
			}
			else if(count == 0 || count == 3)
			{
				printf("%c", ch);
			}
		}
		printf("\n");
		head = head->next;

	}
	return SUCCESS;
}
