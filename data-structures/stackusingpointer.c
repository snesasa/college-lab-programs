// stack using pointer without structures
#include <stdio.h>
#define maxsize 100
int isfull(int* top)
{
    if(*top==maxsize-1)
    return 1;
    else  return 0;
}
int isempty(int* top)
    {
        if(*top==-1)
        return 1;
        else 
        return 0;
    }
void push(int s[],int *t,int item)
{
    if(isfull(t))
    printf("full");
    else 
    {
        *t=*t+1;
         s[*t]=item;
    }
}    
    
    int pop(int s[],int *t)
    {
        if(isempty(t))
       { printf("empty\n");
        return -1;
       }
        else
        {
            int e=s[*t];
            (*t)--;
            return e;
        }
    }
    void display(int st[],int *top)
    {
         if(isempty(top))
        {
        printf("empty\n");
        
        }
        else
       {  
           printf("the elements are\n");
           for(int i=0; i<=*top;i++)
        printf("%d\n",st[i]);
       }
    }

void main() 
{
    int s[maxsize],top=-1,n,item;
    do
    {
        printf("enter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
                    printf("enter the item\n");
                    scanf("%d",&item);
                     push  (s,&top,item);
                     break;
            case 2: item=pop(s,&top);
                          if(item!=-1)
                         printf("the popped element is %d\n",item);
                          break;
            case 3: display(s,&top);
                         break;
            case 4: printf("exit");
                    break;
            default:printf("invalid input");
        }
        
        
    }while(n!=4);
}
