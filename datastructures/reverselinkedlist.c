//reverse linked list1without pop
#include <stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};

struct node* insertfront(struct node **head,int d)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
     printf("insufficient memory\n");
    
    }
   
    else 
    {
        newnode->data=d;
        newnode->next=*head;
        *head=newnode;
    }
     return *head;
}

int deletefront(struct node **head)
{
   if(*head!=NULL)
   {
       struct node* ptr=*head;
       int trash=ptr->data;
        *head=ptr->next;
       free(ptr);
       return trash;
   }
   else
   {
       printf("empty\n");
       return -1;
   }   
}
void display(struct node *head)
{
    struct node* ptr=head;
    if(ptr==NULL)
    printf("empty\n");
    else 
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
void reverse(struct node *head)
{
     struct node* ptr=head;
    if(ptr==NULL)
    printf("empty\n");
    else 
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

int main()
{
     struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    int t;
    struct node* s;
    int c;
    do
    {
    printf("enter your choice\n1.push\n2.pop\n3.display\n4.reverse\n5.exit\n");
    scanf("%d",&c);
    
    switch(c)
    {
        case 1: 
                printf("enter the element\n");
                scanf("%d",&t);
                insertfront(&head,t);
               break;
         case 2: t=deletefront(&head);
                if(t!=-1)
                printf("the deleted element is %d\n",t);
               break;
         case 3:display(head);
                break;    
         case 4:reverse(head);
               break;   
         case 5:printf("exit");
               break;      
    }
    }while(c!=5);
    
    
    return 0;
}