
#include <stdio.h>
int s[20];
int item,top=-1,maxsize=20;
int isempty()
{
    if(top==-1)
    return 1;
    else return 0;
}
int isfull()
{
    if(top==maxsize-1)
    return 1;
    else return 0;
}
void push( int item)
{
    if(isfull())
    printf("stack overflow\n");
else 
   { 
       top=top+1;
    s[top]=item;
   }
}
int pop()
{
    if(isempty())
    printf("stack empty\n");
    else
   {
       item=s[top];
    top=top-1;
     return item;
   }
}
void display()
{
    if(isempty())
    printf("stack empty");
    else 
    { 
        printf("the elements are\n");
    for(int i=0; i<=top; i++)
   { printf("%d\n",s[i]);
    }
        
    }
}
void main()
{
    // Write C code here
    int n;
    do
    {
        printf("enter the choice\n1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d",&n);
        switch(n)
        {
            case 1: printf("enter the element\n");
                     scanf("%d",&item);
                     push(item);
                    break;
             case 2: int c=pop();
                     printf("the popped element is %d\n",c);
                        break;
             case 3: display();
                     break;
             case 4:
                  printf("exit");
                   break;
             deafult: printf("\ninvalid input");
             
        }
    } 
    while(n!=4);
    
}