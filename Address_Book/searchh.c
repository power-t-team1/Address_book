#include "common.h"
int searchh(int callcount)
{
	FILE *fp1 = fopen("Address_book.csv", "r");
	FILE *fp = fopen("Address_book.csv", "r");
	FILE *ft = fopen("Address_book.csv", "r");
	FILE *fd = fopen("dest1.txt", "w");
	char ch;
	//	ch = fgetc(fs);
	int count = 1, dist;
	char *buffer, *buffer1;
	int comma_count = 1;

	//ask for options
	int option;

	//Enter the key
	char *key = malloc(33 * sizeof(char));
	if(callcount == 0)
	{
		printf("Edit the: \n1.Name\n2.Phone number\n3.Email\n4.Serial no\n");
		scanf("%d", &option);

		printf("Enter the key\n");
		scanf("%s", key);
	}
	else
	{
		printf("Enter serial number\n");
		scanf("%s",key);
		option = 4;
	}
	int len = strlen(key);
	int tok = 1;
	int flag;
	int found = 0;
	int firstLettrMatch = 0;
	//fprintf(fd, "%s", key);
	while((ch=fgetc(fp1)) != EOF)
	{
		//fputc(ch,fd);
		if (ch == '\n')
		{
			dist = ftell(fp1) - ftell(fp) - 1;

				//getting lines in buffer
				buffer = malloc((dist) * sizeof(char));
				buffer1 = malloc((dist) * sizeof(char));
				fseek(fp1, -(dist + 1), SEEK_CUR);
				fread(buffer, dist, 1, fp1);
				fseek(fp1,1,SEEK_CUR);
				//printf("%s\n", buffer);
				fseek(fp, dist + 1, SEEK_CUR);
				strcpy(buffer1,buffer);


				//tokenizing each line from buffer
				char *token1 = strtok(buffer, ",");
				//printf("t1:%s\t", token1);
				char *token2 = strtok(NULL, ",");
				//printf("t2:%s\t", token2);
				char *token3 = strtok(NULL, ",");
				//printf("t3%s\t", token3);
				char *token4 = strtok(NULL,"\n");
				//printf("t4 %s\n", token4);

				flag = 0;
				//keep printing lines till match 
				switch(option)
				{
					case 1:
						if((strncmp(token1, key, 1) == 0) && len == 1)
						{
							flag = 1;
							firstLettrMatch = 1;
						}
						if(strcmp(token1, key) == 0)
						{
							//printf("match name\n");
							flag = 1;
						}
						break;
					case 2:
						if(strcmp(token2, key) == 0)
						{
							flag = 1;
						}
						break;
					case 3:
						if(strcmp(token3, key) == 0)
						{
							flag = 1;
						}
						break;
					case 4:
						if(strcmp(token4, key) == 0)
						{
							flag = 1;
						}
						break;
					default:
						printf("invalid option\n");
				}
				if(flag == 0)
				{
					//printf("buff--->%s\n",buffer1);
					//printf("xyz\n");
					//fprintf(fd, "%s\n", buffer1);
					fprintf(fd, "%s,", token1);
					fprintf(fd, "%s,", token2);
					fprintf(fd, "%s,", token3);
					fprintf(fd, "%d",  tok++);
				
					fprintf(fd,"\n");
					//fwrite(key, 1, dist, fd);
					//printf("yzv\n");
				}
				if(flag == 1)
				{
					printf("%s,", token1);
					printf("%s,", token2);
					printf("%s,", token3);
					printf("%d",  tok++);

					printf("\n");
					//printf("Enter the term to edit\n");

					//printf("seeked\n");
					//fseek(fp1,dist,SEEK_CUR);
					found = 1;
					flag = 0;
				}
		}
	}
	if(firstLettrMatch == 1)
	{
		searchh(1);
	}
	if(found == 0)
	{
		printf("Entry not in the list!!\n");
	}
}
