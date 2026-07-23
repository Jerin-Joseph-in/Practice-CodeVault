#include <stdlib.h>
#include <stdio.h>
#define n 100
void IF(int item);
void IR(int item);
void DF();
void DR();
void display();
int s[n];
int i=0;
int item;
int front=-1;
int rear=-1;
int main()
{
    int c;
    do{
printf("\n1. INSERT REAR\t2. DELETE FRONT\t3. INSERT FRONT\t4. DELETE REAR\t5. DISPLAY\t6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: printf("enter the item to insert");
                    scanf("%d",&item);
                    IR(item);
                    break;
            case 2: DF();
                    break;
            case 3: printf("enter the item to insert");
                    scanf("%d",&item);
                    IF(item);
                    break;
            case 4: DR();
                    break;
            case 5: display();
                    break;
            case 6:break;
            default: printf("invalid");
                    break;
        }
}
    while(c!=6);
        return 0;
}
void IR(int item)
{
    if(rear==n-1)
    {
        printf("full");
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            s[rear]=item;
        }
        else
        {
            rear=rear+1;
            s[rear]=item;
        }
    }
}
void DF()
{
    if(front==-1)
    {
        printf("empty");
    }
    else
    {
        if(front==rear)
        {
            front=rear=-1;
            
        }
        else
        {
            s[front]=item;
            front=front+1;
        }
    }
}
void IF(int item)
{
    if(front==0)
    {
        printf("not possible");
    }
    else
    {
        if(front==-1)
        {
            front=rear=0;
            s[front]=item;
        }
        else{
        front=front-1;
        s[front]=item;
    }
}
}
void DR()
{
    if(rear==-1)
    {
        printf("not possible");
    }
    else
    {
        if(front==rear)
        {
            front=rear=-1;
            
        }
        else
        {
          rear=rear-1;
        }
    }
}
void display()
{
    if(front==-1)
    {
        printf("its empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",s[i]);
        }
    }
}
    
















