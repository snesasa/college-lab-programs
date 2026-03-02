#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left,*right;

};
struct node* root=NULL;
struct node *q[20];
int front=-1,rear=-1;
void enqueue(struct node *ptr)
{
  if(rear==19)
  {
    printf("full");
  }
  else 
  {
    if(rear==-1)
    {
      rear=0;
      front=0;
    }
    else 
    rear=rear+1;
  q[rear]=ptr;
  }
}
struct node* dequeue()
{
  if(front==-1)
  {
    printf("empty");
    return NULL;
  }
  else 
  {
    struct node *ptr=q[front];
    if(front==rear)
    {
      front=-1;
       rear=-1;
    }
    else 
    front=front +1;
  return ptr;
  }

}

struct node* getnode(int d)
{
  struct node *n=(struct node*)malloc(sizeof(struct node));
  n->data=d;
  n->left=NULL;
  n->right=NULL;
  return n;
}
void insert(int data)
{
  struct node* n=getnode(data);
  struct node *current;
  if(root==NULL)
  {
    root=n;
    
  }
  else 
  {
    enqueue(root);
    while(1)
    {
      current=dequeue();
      if(current->left!=NULL&&current->right!=NULL)
      {
        enqueue(current->left);
        enqueue(current->right);
      }
      else if(current->left==NULL)
      {
        current->left=n;
        break;
      }
      else if(current->right==NULL)
      {
        current->right=n;
        break;
      }
      
    }
  }
}
void preorder(struct node* root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void inorder(struct node* root)
{
  if(root)
  {
    inorder(root->left);
     printf("%d ",root->data);
    inorder(root->right);
  }
}
void postorder(struct node* root )
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

void main()
{
  int c;

  int item;
  do
  {
    printf("enter the option \n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.exit\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:printf("enter the data\n");
              scanf("%d",&item);
              insert(item);
              break;
      case 2:preorder(root);
              break;
      case 3:postorder(root);
            break; 
      case 4:inorder(root);
            break;    
       case 5:exit(0);                    
    }
  }while(c!=5);
}