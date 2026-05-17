#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff,exp;
  struct node *next;
};
struct node *p1=NULL,*p2=NULL; 

struct node *getnode(int c,int e)
{
  struct node* n=(struct node*)malloc(sizeof(struct node));
  n->coeff=c;
  n->exp=e;
  n->next=NULL;
  return n;
}
struct node* insert(struct node* head)
{
  struct node *new,*temp=head;
  int no,c,e,i;
  printf("enter the number of terms\n");
  scanf("%d",&no);
  for(i=1;i<=no;i++)
  {
    printf("enter the coeffient and exponent\n");
    scanf("%d",&c);
    scanf("%d",&e);
    new=getnode(c,e);
    if(head==NULL)
    {
      head=new;
      temp=new;
    }
    else
    {
      temp->next=new;
      temp=new;
    }
  }
  return head;
}
struct node* add(struct node* p1,struct node* p2)
{
  struct node *t1=p1,*t2=p2,*p3=NULL,*temp=p3;

  while(t1!=NULL&&t2!=NULL)
  {
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(t1->exp==t2->exp)
    {
      new->exp=t1->exp;
      new->coeff=t2->coeff+t1->coeff;
      new->next=NULL;
      t1=t1->next;
      t2=t2->next;
    }
    else if(t1->exp>t2->exp)
    {
      new->exp=t1->exp;
      new->coeff=t1->coeff;
      new->next=NULL;
      t1=t1->next;
     
    }
    else 
    {
      new->exp=t2->exp;
      new->coeff=t2->coeff;
      new->next=NULL;
      t2=t2->next;
    }
  if(p3==NULL)
  {
    p3=new;
    temp=p3;

  }
  else 
  {
    temp->next=new;
    temp=new;
  }
  }
  while(t1!=NULL)
  {
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coeff=t1->coeff;
    new->exp=t1->exp;
    new->next=NULL;
      temp->next=new;
      temp=new;
      t1=t1->next;
  }
  while(t2!=NULL)
  {
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coeff=t2->coeff;
    new->exp=t2->exp;
    new->next=NULL;
      temp->next=new;
      temp=new;
      t2=t2->next;
  }
  return p3;
}

struct node* multi()
{
  struct node *t1=p1,*t2=p2,*temp,*temp1=NULL,*p3=NULL;
  int e,c;
  while(t1!=NULL)
  {
    t2=p2;
    while(t2!=NULL)
    {
      struct node* new=(struct node*)malloc(sizeof(struct node));
      new->next=NULL;
      new->exp=t1->exp+t2->exp;
      new->coeff=t1->coeff*t2->coeff;
      if(p3==NULL)
      {
        p3=new;
      }
      else
      {
        temp=p3;
        while(temp!=NULL&&temp->exp > new->exp)
        {
          temp1=temp;
          temp=temp->next;
        }
        if(temp!=NULL&&temp->exp==new->exp)
        {
          temp->coeff+=new->coeff;
          free(new);
        }
        
        else if(temp!=NULL&&temp->next==NULL)
        {
          temp->next=new;
        }
        
        else  
        {
          new->next=temp1->next;
          temp1->next=new;
        }

      }
      t2=t2->next;
    }
    t1=t1->next;
  }
  return p3;
}

void display(struct node *head)
{
  if(head==NULL)
  {
    printf("empty");
  }
  else
  {
    struct node* temp=head;
    while(temp!=NULL)
    {
      printf("(%d)x^%d",temp->coeff,temp->exp);
      if(temp->next!=NULL)
      printf(" + ");
    temp=temp->next;
    }
  }
}
void main()
{
  int c;
  struct node* p3=NULL,*p4=NULL;
  do
  {
    printf("enter the options \n1.1st polynomial\n2.2nd polynomial\n3.sum\n4.multiplication\n5.exit\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:p1=insert(p1);
              display(p1);
              break;
      case 2:p2=insert(p2);  
              display(p2);
              break;
      case 3:p3=add(p1,p2);  
            display(p3); 
            break; 
      case 4:p4=multi(p1,p2);  
            display(p4); 
            break;      
       case 5:exit(0);     

    }
  }while(c!=5);
}