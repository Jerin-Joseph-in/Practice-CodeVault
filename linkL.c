#include <stdlib.h>
#include <stdio.h>


int item,i;
int key;
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
    if(head==NULL)
    {
        head=new;
        new->link=NULL;
        
    }
    else
    {
        new->link=head;
        head=new;
        
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
        head=new;
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

void insertspecpos(int item,int key)
{ struct node *new, *ptr;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = item; // Initialize the new node's data

    if (head == NULL) {
        printf("List is empty\n");
        free(new); // Free the allocated memory since we won't use this node
        return;
    }

    ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found\n");
        free(new); // Free the new node since we won't insert it
    } else {
        new->link = ptr->link; // Link the new node to the next node
        ptr->link = new; // Link the previous node to the new node
    }
}

void deletefront()
{ struct node*temp;
    if(head==NULL)
    {
        printf("its empty");
    
    
    }
    else if(head->link==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
       temp=head;
       head=head->link;
       free(temp);
    }
}

void deleteend()
{ struct node*temp,*ptr;
    if(head==NULL)
    {
        printf("its empty");
    
    }
    else if(head->link==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        ptr=head;
        temp=head;
        while(ptr->link!=NULL)
        {   temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        free(ptr);
        
    }
}

void deletespecpos(int key)
{struct node*temp,*ptr;
    if(head==NULL)
  {
      printf("no elemt is there");
  }
  else if(head->link==NULL)
  {
      temp=head;
      head=NULL;
      free(temp);
      
      
  }
    else
    {
        ptr=head;
        temp=head;
      while(ptr->link!=NULL&&ptr->data!=key)
      {   temp=ptr;
          ptr=ptr->link;
      }
      if(ptr->data!=key)
      {
          printf("not possible");
      }
        else
        {
            temp->link=ptr->link;
            free(ptr);
        }
    }
}
void display()
{struct node*ptr;

  if(head==NULL)
  {
      printf("no elemt is there");
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
int main()
{ int c;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific position\n");
        printf("4. Delete front\n");
        printf("5. Delete end\n");
        printf("6. Delete specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:printf("enter the element ");
                   scanf("%d",&item);
                   insertfront(item);
                   break;
            case 2:printf("enter the element ");
                   scanf("%d",&item);
                   insertend(item);
                   break;
            case 3:printf("enter the element ");
                   scanf("%d",&item);
                   printf("enter the key");
                   scanf("%d",&key);
                   insertspecpos(item,key);
                   break;
            case 4:deletefront();
                   break;
            case 5:deleteend();
                   break;
            case 6:printf("enter the key");
                   scanf("%d",&key);
                   deletespecpos(key);
                   break;
            case 7:display();
                   break;
            case 8:break;
            default:printf("invalid choice");
        }
    }while(c!=8);
    return 0;
}


















