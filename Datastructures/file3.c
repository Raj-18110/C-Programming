#include<stdio.h>
int main( int argc, char *argv[] )
{
	FILE *f1,*f2;
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"w");
	int k;
	k=atoi(argv[3]);
	char r;
	while(k>0 && (r=fgetc(f1))!=EOF)
	{
		fprintf(f2,"%c",r);
		if(r=='\n')
 		--k;
	}
	return 0;
}

