#include <stdio.h>
int r,c,x,y,z,i,j,k;
int a[20][20],b[30][30];
int main()
{
    printf("enter the row size");
    scanf("%d",&r);
     printf("enter the column size");
    scanf("%d",&c);
    
    printf("enter the elements");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
    }
    }k=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
    {
   
        if(a[i][j]!=0)
        {
            b[k][0]=i;
            b[k][1]=j;
            b[k][2]=a[i][j];
            k++;
        }
  
    }
    }
 b[0][0]=r;
 b[0][1]=c;
 b[0][2]=k-1;
   
    for(i=0;i<k;i++)
    {
        printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
        
    }
    return 0;
}

























