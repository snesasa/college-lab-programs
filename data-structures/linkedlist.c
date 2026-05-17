//linked list insert delete count display
#include <stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};

struct node* insertfront(struct node *head,int d)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
     printf("insufficient memory\n");
    
    }
   
    else 
    {
        newnode->data=d;
        newnode->next=head;
        head=newnode;
    }
     return head;
}
struct node* insertbetween(struct node *head,int key,int d)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
     printf("insufficient memory\n");
    }
    else 
    {
        struct node* ptr=head;
        while(ptr->data!=key&&ptr->next!=NULL)
        ptr=ptr->next;
        if(ptr->data!=key)
        {
        printf("key not found\n");
        free(newnode);
        }
        else 
        {
            newnode->next=ptr->next;
             ptr->next=newnode;
            newnode->data=d;
        }
    }
     return head;
}

struct node* insertend(struct node *head,int d)
{
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   if(newnode==NULL)
   {
        printf("memory insufficient\n");
     
   }
   else 
   {
       if(head==NULL)
        {
         head=newnode;
         newnode->data=d;
         newnode->next=NULL;
       
         }
        else
        {
         struct node* ptr=head;
         while(ptr->next!=NULL)
             ptr=ptr->next;
         ptr->next=newnode;
        newnode->data=d;
         newnode->next=NULL;
        
        }
    } 
     return head;
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
       return 0;
   }   
}
int deletebetween(struct node **head,int key)
{
    if(*head==NULL)
    {
        printf("empty\n");
        return 0;
    }
    else 
    {
        struct node* ptr;
        struct node *ptr1=NULL;
        ptr=*head;
        if(ptr->data==key)
        {
            return deletefront(head);
        }
        while(ptr->data!=key&&ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr->data!=key)
        {
            printf("key not found\n");
            return 0;
            
        }
        else 
        {
            
            int trash=ptr->data;
             ptr1->next=ptr->next;
            free(ptr);
            return trash;
            
        }
    }
}

int deleteend(struct node **head)
{
    if(*head==NULL)
    {
        printf("empty\n");
        return 0;
    }
    else
    
    { 
        int trash;
        struct node *ptr=*head;
        if(ptr->next==NULL)
        {
           trash=ptr->data;
           *head=NULL;
           free(ptr);
           
         }
         else
        {
          struct node* ptr1=NULL;
          //struct node* ptr=*head;
            while(ptr->next!=NULL)
           {
               ptr1=ptr;
               ptr=ptr->next;
            }
         trash=ptr->data;
         ptr1->next=NULL;
         free(ptr);
        }
        return trash;
    }
}

int count(struct node* head)
{
    struct node* ptr=head;
  
        int c=0;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;
        }
        return c;
    
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
int main() {
    struct node* head=NULL;
    
    int t;
    struct node* s;
    int c;
    do
    {
    printf("enter your choice\n1.insert front\n2.insert between\n3.insert end\n4.delete front\n5.delete between\n6.delete end\n7.display\n8.exit\n9.count\n");
    scanf("%d",&c);
    
    switch(c)
    {
        case 1: 
                printf("enter the element\n");
                scanf("%d",&t);
                head=insertfront(head,t);
               break;
         case 2: int key;
                printf("enter the element\n");
                scanf("%d",&t);
                printf("enter the key\n");
                scanf("%d",&key);
                
                head=insertbetween(head,key,t);
               break;
         case 3:printf("enter the element\n");
                scanf("%d",&t);
                head=insertend(head,t);
                break;    
         case 4:t=deletefront(&head);
                if(t!=0)
                printf("the deleted element is %d\n",t);
               break;       
         case 5:printf("enter the key\n");
                scanf("%d",&key);
                t=deletebetween(&head,key);
                 if(t!=0)
                printf("the deleted element is %d\n",t);
               break;
         case 6:t=deleteend(&head);
                if(t!=0)
                printf("the deleted element is %d\n",t);
               break;       
         case 7: display(head);
               break;       
         case 8:printf("exit\n");
               break;  
        case 9: int c=count(head);
                printf("count is %d\n",c);
                break;
         default:
               break;       
    }
    
    }
    while(c!=0);
    return 0;
}
