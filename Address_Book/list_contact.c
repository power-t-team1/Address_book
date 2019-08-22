#include "common.h"

int list_contact(addressbook *book)
{
	//Declare the variables
	int i, flag = 0;
	char ch, choice;
	FILE *f1, *f2, *f3, *f4;
	f1 = f2 = f3 = f4 = book->fp;

	//Iterate till the end of the .csv file
	while((*book).count)
	{
		//Print only 5 contacts on the stdout
		for (i = 0; i < 5 && (*book).count != '\0'; i++)
		{
			while((ch = fgetc(f4))!= '\n')
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
		flag++;
		//Update the address of the page pointers
		if (flag == 1)
		{
			f2 = f4;
		}
		else
		{
			f3 = f4;
		}

		//Prompt if the previous or next page is to be displayed
		printf("Press [ p | n ] for Previous or Next page: ");
		scanf("\n%c", &choice);
		switch (choice)
		{
			case 'p':
				if (flag == 2)
				{
					f4 = f1;
					flag--;
				}
				else if(flag == 3)
				{
					f4 = f2;
					flag--;
				}
				else
				{
					printf("There is no previous page\n");
				}
				break;

			case 'n':
				if (flag == 1)
				{
					f4 = f2;
					flag--;
				}
				else if(flag == 2)
				{
					f4 = f3;
					flag--;
				}
				else
				{
					printf("There is no next page\n");
				}
				break;
		}
	}
}

