#include "common.h"

int convert()
{
	FILE *fp, *fd, *fp1;
	fp = fopen("sth.txt", "rb");
	fp1	= fopen("sth.txt", "rb");

	char *name = malloc(20 * sizeof(char));
	char *buffer = malloc(20 * sizeof(char));
	char *buff2 = malloc(20 * sizeof(char));

	printf("Enter the name: ");
	scanf("%s", name);
	fd = fopen("mar.txt", "wb");

	char ch, ch1;
	FILE *ft;
	ft = fopen("sth.txt", "rb");
	int c = 0, ct = 0, dist;
	ch = fgetc(fp1);
	int count = 0;
	while(ch != EOF)
	{
		ch = fgetc(fp1);
		if(ch == ',')
		{
			printf("comma\n");
			dist = ftell(fp1) - ftell(fp) - 1;	
			buffer = malloc(dist * sizeof(char));
			fseek(fp1,-(dist+1),SEEK_CUR);
			fread(buffer, dist, 1, fp1);

			printf("buffer: %s",buffer );
			printf("\n");
			if(strcmp(buffer, name) == 0)
			{
				printf("zero\n");
				while((ch = fgetc(fp1)) != '\n');
				break;
			}
			else
			{
				fseek(fp1,-dist, SEEK_CUR);
				printf("Buffer not matched\n");
				ch = fgetc(fp1);
				fseek(fp,1,SEEK_CUR);
				while(ch != '\n')
				{
					fputc(ch, fd);
					ch = fgetc(fp1);
					fseek(fp,1,SEEK_CUR);
				}
				fputc(ch,fd);
				printf("aaaaaaa\n");
			}
		}
		/*	if(ch == '\n')
			{
			int distLINE = ftell(fp1) - ftell(ft) - 1;
			fread(buff2,1, distLINE, ft);
			fwrite(buff2,1,distLINE, fd);
			fseek(fp,dist,SEEK_CUR);
			count = 0;
			}*/
	}

	while((ch1 = fgetc(fp1)) != EOF)
	{
		fputc(ch1, fd);
	}
	//rename("mark.html", "sth.txt");
	fclose(fd);
	fclose(fp);
	return SUCCESS;
}
