#include<stdio.h>
struct process
{
    int pid,at,bt,ct,tat,wt;
    int cbt;
};
struct gangchart
{
    int pid,ct;
};
float avgtat,avgwt;

void gangchart(struct gangchart gg[],int max)
{
    

    int i,j,k;
    for(i=0;i<max;i++)
    printf("+------");
    printf("+\n");

    for(i=0;i<max;i++)
    printf("|  %d  ",gg[i].pid);
    printf("|\n");

    for(i=0;i<max;i++)
    printf("+------");
    printf("+\n");

    for(i=0;i<max;i++)
    printf("    %d",gg[i].ct);
    
    


}

void rr(struct process p[],int qt,int n)
{
    struct gangchart gg[40];
    int i,max=0,done,x=0;
    int count=0;
    while(count<n)
    {
        
        for(i=0;i<n;i++)
        {
            if(p[i].bt>qt)
            {
                
                p[i].bt-=qt;
                x+=qt;
                gg[max].pid=p[i].pid;
                 gg[max].ct=x;
                max++;
            }
            else
            {
                if(p[i].bt!=0)
                {
                   count++;
                    x+=p[i].bt;
                        gg[max].pid=p[i].pid;
                        gg[max].ct=x;
                        max++;
                        p[i].ct=x;
                        p[i].tat=x-p[i].at;
                        p[i].wt=p[i].tat-p[i].cbt;
                        avgtat+=p[i].tat;
                        avgwt+=p[i].wt;
                    p[i].bt=0; 
                }
                
                    
                    
            }
        }
    }
    printf("average turndaround time=%f\naverage waiting time =%f\n",avgtat/n,avgwt/n);
    gangchart(gg,max);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
     {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].cbt, p[i].ct, p[i].tat, p[i].wt);
        }         
}


void main()
{
int i,j,k,n,qt;

printf("enter the number of processes\n");
scanf("%d",&n);
struct process p[n];
printf("enter arrival time and burst time for each process\n");
for(i=0;i<n;i++)
{
    scanf("%d%d",&p[i].at,&p[i].bt);
}
for(i=0;i<n;i++)
p[i].pid=i+1;
for(i=0;i<n;i++)
p[i].cbt=p[i].bt;

printf("enter the quantum time\n");
scanf("%d",&qt);
struct process temp;
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(p[j].at>p[j+1].at)
        {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
        }
    }
}

rr(p,qt,n);
}

/*
enter the number of processes
5
enter arrival time and burst time for each process
0
5
1
6
2
3
3
1
4
5
enter the quantum time
4
average turndaround time=13.800000
average waiting time =9.800000
+------+------+------+------+------+------+------+------+
|  1  |  2  |  3  |  4  |  5  |  1  |  2  |  5  |
+------+------+------+------+------+------+------+------+
    4    8    11    12    16    17    19    20
PID     AT      BT      CT      TAT     WT
P1      0       5       17      17      12
P2      1       6       19      18      12
P3      2       3       11      9       6
P4      3       1       12      9       8
P5      4       5       20      16      11
*/