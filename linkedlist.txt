#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
int n,c,item,key;
struct node
{
    int data;
    struct node*link;
};
struct node*head=NULL;

void insertfront(int item)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        head= new;
    }
    else
    {
        new->link=head;
        head= new;
    }
}
void insertend(int item)
{
   struct node*new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        head= new;
    } 
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}
void insertspeckey(int item,int key)
{
    struct node*new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        printf("not found");
    }
    else
    {
        ptr=head;
          while(ptr->link!=NULL && ptr->data!=key)
        {
            ptr=ptr->link;
        }
        if(ptr->data!=key)
        {
            printf("not exits");
        }
        else
        {   new->link=ptr->link;
            ptr->link=new;
        }
    }
}
void display()
{ struct node*ptr;
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->link;
        }
        printf("%d",ptr->data);
    }
}
void deletefront()
{
    struct node*ptr;
    if(head==NULL)
    {
        printf("NULL");
    }
    else if(head->link==NULL)
    {
      ptr=head;
      head=NULL;
      free(ptr);
    }
    else
    {
        ptr=head;
        head=head->link;
        free(ptr);
    }
}
void deleteend()
{
   struct node*ptr,*curr;
    if(head==NULL)
    {
        printf("NULL");
    }
    else if(head->link==NULL)
    {
      ptr=head;
      head=NULL;
      free(ptr);
    } 
    else
    {
        ptr=head;
        curr=head;
        while(ptr->link!=NULL)
        {
            curr=ptr;
            ptr=ptr->link;
        }
        curr->link=NULL;
        free(ptr);
    }
}
void deletespeckey(int key)
{
    struct node*ptr,*curr;
    if(head==NULL)
    {
        printf("NULL");
    }
    else if(head->data==key)
    {
      ptr=head;
      head=NULL;
      free(ptr);
    }
    else
    {
        
        ptr=head;
        curr=head;
          while(ptr->link!=NULL && ptr->data!=key)
        {   curr=ptr;
            ptr=ptr->link;
        }
        if(ptr->data!=key)
        {
            printf("not exits");
        }
        else
        {
            curr->link=ptr->link;
            free(ptr);
        }
    }
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    do {
        printf("1. Insert front\n");
        printf("2. insert end\n");
        printf("3.  insert key\n");
        printf("4. delete front\n");
        printf("5. delete end\n");
        printf("6. delete key\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                insertfront(item);
                break;

            case 2:
                printf("Enter the item: ");
                scanf("%d", &item);
                insertend(item);
                break;

            case 3:
                printf("Enter the item: ");
                scanf("%d", &item);
                printf("enter the key");
                scanf("%d",&key);
                insertspeckey(item,key);
                break;

            case 4:deletefront();
                    break;
            
            
            case 5:deleteend();
                    break;
            
            
            case 6:
                printf("enter the key");
                scanf("%d",&key);
                deletespeckey(key);
                    break;
                   
            case 7:
                display();
                break;

            case 8:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (c != 8);

    return 0;
}
