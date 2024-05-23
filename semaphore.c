include<stdio.h>
char buf[20],p[20],cos[20];
int mutex,i,k,c,sz,n;
mutex=0;
void prosig()
{
mutex=mutex+1;
}
void consig()
{
mutex=mutex-1;
}
int buffer(int mutex)
{
if(mutex==0)
return 1;
else
return 0;
}
void producer(int sz)
{
int c;
c=buffer(mutex);
if(c==1)
{
printf("\nProducer can produce the item and give $ for exit\n");
i=0;
while(i<sz&&(p[i]=getchar())!='$')
{
buf[i]=p[i];
i++;
}
k=i;
prosig();
printf("\nProduction done successfully\n");
}
else if(k<sz)
{
printf("Producer can also produce items");
while((p[k]=getchar())!='$')
{
buf[k]=p[k];
k++;
}
prosig();
printf("\nProduction done successfully\n");
}
else if(k>=sz)
{
printf("\nBuffer is full,can't produce\n");
}
}
void consumer()
{
int c1;
c1=buffer(mutex);
if(c1==0)
{
printf("\nConsumer can consume item\n");
for(i=0;i<k;i++)
cos[i]=buf[i];
printf("\nConsumed item is:\n");
for(i=0;i<k;i++)
printf("\n%c",cos[i]);
consig();
printf("\nSuccessfully done\n");
}
else
{
printf("\nBuffer is empty,can't consume\n");
}
}
int main()
{
intop,sz;
printf("Enter the buffer size");
scanf("%d",&sz);
do
{
printf("\n1.Producer\t2.Consumer\t3.Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&op);
switch(op)
{
case 1:
producer(sz);
break;
case 2:
consumer();
break;
case 3:
exit(0);
}
}
while(op<=2);
return 0;
}
