// dqcircular queue
#include <stdio.h>
int rear=-1,front=-1,a[5],maxsize=5;
void enqueuer(int x)
{
    if(front==(rear+1)%maxsize)
    {
        printf("full\n");
    }
   else if(rear==-1)
    {
        rear=0;
        front=0;
        a[rear]=x;
    }
    else
    {
        rear=(rear+1)%maxsize;
        a[rear]=x;
    }
}
int enqueuef(int x)
{
    if((rear+1)%maxsize==front)
    {
        printf("empty");
        return -1;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        a[front]=x;
    }
    else
   {
       front=(front-1+maxsize)%maxsize;
       a[front]=x;
   }
}
int dequeuer()
{
    if(front==-1)
    {
        printf("empty");
        return -1;
    }
    else 
    {  int x=a[rear];
        if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else rear=(rear-1+maxsize)%maxsize;
    return x;
    }
    
}
int dequeuef()
{
    if(front==-1)
    {
    printf("empty\n");
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
        front=(front+1)%maxsize;//condition is updated if it is true first
        return x;
    }
    
}
void display()
{
     if(front==-1)
    {
    printf("empty\n");
    
    }
    else {
       
        if(front>rear)
      {
           for(int i=front;i<maxsize;i++)
    printf("%d\t",a[i]);
    
       for(int i=0;i<=rear;i++)
     printf("%d\t",a[i]);
     printf("\n");
     }
 else
        {
    for(int i=front;i<=rear;i++)
    printf("%d\t",a[i]);
    printf("\n");
        }
    }
    
}
void main()
{
    int n,item;
do
    {
        printf("enter your choice\n1.enqueuefront\n2.dequeuefront\n3.enqueuerear\n4.dequeuerear\n5.display\n6.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
                    printf("enter the item\n");
                    scanf("%d",&item);
                     enqueuef(item);
                     break;
            case 2: item=dequeuef();
                          if(item!=-1)
                         printf("the dequeued element is %d\n",item);
                          break;
             case 3: 
                    printf("enter the item\n");
                    scanf("%d",&item);
                     enqueuer(item);
                     break;
            case 4: item=dequeuer();
                          if(item!=-1)
                         printf("the dequeued element is %d\n",item);
                          break;              
            case 5: display();
                         break;
            case 6: printf("exit");
                    break;
            default:printf("invalid input");
        }

    }while(n!=6);
    
}