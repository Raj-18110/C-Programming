#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
struct timeval startread,startcalc,finish,readtime,calctime,overalltime;
int n,a[100],value;int thread_count,count;
pthread_mutex_t mutex;

void *t1(void *x)
{
   // printf("Reached in thread");
    int i=(int)x;
    int k;
if(i==thread_count-1)
{
for(k=(i)*(n);k<count;k++){
if(a[k]==3)
        {
            pthread_mutex_lock (&mutex);
//printf("Reached");
            value++;
            pthread_mutex_unlock (&mutex);
        
        }

}}
						else
						{
						    for(k=(i)*(n);k<(i+1)*(n);k++)
						    {
							if(a[k]==3)
							{
							    pthread_mutex_lock (&mutex);
							    value++;
							    pthread_mutex_unlock (&mutex);
		
							}
						    }
						}
}

void main(int argc ,char *argv[] )
{
FILE *fp,*fp1;



   
    if(argc!=2){
    printf("Arguments not sufficient\n");
    exit(0);
    }


thread_count=*argv[1]-48;

pthread_t p[thread_count];

						fp=fopen("/home/sunny/number.txt","r");
						int c;char d;int i=0;

						if(fp==NULL)
						{

						printf("File empty");
						}


						while(fscanf(fp,"%c",&d)!=EOF)
						{
						if(d=='\n')
						count++;
						}

						fclose(fp);



									fp1=fopen("/home/sunny/number.txt","r");
									if(fp1==NULL)
									{

									printf("File empty");
									}
									gettimeofday(&startread,NULL);
									while(fscanf(fp1,"%d",&c)!=EOF)
									{
									a[i]=c;
									i++;
									}
									fclose(fp1);


gettimeofday(&startcalc,NULL);

n=count/(thread_count);
//printf("Value of n: %d,thread: %d\n",n,thread_count);
for(i=0;i<thread_count;i++)
{
//printf("Sending thread");
 pthread_create(&p[i],NULL,t1,(void *)i);
}

for(i=0;i<thread_count;i++)
{
//printf("Sending thread");
 pthread_join(p[i],NULL);
}
gettimeofday(&finish,NULL);
timersub(&startcalc,&startread,&readtime);
timersub(&finish,&startread,&overalltime);
timersub(&finish,&startcalc,&calctime);

printf("Reading time     : %ld.%03ld \n",readtime.tv_sec,readtime.tv_usec);
printf("calculation time : %ld.%03ld \n",calctime.tv_sec,calctime.tv_usec);
printf("Overall time     : %ld.%03ld \n",overalltime.tv_sec,overalltime.tv_usec);

printf("Count:%d ",count);

/*for(i=0;i<count;i++)
printf("%d ",a[i]);*/

printf("No.of 3's: %d\n",value);




}
