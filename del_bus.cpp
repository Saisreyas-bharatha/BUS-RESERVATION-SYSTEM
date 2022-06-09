#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp,*fp1;
	char id1[100],id2[100],re[100],from[50],from1[50],to[50];
	printf("\t\t\t*DELETE BUS*\t\t\t\n");
    printf("Enter FROM: ");
    scanf("%s",from);
    strcpy(from1,from);
    char buffer[100];
    int size=100;
	char ch[size];
    strcat(from,".txt");
	fp=fopen(from,"r+");
	fp1=fopen("copy","a+");
	if(fp1==NULL)
	{
		printf("Error opening the file");
	}
	printf("Enter TO:");
	scanf("%s",to);
//	strcpy(id1,"TO:");
//	sprintf(id2,"%s",to);
//	strcat(id1,id2);
	printf("%s",to);
	while(fscanf(fp,"%s",re)!=EOF)
	{
		fprintf(fp1,"%s\n",re);
		if(strcmp(re,to)==0)
		{
			fprintf(fp1,"		->RECORD_DELETED\n");
			fseek(fp,100,SEEK_CUR);
		}
	}
	printf("Details deleted from file.");
	fclose(fp);
	fclose(fp1);
	remove(from);
	rename("copy",from);
}
