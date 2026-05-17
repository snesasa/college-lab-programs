#include<stdio.h>

int main()
{
    int n,r,i,j;

      
        printf("enter the number process\n");
        scanf("%d",&n);
      printf("enter the number of resources\n");
      scanf("%d",&r);

      int pid[n];
      int alloc[n][r],max[n][r],need[n][r],avail[n][r];
      int tot[r];
        //alloc matrix
      for(i=0;i<n;i++)
      {
        printf("printf details of  alloc for process %d\n",i);
        for(j=0;j<r;j++)
        {
          scanf("%d",&alloc[i][j]);
        }
      }
      //max matrix
      for(i=0;i<n;i++)
      {
        printf("printf details of  max for process %d\n",i);
        for(j=0;j<r;j++)
        {
          scanf("%d",&max[i][j]);
        }
      }
    //tot matrix
    printf("printf details of  total resources\n" );
    for(j=0;j<r;j++)
    {
      scanf("%d",&tot[j]);
    }
    //need matrix

    for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
        need[i][j]=max[i][j]-alloc[i][j];
        }
      }
      printf("need matrix\n");
      for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
          printf("%d ",need[i][j]);
        }
        printf("\n");
      }
      //find the available matrix first row
      int sum[r];
      for(i=0;i<r;i++)
      sum[i]=0;
      for(j=0;j<r;j++)
      {
        for(i=0;i<n;i++)
        {
        sum[j]+=alloc[i][j];
        }
        avail[0][j]=tot[j]-sum[j];
      }
    //transfering to work
    int work[r];
    for(j=0;j<r;j++)
    {
      work[j]=avail[0][j];
    }
      //bankers
      int safesequence[n];
      
      int visited[n];
      for(i=0;i<n;i++)
      visited[i]=0;
    int count=0,found;
    while(count<n)
    {
     found=0;
      for(i=0;i<n;i++)
      {
            if(visited[i]==0)
            {
                int canallocate=1;
                for(j=0;j<r;j++)
                {
                      if(need[i][j]>work[j])
                      {
                          canallocate=0;
                          break;
                      }
                  
                }
                if(canallocate==1)
                {
                  safesequence[count]=i;
                  visited[i]=1;
                  for(int k=0;k<r;k++)
                  {
                    work[k]=avail[count][k];
                  }
                  count++;
                      for(int k=0;k<r;k++)
                      {
                        
                        avail[count][k]=work[k]+alloc[i][k];
                        
                        
                      }
                      
                        found=1;
                       
                      
                }
          }
      }
    }
if(!found)
printf("safe sequence doesnt exist\n");
else 
{
  printf("safe sequence is P%d",safesequence[0]);
  for(i=1;i<n;i++)
printf("->P%d",safesequence[i]);
printf("\n");
}

//print
printf("allocation matrix\n");
for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
          printf("%d ",alloc[i][j]);
        }
        printf("\n");
      }
      printf("maximum matrix\n");
      for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
          printf("%d ",max[i][j]);
        }
        printf("\n");
      }

      printf("need matrix\n");
      for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
          printf("%d ",need[i][j]);
        }
        printf("\n");
      }
      printf("available matrix\n");
      for(i=0;i<n;i++)
      {
        
        for(j=0;j<r;j++)
        {
          printf("%d ",avail[i][j]);
        }
        printf("\n");
      }

      return 0;
}