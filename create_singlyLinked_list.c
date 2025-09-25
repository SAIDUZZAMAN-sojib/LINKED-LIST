#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data ;
    struct node *next;
};
struct node *head;

void createlist(int n)
{
    struct node *newnode,*temp;
    int i,data;
    newnode=(struct node *)malloc(sizeof(struct node ));
    if (newnode==NULL)
    {
       return ;
    }
    else
    {
        printf("Enter the the data of node 1 :");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        head=newnode;
        temp=newnode;
        for (int  i = 2; i <=n; i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node ));
            if (newnode==NULL)
            {
               return;

            }
            else 
            {
                printf("Enter the data of node %d ",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;
                temp->next=newnode;
                temp=newnode;


            }
            
        }
        
    }
    
}
void display()
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}
int main() { 
    int n;
    printf("Enter node size:");
    scanf("%d",&n);
    createlist(n);
    display();
    return 0;
}
