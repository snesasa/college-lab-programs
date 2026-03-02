// sparse triplet sum
#include <stdio.h>
void main()
{
int a[10][10],r,c,count=0,b[101][3];
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
    for(int i=0;i<count+1;i++)
    {
    for(int j=0;j<3;j++)
    printf("%d\t",b[i][j]);
     printf("\n");
    }
    //for matrix 2
    int c2[10][10],m,n,count2=0,d[101][3];
    printf("enter the no of rows and columns for matrix2\n");
    scanf("%d%d",&m,&n);
    printf("enter the numbers\n");
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        scanf("%d",&c2[i][j]);
        
    }
    printf("the matrix is\n");
    for(int i=0;i<m;i++)
   { for(int j=0;j<n;j++)
    {
        printf("%d\t",c2[i][j]);
        
    }printf("\n");
   }
     d[0][0]=m;
        d[0][1]=n;
       
        
    for(int i=0;i<m;i++)
     
    for(int j=0;j<n;j++)
    
        if(c2[i][j]!=0)
        {
           
            count2++;
                d[count2][0]=i;
                d[count2][1]=j;
                d[count2][2]=c2[i][j];
            
        }
        
     d[0][2]=count2;
    printf("the sparse triplet representation is\n");
    for(int i=0;i<count2+1;i++)
    {
    for(int j=0;j<3;j++)
    printf("%d\t",d[i][j]);
     printf("\n");
    }
    //sum
    int sum[10][10],c1,cmat2 ,c3;
    if(m==r||n==c)
    {
        int count3;
        if(count>count2)
        count3=count;
        else
        count3=count2;
        c3=0;
        c1=1;
        cmat2=1;
        for(int i=0;i<r;i++)
        {
           
              
                for(int j=0;j<count3;j++)
                {
                 
              if(b[c1][0]==i&&d[cmat2][0]==i)
               { 
                   if (b[c1][1]==d[cmat2][1])
                    {
                    c3++;
                    sum[c3][0]=b[c1][0];
                     sum[c3][1]=b[c1][1];
                    sum[c3][2]=b[c1][2]+d[cmat2][2];
                    c1++,cmat2++;
                    } 
              else if(b[c1][1]<d[cmat2][1])
                   {
                    c3++;
                    sum[c3][0]=b[c1][0];
                     sum[c3][1]=b[c1][1];
                    sum[c3][2]=b[c1][2];
                    c1++;
                    }  
              else
                    {
                    c3++;
                    sum[c3][0]=d[cmat2][0];
                     sum[c3][1]=d[cmat2][1];
                    sum[c3][2]=d[cmat2][2];
                    cmat2++;
                    } 
                }
     else if(b[c1][0]==i)
                   {
                    c3++;
                    sum[c3][0]=b[c1][0];
                     sum[c3][1]=b[c1][1];
                    sum[c3][2]=b[c1][2];
                    c1++;
                    }  
    else if(d[cmat2][0]==i)
                    {
                    c3++;
                    sum[c3][0]=d[cmat2][0];
                     sum[c3][1]=d[cmat2][1];
                    sum[c3][2]=d[cmat2][2];
                    cmat2++;
                    } 
                    
              }   
   }    
        
            sum[0][0]=r;
            sum[0][1]=c;
            sum[0][2]=c3;
          
            printf("the sparse  triplet representation of sum is \n");
        for(int i=0;i<c3+1;i++)
                    {
                        for(int j=0;j<3;j++)
                        printf("%d\t",sum[i][j]);
                        printf("\n");
                    }
                    int c4=1,zero=0;
             printf("the sum matrix is\n");  
          for(int i=0;i<r;i++)
             {
             for(int j=0 ;j<c;j++)
               {
                 if(sum[c4][0]==i&&sum[c4][1]==j)
                    {
                      printf("%d\t",sum[c4][2]);
                      c4++;;
                      }
                  else
                  printf("%d\t",0);
              }
            printf("\n");
             }
         }
        
        else printf("addition not possible");
        
      
    }
/*
    enter the no of rows and columns
3
3
enter the numbers
1
0
0
9
5
6
0
0
0
the matrix is
1	0	0	
9	5	6	
0	0	0	
the sparse triplet representation is
3	3	4	
0	0	1	
1	0	9	
1	1	5	
1	2	6	
enter the no of rows and columns for matrix2
3
3
enter the numbers
2
0
0

0
4
5
6
0
0
0
0
the matrix is
2	0	0	
4	5	6	
0	0	0	
the sparse triplet representation is
3	3	4	
0	0	2	
1	0	4	
1	1	5	
1	2	6	
the sparse  triplet representation of sum is 
3	3	4	 
0	0	3	
1	0	13	
1	1	10	
1	2	12	
the sum matrix is
3	0	0	
13	10	12	
0	0	0	


    */ 