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
	//fp1 = fp;
	//fseek(fp1,10,SEEK_CUR);
	fd = fopen("mar.txt", "wb");

	char ch;
	FILE *ft;
	//printf("befft:%ld\n", ftell(ft));
	ft = fopen("sth.txt", "rb");
	printf("ft:%ld\n", ftell(ft));
	int c = 0, ct = 0, dist;
	ch = fgetc(fp1);
	while(ch != EOF)//ch = fgetc(fp1))//;fp1)
	{
		printf("%c\n",ch);
		ch = fgetc(fp1);
		int count = 1;
	//	while((ch = fgetc(fp1) != '\n'))
	//	{
			if(ch == ',')//&& count == 1)
			{

				printf("comma\n");
	//			count = 0;
				if(ct == 0)
				{
					dist = ftell(fp1) - ftell(fp) - 1;
					ct++;
				}
				else
				{
					dist = ftell(fp1) - ftell(fp) - 1;	
				}
				//int dist = ftell(fp1) - ftell(fp) - 1;
				buffer = malloc(dist * sizeof(char));
				printf("fp1:%ld\n", ftell(fp1));
				printf("fp:%ld\n", ftell(fp));
				printf("d:%d\n",dist );
				fread(buffer, dist, 1, fp);
				dist = ftell(fp1) - ftell(fp) - 1;
				printf("buffer: %s",buffer );
				printf("\n");
				if(strcmp(buffer, name) == 0)
				{
					printf("zero\n");
					while((ch = fgetc(fp1)) != '\n');
					break;
				}
			}
			printf("befNLfp:%ld\n", ftell(fp));
			if(ch == '\n')
			{
				int distLINE = ftell(fp1) - ftell(ft) - 1;
				printf("distLINE = %d\n", distLINE);
				fread(buff2,1, distLINE, ft);
				fwrite(buff2,1,distLINE, fd);
				fseek(fp,dist,SEEK_CUR);
				//fp = fp1;
		//		ft = fp1;
			}
		//	printf("kkkk\n");
			c++;
			//if(strcmp())
			{
			//	break;
			}
		//	if(c == 40)
			{
				//break;
			}
		//}
	}
	char ch1;
	while((ch1 = fgetc(fp1)) != EOF)
	{
		printf("dsfds\n");
		fputc(ch1, fd);
	}
	/*char *buf1 = malloc(sizeof(char) * 10);
	for (int i = 0; i < 16; i++)
	{
		fread(buf1,1,1,fp1);
		//buf1 = NULL;
		fwrite(buf1,1,1,fd);
	//	memmove(fp,fp1,1);
	//	tem = fp;
	//	fseek(fp,1,SEEK_CUR);
	//	free(tem);

	}*/
	//rename("mark.html", "sth.txt");
	//fseek(fp1,-10,SEEK_CUR);
	//for (int i = 0; i < 10; i++)
	{
		//fread(buf1,1,1,fp1);
	//	buf1 = 0x00 ;
	//	fwrite(buf1,1,1,fp);

	//	tem = fp;
	//	fseek(fp,1,SEEK_CUR);
	//	free(tem);

	}
	//char *buf = malloc(sizeof(char) * 10);
	/*while((fscanf(fp,"%s",buf )) != EOF)
	{
		fprintf(fd,"%s",buf);
	}*/
	//while((ch = fgetc(fp)) != EOF)
	{
	//	fputc(ch, fd);
	}
	fclose(fd);
	fclose(fp);
	return SUCCESS;
}