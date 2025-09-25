#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;

};
struct node *head,*tail;
void createlist(int n)
{
       int i,data;
       struct node *newnode,*temp;
       newnode=(struct node*)malloc(sizeof(struct node ));
       if (newnode==NULL)
       {
        return ;
       }
       else 
       {
        printf("Enter the data of node 1 :");
        scanf("%d",&data);
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
       }
       for (int  i = 2; i <=n; i++)
       {
        newnode=(struct node*)malloc(sizeof(struct node ));
        if (newnode==NULL)
        {
            return ;
        }
        else 
        {
            printf("Enter the data of node %d :",i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->prev=tail;
            newnode->next=NULL;
            tail->next=newnode;
            tail=newnode;
        }
        
       }
       
}
void display()
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("->%d<-",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}
int main() { 
    int n;
    printf("Enter the size of the node ");
    scanf("%d",&n);
    createlist(n);
    display();

    return 0;
}
