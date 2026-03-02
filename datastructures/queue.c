
#include <stdio.h>
int rear=-1,front=-1,a[10],maxsize=10;
void enqueue(int x)
{
    if(rear==maxsize-1)
    {
        printf("full");
    }
    if(rear==-1)
    {
        rear=0;
        front=0;
        a[rear]=x;
    }
    else
    {
        rear=rear+1;
        a[rear]=x;
    }
}
int dequeue()
{
    if(front==-1)
    {
    printf("empty");
    return -1;
    }
    else 
    { int x=a[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        front=front+1;
        return x;
    }
    
}
void display()
{
     if(front==-1)
    {
    printf("empty");
    
    }
    else
    {
    for(int i=front;i<=rear;i++)
    printf("%d\t",a[i]);
printf("\n");
    }
    
}
void main()
{
    int n,item;
do
    {
        printf("enter your choice\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
                    printf("enter the item\n");
                    scanf("%d",&item);
                     enqueue(item);
                     break;
            case 2: item=dequeue();
                          if(item!=-1)
                         printf("the dequeued element is %d\n",item);
                          break;
            case 3: display();
                         break;
            case 4: printf("exit");
                    break;
            default:printf("invalid input");
        }
        
        
    }while(n!=4);
    
}