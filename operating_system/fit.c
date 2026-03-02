#include<stdio.h>

void display(int allocation[],int p)
{
  int i=0,j;
  for(j=0;j<p;j++)
  {
      if(allocation[j]==0)
      printf("P%d:not allocated\n",j+1);
    else 
    {
      printf("P%d:allocated memory block%d\n",j+1,allocation[j]);
     
    }
  
  }
}
void firstfit(int memc[],int m,int pro[],int p)
{
  int i,j,flag=0,visited[m];
  for(j=0;j<m;j++)
  visited[j]=0;
int allocation[p];
for(j=0;j<p;j++)
allocation[j]=0;
  for(i=0;i<p;i++)
  {
    for(j=0;j<m;j++)
    {
        if(visited[j]==0&&pro[i]<=memc[j])
        {
          //assigning process to block
          allocation[i]=j+1;
          visited[j]=1;
          break;
        }

    }
  }
  display(allocation,p);
  
}
void bestfit(int memc[],int m,int pro[],int p)
{
  int i,j,flag=0,storeindex,min;
  
int allocation[p];
for(j=0;j<p;j++)
allocation[j]=0;
  for(i=0;i<p;i++)
  {
    min=10000;
    flag=0;
    for(j=0;j<m;j++)
    {
       if(pro[i]<=memc[j]&&memc[j]<=min)
       {
        flag=1;
        min=memc[j];
        storeindex=j;//for storing index for one that best suites
       } 

    }
    if(flag==1)
    {
        allocation[i]=storeindex+1;
        memc[storeindex]=memc[storeindex]-pro[i];//note
    }
    
  }
  display(allocation,p);
  
}

void worstfit(int memc[],int m,int pro[],int p)
{
  int i,j,flag=0,visited[m],max,storeindex;
  for(j=0;j<m;j++)
  visited[j]=0;
int allocation[p];
for(j=0;j<p;j++)
allocation[j]=0;
  for(i=0;i<p;i++)
  {
    max=0;
    for(j=0;j<m;j++)
    {
       if(visited[j]==0&pro[i]<=memc[j]&&memc[j]>=max)
       {
        max=memc[j];
        allocation[i]=j+1;
        flag=1;
        storeindex=j;
       } 
      
      
    }
    if(flag==1)
          {
          visited[storeindex]=1;
          }
  }
  display(allocation,p);
  
}



void main()
{
  int m,p,i,j,k;
  printf("enter the number of memory blocks\n");
  scanf("%d",&m);
  printf("enter the number of process\n");
  scanf("%d",&p);
  int mem[m],pro[p];
  //memoryblocks
  printf("enter the fixed size of memory blocks\n");
  for(i=0;i<m;i++)
  scanf("%d",&mem[i]);
  //process
  printf("enter the fixed size of process \n");
  for(i=0;i<p;i++)
  scanf("%d",&pro[i]);
  int x=0,c,memc[m];
    while(x==0)
    {
      printf("enter a choice\n1.first fit\n2.best fit\n3.worstfit\n4.exit\n");
      scanf("%d",&c);
      switch(c)
        {
          case 1:for(i=0;i<m;i++)
                  memc[i]=mem[i];
                  firstfit(memc,m,pro,p);
                  break;
          case 2:for(i=0;i<m;i++)
                  memc[i]=mem[i];
                  bestfit(memc,m,pro,p);
                  break; 
          case 3:for(i=0;i<m;i++)
                memc[i]=mem[i];
                worstfit(memc,m,pro,p);
                    break;
          case 4:x=1;
                  break;       
        }

    }
}
/*
enter the number of memory blocks
6
enter the number of process
4
enter the fixed size of memory blocks
200 400 600 500 300 250
enter the fixed size of process 
357
210
468
491
enter a choice
1.first fit
2.best fit
3.worstfit
4.exit
1
P1:allocated memory block2
P2:allocated memory block3
P3:allocated memory block4
P4:not allocated
enter a choice
1.first fit
2.best fit
3.worstfit
4.exit
2
P1:allocated memory block2
P2:allocated memory block6
P3:allocated memory block4
P4:allocated memory block3
enter a choice
1.first fit
2.best fit
3.worstfit
4.exit
3
P1:allocated memory block3
P2:allocated memory block4
P3:not allocated
P4:not allocated
enter a choice
1.first fit
2.best fit
3.worstfit
4.exit
4

*/