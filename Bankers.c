#include<stdio.h>
#include<stdlib.h>
int allocation[20][20],max[20][20],available[20],need[20][20],safe[10],s=0;
int finish[10],work[10],cnt=0,flag=0,temp=0;
int p,r,i,j,ch,index,req[10];
void check()
{
temp=0;
s=0;
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-allocation[i][j];
printf("\nallocation table is:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d\t",allocation[i][j]);
printf("\n");
}
printf("\n Need table is:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d\t",need[i][j]);
printf("\n");
}
for(i=0;i<p;i++)
finish[i]=0;//false
for(i=0;i<r;i++)
work[i]=available[i];
while(temp<2)
{
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
if(finish[i]==0 && need[i][j]<=work[j])
flag=1;
else
{
flag=0;
break;
}
}
if(flag==1)
{
for(j=0;j<r;j++)
work[j]=work[j]+allocation[i][j];
finish[i]=1;
safe[s++]=i;
}
}
temp++;
}
flag=0;
for(i=0;i<p;i++)
{
if(finish[i]==0)
{
flag=1;
break;
}
}
if(flag==1)
{
printf("\nsystem is in deadlock state");
}
else
{
printf("\nsystem is in safe state");
printf("\nsafe sequance is:");
for(i=0;i<p;i++)
printf("p%d\t",safe[i]);
}
}
int main()
{
system("clear");
printf("\n__________________BANKER'S ALGORITHM_______");
printf("\n\nenter the no of resources and processes:");
scanf("%d%d",&r,&p);
printf("\nenter the allocation table:\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&allocation[i][j]);
printf("\nenter the max table:\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
printf("\nenter the vector available:");
for(i=0;i<r;i++)
scanf("%d",&available[i]);
check();
printf("\nDo u want to add new request:(0/1)");
scanf("%d",&ch);
if (ch==0)
exit(1);
printf("\nenter the process no:");
scanf("%d",&index);
printf("\nenter the request:");
for(i=0;i<r;i++)
scanf("%d",&req[i]);
flag=0;
for(i=0;i<r;i++)
if(req[i]<=need [index][i])
flag=1;
else
flag=0;
if(flag==0)
{
printf("\n request can not be satisfied.....");
exit(1);
}
for(i=0;i<r;i++)
if(req[i]<=available[i])
flag=1;
else
flag=0;
if(flag==0)
{
printf("\n request can not be satisfied.....");
exit(1);
}
for(i=0;i<r;i++)
{
allocation[index][i]=allocation[index][i]+req[i];
available[i]=available[i]-req[i];
}
check();
return 0;
}
