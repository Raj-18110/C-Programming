#include<stdio.h>
#include<string.h>
FILE *out;
int checkNumber(int num){
    char line[512];
   int number;  
    int result=0; 

    if((out = fopen("file.dat","r"))==NULL){
            result= 1;
    }

    char buf[10];
	atoi(num, buf, 10);


    while(fgets(line, 512, out) != NULL)
    {
       if((strstr(line,buf)) != NULL){
              result = 0;
       }
    }
    if(out) {
        fclose(out);
    } 
    return result;  
}

void main()
{
	FILE *fptr;
	fptr=fopen("file.dat","w");
	fprintf(fptr,"Sl. No.\t\tRoll No.\t\tName\t\tsub1\t\tsub2\t\tsub3\t\tsub4\t\tsub5\t\tAverage\n");
	printf("\nEnter 5 values :\n");
	int i,s1,s2,s3,s4,s5,roll;
	char name[20];
	float avg=0.0;
	for(i=0;i<2;i++)
	{
		printf("\nEnter Roll No. : ");
		scanf("%d",&roll);
		printf("\nEnter Name : ");
		getchar();
		gets(name);
		printf("\nEnter Subject 1 marks : ");
		scanf("%d",&s1);
		printf("\nEnter Subject 2 marks : ");
		scanf("%d",&s2);
		printf("\nEnter Subject 3 marks : ");
		scanf("%d",&s3);
		printf("\nEnter Subject 4 marks : ");
		scanf("%d",&s4);
		printf("\nEnter Subject 5 marks : ");
		scanf("%d",&s5);
		avg=(s1+s2+s3+s4+s5)/5;
		fprintf(fptr,"%-10d \t %-10d \t %-10s \t %-10d \t %-10d \t %-10d \t %-10d \t %-10d \t %-10f    \n",i+1,roll,name,s1,s2,s3,s4,s5,avg);
	}
	system("clear");
	fclose(fptr);
	FILE *fpt,*fp;
	int j=0,z=0,k1=0;
	char c=' ';
	fpt=fopen("file.dat","r");
	do
	{
		c=fgetc(fpt);
		printf("%c",c);
	}
	while(c!=EOF);
	fclose(fpt);
	fp=fopen("file.dat","r");
	printf("\nEnter roll no. to search : ");
	scanf("%d",&k1);
	do
	{
		c=fgetc(fpt);
	}
	while(c!='\n');
	while(j<2)
	{
		fscanf(fp,"%d %d %s %d %d %d %d %d %f ",&z,&roll,name,&s1,&s2,&s3,&s4,&s5,&avg);
		if(roll==k1)
		printf("%d %d %s %d %d %d %d %d %f ",z,roll,name,s1,s2,s3,s4,s5,avg);j++;
	}		
	int o=checkNumber(k1);
	if(o==0)
	printf("\nNumber found");	
	fclose(fp);
}
