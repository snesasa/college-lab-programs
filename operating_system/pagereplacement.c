#include<stdio.h>
int inframe(int page,int frames[],int f)
{
  int i;
  for(i=0;i<f;i++)
  {
    if(page==frames[i])
    {
      return i;
     
    }
  }
  return -1;
}
void fifo(int pages[],int p,int frames[],int f)
{
    int i,j,faults=0,index=0,hit=0,page;
    for(i=0;i<p;i++)
    {
          page=pages[i];
        if(inframe(page,frames,f)==-1)
        {
            faults++;
            frames[index]=page;
            index=(index+1)%f;
            for(j=0;j<f;j++)
            {
               printf("%d ",frames[j]);
            }
            printf(":fault\n");
            
        }
        else
            {
              hit++;
              for(j=0;j<f;j++)
            {
               printf("%d ",frames[j]);
            }
            printf(":hit\n");

            }
            
    }
            printf("number of hit %d\n",hit);
            printf("number of fault %d\n",faults);
}

void lru(int pages[],int p,int frames[],int f)
{
  int i,j,page,pageindex,hit=0,fault=0,used[f],time=0,replaceindex;
  printf("lru page replacement\n");
  for (i = 0; i < f; i++)
        used[i] = -1;
  for(i=0;i<p;i++)
  {
          page=pages[i];
          
          pageindex=inframe(page,frames,f);
          if(pageindex==-1)
          {
              fault++;
              replaceindex=0;
              for(j=1;j<f;j++)
              {
                
                  
                    if(used[j]<used[replaceindex])
                    {
                        replaceindex=j;
                      
                    }
                    
                    
              }
              used[replaceindex]=time;
                    frames[replaceindex]=pages[i];
                    for(j=0;j<f;j++)
                    {
                        printf("%d ",frames[j]);
                    }
                    printf(":fault\n");

          }
          
          else
          {
            used[pageindex]=time;
            hit++;
            for(j=0;j<f;j++)
                  {
                    printf("%d ",frames[j]);
                  }
                  printf(":hit\n");

          }
          time++;
    }
    

    printf("number of hit %d\n",hit);
            printf("number of fault %d\n",fault);
  }

  void lfu(int pages[],int p,int frame[],int f)
  {
    int i,j,k,used[f],page,flag,min,pageindex,hit=0,fault=0,replaceindex;
    for(i=0;i<f;i++)
      {
        used[i]=-1;

      }
      for(i=0;i<p;i++)
      {
        page=pages[i];
        flag=0;
        pageindex=inframe(page,frame,f);
        if(pageindex==-1)
        {
          fault++;
          replaceindex=0;
          for(j=0;j<f;j++)
          {
              if(frame[j]==-1)
                {
                      frame[j]=page;
                      used[j]=1;
                      flag=1;
                      break;
                }
                
          }
          if(flag!=1)
          {
            min=used[0];
            for(j=0;j<f;j++)
            {
              if(used[j]<min)
              {
                replaceindex=j;
                min=used[j];

              }

            }
            
            
          }
          used[replaceindex]=1;
            frame[replaceindex]=page;
            for(j=0;j<f;j++)
          {
            printf("%d ", frame[j]);
          }
          printf("fault\n");
          
        else
        {
          hit++;
          used[pageindex]++;
          for(j=0;j<f;j++)
          {
            printf("%d ", frame[j]);
          }
          printf("hit\n");
        }
        
        
      }
      printf("number of hit %d\n",hit);
      printf("number of fault %d\n",fault);
  }


void main()
{
  int p,f,i,j;
  printf("enter the number of pages\n");
  scanf("%d",&p);
  printf("enter the number of frames\n");
  scanf("%d",&f);
  int pages[p],frames[f];
  printf("enter the of pages\n");
  for(i=0;i<p;i++)
  scanf("%d",&pages[i]);

  printf("fifo\n");
  for(i=0;i<f;i++)
  frames[i]=-1;
  fifo(pages,p,frames,f);
  printf("lru\n");
  for(i=0;i<f;i++)
  frames[i]=-1;
  lru(pages,p,frames,f);
  printf("lfu\n");
  for(i=0;i<f;i++)
  frames[i]=-1;
  lfu(pages,p,frames,f);
}
/*
output
enter the number of pages
12
enter the number of frames
4
enter the of pages
1
2
3
4
5
1
3
1
6
3
2
3
fifo
1 -1 -1 -1 :fault
1 2 -1 -1 :fault
1 2 3 -1 :fault
1 2 3 4 :fault
5 2 3 4 :fault
5 1 3 4 :fault
5 1 3 4 :hit
5 1 3 4 :hit
5 1 6 4 :fault
5 1 6 3 :fault
2 1 6 3 :fault
2 1 6 3 :hit
number of hit 3
number of fault 9
lru
lru page replacement
1 -1 -1 -1 :fault
1 2 -1 -1 :fault
1 2 3 -1 :fault
1 2 3 4 :fault
5 2 3 4 :fault
5 1 3 4 :fault
5 1 3 4 :hit
5 1 3 4 :hit
5 1 3 6 :fault
5 1 3 6 :hit
2 1 3 6 :fault
2 1 3 6 :hit
number of hit 4
number of fault 8
lfu
1 -1 -1 -1 fault
2 2 -1 -1 fault
3 2 3 -1 fault
4 2 3 4 fault
5 2 3 4 fault
1 2 3 4 fault
1 2 3 4 hit
1 2 3 4 hit
1 6 3 4 fault
1 6 3 4 hit
1 2 3 4 fault
1 2 3 4 hit
number of hit 4
number of fault 8
*/