#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* root=NULL;

struct node* getnode()
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    return NULL;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}
void search(int d)
{
   int flag=0;
   struct node *ptr=root;
    while(ptr!=NULL&&flag==0)
    {
        if(d<ptr->data)
        {
          
          ptr=ptr->left;
        }
        if(d>ptr->data)
        {
         
          ptr=ptr->right;
        }
        else
        {
          flag=1;
          printf("element  found");
        }
    } 
}
void insert(int d)
{
  struct node *ptr=root,*parent=NULL,*new;
  if(root==NULL)
  {
    new=getnode();
    if(new==NULL)
    {
      printf("memory allocation faied");
      return;
    }
    new->data=d;
    root=new;
    ptr=new;
    return;
  }
 else 
  {
    int flag=0;
    
    while(ptr!=NULL&&flag==0)
    {
        if(d<ptr->data)
        {
          parent=ptr;
          ptr=ptr->left;
        }
        if(d>ptr->data)
        {
          parent=ptr;
          ptr=ptr->right;
        }
        else
        {
          flag=1;
          printf("element already exists");
          return;
        }
      
    }
    if(ptr==NULL)
    {
      new=getnode();
      new->data=d;
      if(parent->data>d)
      {
        parent->left=new;
      }
      else
      parent->right=new;
    }
  }
}
void displaypreorder(struct node* root)
{
  if(root)
  {
    printf("%d ",root->data);
    displaypreorder(root->left);
    displaypreorder(root->right);
  }
}
struct node* succ(struct node* ptr)
{
  struct node* ptr1=ptr->right;
  while(ptr1->left!=NULL)
  {
    ptr1=ptr1->left;
  }
  return ptr1;
}
struct node* delete(int d)
{
  int flag=0,item;
  struct node *ptr=root,*parent,*ptr1;
    while(ptr!=NULL&&flag==0)
    {
        if(d<ptr->data)
        {
          parent=ptr;
          ptr=ptr->left;
        }
        if(d>ptr->data)
        {
          parent=ptr;
          ptr=ptr->right;
        }
        else
        {
          flag=1;
          
        }
      
    }
    if(flag==0)
    {
      printf("item not found");
    }
    else 
    {
      int casee;
      if(ptr->left==NULL&&ptr->right==NULL)
      casee= 1;
    else if(ptr->left!=NULL&&ptr->right!=NULL)
    casee= 3;
      else 
      casee =2;
    switch(casee)
    {
      case 1: if(parent->left==ptr)
                parent->left=NULL;
              
                else
                parent->right=NULL;
              free(ptr);
              break;
      case 2: if(ptr->left==NULL)
              {
                if(parent->right==ptr)
                {
                  parent->right=ptr->right;
                }
                else 
                parent->left=ptr->right;
              }
              else
              {
                if(parent->right==ptr)
                {
                  parent->right=ptr->left;
                }
                else 
                parent->left=ptr->left;
              }
              free(ptr);
              break;
      case 3: ptr1=succ(ptr);
              item=ptr1->data;
              root=delete(item);
              ptr->data=item;
              break;

    }

    }
return root;

}

void main()
{
  
  int c,d;
  do
  {
     printf("enter the options \n1.insert\n2.delete\n3.search\n4.display\n5.exit\n");
     scanf("%d",&c);
     switch(c)
      {
        case 1:printf("enter the element\n");
              scanf("%d",&d);
              insert(d);
              break;
        case 2:printf("enter the element\n");
              scanf("%d",&d);
              delete(d);
              break;
       case 3:printf("enter the element\n");
              scanf("%d",&d);
              search(d);
              break;
        case 4:displaypreorder(root);
              printf("\n");
                break;
        case 5:exit(0);

      }
  }while(c!=5);

}