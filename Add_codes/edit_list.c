#include "common.h"

int edit_contact(char *changes, int location, int flag)
{
	FILE *fe = fopen("Address_book.csv", "r");
	FILE *fd = fopen("Temp.csv", "w");
	char ch;
	int count = 0;
	while((ch = fgetc(fe)) != EOF)
	{
		if (ftell(fe) == location)
		{
			fprintf(fd, "\n");
			while ((ch = fgetc(fe)) != '\n')
			{
				if (ch == ',')
				{
					++count;
				fputc(ch, fd);
				}
				if(flag == count)
				{

					fprintf(fd, "%s", changes);
					while((ch = fgetc(fe)) != ',');
					break;
				}
				fputc(ch, fd);
			}
		}
		fputc(ch, fd);
	}
	fclose(fe);
	fclose(fd);

	fe = fopen("Address_book.csv", "w");
	fd = fopen("Temp.csv", "r");

	while((ch = fgetc(fd)) != EOF)
	{
		fputc(ch, fe);
	}
	fclose(fe);
	fclose(fd);

}
