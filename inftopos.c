#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[50];
char E[30];
char item;
int top=-1,n,i;
void push(char item)
{
    if(top==n-1)
    {
        printf("full");
    }
    else
    {
        top=top+1;
        s[top]=item;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("its empty");
        return '\0';
    }
    else
    {
        item=s[top];
        top=top-1;
        return item;
    }
}
 int P(char sym)
 {
 switch(sym)
 {
     case '^':return 3;
     case '*':
     case '/':return 2;
     case '+':
     case '-':return 1;
     default:return 0;
 }
 }
 
 void infix()
 {
     push('(');
     strcat(E,")");
     for(i=0;E[i]!='\0';i++)
     {
         item=E[i];
         if(item=='(')
         {
             push(item);
         }
         else if(isalnum(item))
         {
             printf("%c",item);
         }
         else if(item=='^'||item=='*'||item=='+'||item=='-'||item=='/')
         {
             while(top!=-1 && P(s[top])>P(item))
             {
                 printf("%c",pop());
             }
             push(item);
         }
         else if(item==')')
         {
             while(top!=-1 && s[top]!='(')
             {
                 printf("%c",pop());
             }
             pop();
         }
         else
         {
             printf("invalid expression");
             break;
         }
     }
         
         
         
         
     }

int main()
{
    printf("enter the size");
    scanf("%d",&n);
    printf("enter the expression : ");
    scanf("%s",&E);
    infix();
    return 0;
}
