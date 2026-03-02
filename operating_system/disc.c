#include<stdio.h>
#include<stdlib.h>
void fifo(int head,int req[],int max)
{
  int seektime=0,i;
  printf("%d",head);
  for(i=0;i<max;i++)
  {
    printf("->%d",req[i]);
    seektime+=abs(req[i]-head);
    head=req[i];
  }
  printf("end\n");
  printf("seektime= %d\n",seektime);
}

void cscan(int head,int req[],int max,int mem)
{
  int i,k=-1,j,seektime,head2=head,pos;
  mem=mem-1;
  for(i=0;req[i]<head;i++)
  {
    k++;
  }
  pos=k;
  printf("enter 1 for left and 2 for right");
  scanf("%d",&k);
  if(k==2)
  {
    seektime=0;
    printf("right\n");
    printf("%d",head);
    for(i=pos+1;i<max;i++)
    {
      printf("->%d",req[i]);
      seektime+=abs(req[i]-head);
      head=req[i];
    }
    printf("->%d",mem);
    seektime+=abs(mem-req[max-1]) + (mem-0);
    printf("->0");
    head=0;
    for(i=0;i<=pos;i++)
    {
      printf("->%d",req[i]);
      seektime+=abs(req[i]-head);
      head=req[i];
    }
    printf(" \nseek time is %d\n",seektime);
  }
  else
  {
    seektime=0;
    printf("left\n");
    printf("%d",head2); 

    
    for(i=pos;i>=0;i--)
    {
        printf("->%d",req[i]);
        seektime+=abs(head2-req[i]);
        head2=req[i];
    }
    printf("->0");
    printf("->%d",mem);
    seektime+=abs(0-req[0])+(mem-0);
    head2=mem;
    for(i=max-1;i>pos;i--)
    {
      printf("->%d",req[i]);
      seektime+=abs(head2-req[i]);
      head2=req[i];
    }
    printf("\n seek time is %d\n",seektime);
  }
  
}

void sscan(int head,int req[],int max,int mem)
{
  int i,j,k,seektime=0 ,c,head2=head,pos;
  k=-1;
  mem=mem-1;
  for(i=0;req[i]<head;i++)
  {
    k++;
  }
    pos=k;
    printf("1 for left 2 for right\n");
    scanf("%d",&k);
    if(k==2)
    {
        seektime=0;
        printf("%d",head);
        for(i=pos+1;i<max;i++)
        {
          printf("->%d",req[i]);
          seektime+=abs(head-req[i]);
          head=req[i];
        }
        seektime+=abs(req[max-1]-mem);
        printf("->%d",mem);
        head=mem;
        for(i=pos;i>=0;i--)
        {
          printf("->%d",req[i]);
          seektime+=abs(head-req[i]);
          head=req[i]; 
        }
        printf("\n seek time is %d\n",seektime);
    }
    else 
    {
      seektime=0;
        printf("%d",head);
        for(i=pos;i>=0;i--)
        {
          printf("->%d",req[i]);
          seektime+=abs(head-req[i]);
          head=req[i]; 
        }
        seektime+=abs(req[0]-0);
        printf("->0");
        head=0;
        for(i=pos+1;i<max;i++)
        {
          printf("->%d",req[i]);
          seektime+=abs(head-req[i]);
          head=req[i];
        }
        printf("\n seek time is %d\n",seektime);
    }

  }

void main()
{
  int max,head,i,j,mem;
  printf("enter the max size of memory\n");
  scanf("%d",&mem);
  printf("enter the number of requests\n");
  scanf("%d",&max);
  int req[max];
  printf("enter the requests queue\n");
  for(i=0;i<max;i++)
  scanf("%d",&req[i]);
printf("enter the head\n");
scanf("%d",&head);
//fifo
printf("fifo\n");
fifo(head, req, max);
//sort
int temp;
for(i=0;i<max-1;i++)
{
  for(j=0;j<max-i-1;j++)
  {
    if(req[j+1]<req[j])
    {
        temp=req[j+1];
        req[j+1]=req[j];
        req[j]=temp;
    }
  }
}
//cscan
printf("cscan\n");
cscan(head, req, max,mem);
printf("cscan\n");
cscan(head, req, max,mem);
//sscan
printf("sscan\n");
sscan(head, req, max,mem);
printf("sscan\n");
sscan(head, req, max,mem);
}