#include "common.h"
int traversing_function(const char *name)
{
	FILE *fp1 = fopen("Address_book.csv", "r");
	FILE *fp = fopen("Address_book.csv", "r");
	FILE *ft = fopen("Address_book.csv", "r");

	char ch;
	//	ch = fgetc(fs);
	int count = 1, dist;
	char *buffer;
	int comma_count = 1;
/*	while((ch=fgetc(fp1)) != EOF)
	{
		if (ch == ',')
		{
			if(count == comma_count)
			{
				dist = ftell(fp1) - ftell(fp) - 1;
				buffer = malloc(dist * sizeof(char));
				fseek(fp1, -(dist + 1), SEEK_CUR);
				fread(buffer , dist, 1, fp1);
				fseek(fp, dist, SEEK_CUR);
				if(strcmp(buffer, name) == 0)
				{
					printf("%s\t", buffer);
					while((ch = fgetc(fp1)) != '\n') 
					{
						fseek(fp,1, SEEK_CUR);
						if(ch == ',')
						{
							printf("\t");
							continue;
						}
						printf("%c", ch);
					}
					fseek(fp,1,SEEK_CUR);
					printf("\n");
				}
			}
			else
			{
			//	count++;
			}
		}
		else
		{
			while((ch = fgetc(fp1)) != '\n')
			{
				fseek(fp,1,SEEK_CUR);
			}
			fseek(fp,1,SEEK_CUR);
		}
	}*/
	while((ch=fgetc(fp1)) != EOF)
	{
		if (ch == '\n')
		{
			dist = ftell(fp1) - ftell(fp) - 1;

				buffer = malloc((dist) * sizeof(char));
				fseek(fp1, -(dist + 1), SEEK_CUR);
				fread(buffer, dist, 1, fp1);
				fseek(fp1,1,SEEK_CUR);
				printf("%s\n", buffer);
				fseek(fp, dist + 1, SEEK_CUR);
		}
	}





}
