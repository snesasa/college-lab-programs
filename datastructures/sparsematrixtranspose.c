// sparse matrix transpose
#include <stdio.h>
void main()
{
    int a[10][10],r,c,count=0,b[101][3],m=0;
    printf("enter the no of rows and columns\n");
    scanf("%d%d",&r,&c);
    printf("enter the numbers\n");
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
        
    }
    printf("the matrix is\n");
    for(int i=0;i<r;i++)
   { for(int j=0;j<c;j++)
    {
        printf("%d\t",a[i][j]);
        
    }printf("\n");
   }
     b[0][0]=r;
        b[0][1]=c;
       
        
    for(int i=0;i<r;i++)
     
    for(int j=0;j<c;j++)
    
        if(a[i][j]!=0)
        {
           
            count++;
                b[count][0]=i;
                b[count][1]=j;
                b[count][2]=a[i][j];
            
        }
        
     b[0][2]=count;
    printf("the sparse triplet representation is\n");
    for(int i=0;i<count;i++)
    {
    for(int j=0;j<3;j++)
    printf("%d\t",b[i][j]);
     printf("\n");
    }
    int t=0,q[10][10];
    q[0][0]=b[0][1];
    q[0][1]=b[0][0];
    q[0][2]=b[0][2];
    for(int i=0;i<c ;i++)
    for(int j=1;j<count;j++)
    {
     if(b[j][1]==i)
     
    { t++;
       
        q[t][0]=b[j][1];
        q[t][1]=b[j][0];
        q[t][2]=b[j][2];
       
       }
    }
    
    printf("the triplet representation of  transpose is \n");
     for(int i=0;i<count;i++)
    {
        
   for(int j=0;j<3;j++)
    printf("%d\t",q[i][j]);
     printf("\n");
    }
    int d=0,k=1;
    c=q[0][1],r=q[0][0];
    printf("the transposed matrix is\n");
    for(int i=0;i<r;i++)
    {
        for( int j=0;j<c;j++)
        {
           
           if(q[k][0]==i&&q[k][1]==j)
           {
            printf("%d\t",q[k][2]);
            k++;
           }
            else
            printf("%d\t",d);
            
        }printf("\n");
    }
    
}