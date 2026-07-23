// Online C compiler to run C program online
#include <stdio.h>
void NQ();
void DQ();
void display();
int n,S[20],front,rear,i;
void  main()
{
int choice,item;
 front=-1;
 rear=-1;
printf("enter the array size");
scanf("%d",&n);
do
{
    printf("enter the choice \n1.enque\n2.deque\n3.display\n4.exit\nenter choice :  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("enter elemenet");
                scanf("%d",&item);
                NQ(item);
                break;
       case 2: DQ();
       break;
       case 3: display();
       break;
       case 4: break;
    }
}while(choice!=4);
return ;
}
void NQ(int item)
{
    if(rear==n-1)
    {
    printf("element is full");
  }
    else if(rear==n-1){
        front=0;
        rear=0;
        S[rear]=item;
    }
    else{
    rear=rear+1;
    S[rear]=item;}
}
void DQ()
{
    if(front==-1)
    {
    printf("element is empty");
        
    }
    else if(rear==front){
        front=-1;
        rear=-1;
    }
    else
    front=front+1;
    
    
}
void display()
{
    if(rear==-1)
    {
    printf("element is empty");
        
    }
    else 
    for(i=front;i<=rear;i++)
    {
        printf("%d",S[i]);
    }
    
    
}







































