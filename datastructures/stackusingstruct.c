//stack using structures2
#include <stdio.h>
#define maxsize 100
struct lifo
{
    int a[maxsize];
    int top;
};
typedef struct lifo stack;

int create(stack *s)
{
   return s->top=-1;
    
}
 int isfull(stack *s)
{
    if(s->top==maxsize-1)
    return 1;
    else 
    return 0;
}

int isempty(int top)
{
    if(top==-1)
    return 1;
    else return 0;
    
}

void push(stack *s,int item)
{
    if(isfull(s))
    printf("stack full\n");
    else
    {
        s->top=s->top+1;
        s->a[s->top]=item;
    }
    
}

int pop(stack *s)
{
    if(isempty(s->top))
    {
printf("empty\n");
return -1;
        
    }
else 
{
    int item=s->a[s->top];
     s->top--;
     return item;
}   
}

void display(stack *s)
{
    if(isempty(s->top))
printf("empty\n");
else 
for(int i=0;i<=s->top;i++)
printf("%d\n",s->a[i]);
}

void main()
{
    stack b;
    int n,item,top=create(&b);
do
    {
        printf("enter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
                    printf("enter the item\n");
                    scanf("%d",&item);
                     push  (&b,item);
                     break;
            case 2: item=pop(&b);
                          if(item!=-1)
                         printf("the popped element is %d\n",item);
                          break;
            case 3: display(&b);
                         break;
            case 4: printf("exit");
                    break;
            default:printf("invalid input");
        }
        
        
    }while(n!=4);
    
}   
