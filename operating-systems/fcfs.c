#include<stdio.h>

struct process
{
  int pid;
  int arrt;
  int bt;
  int ct;
  int tat;
  int wt;
  
};
void findcompletiontime(struct process p[],int n)
{
  
  int i=0,t=0,j=0;
  p[0].ct=p[0].arrt+p[0].bt;
  p[0].tat=p[0].ct-p[0].arrt;
  p[0].wt=p[0].tat-p[0].bt;
  float tottat=p[0].tat,totwt=p[0].wt;
  for( i=1;i<n;i++)
  {
    //idle condition
    if(p[i].arrt>p[i-1].ct)
    p[i].ct=p[i].arrt+p[i].bt;
  else
     p[i].ct=p[i-1].ct+p[i].bt;
    //turn around time and waiting time
     p[i].tat=p[i].ct-p[i].arrt;
     p[i].wt=p[i].tat-p[i].bt;
    tottat+=p[i].tat;
    totwt+=p[i].wt;
  }
  printf("average turn around time = %f\n",tottat/n);
printf("average waiting time = %f\n",totwt/n);
}
void printgangchart(struct process p[],int n)
{
  int i=0;
  
  for(i=0;i<n;i++)
  printf("+------");
 printf("+\n");
 
 if(p[0].arrt>0)
 printf("|  idle  |");
 for(i=0;i<n;i++)
 printf ("|  P%d  ",p[i].pid);
printf("|\n");

for(i=0;i<n;i++)
printf("+------");
printf("+\n");


}

int main()
{
  int n,i,j;
  printf("enter the number of process\n");
  scanf("%d",&n);
  struct process p[n];
  for(i=0;i<n;i++)
  {
    printf("enter the process id,arrival time and burst time of %d\n",i);
    scanf("%d",&p[i].pid);
    scanf("%d",&p[i].arrt);
    scanf("%d",&p[i].bt);
  }
  //sorting
  for(int i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(p[j].arrt>p[j+1].arrt)
      {
        struct process temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
  findcompletiontime(p,n);
  printgangchart(p,n);
}