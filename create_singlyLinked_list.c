#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};//also we can declere here 
struct node *header;
void createlist(int n)
{
  struct node *temp,*newnode;
  int i,data;
  newnode=(struct node* )malloc(sizeof(struct node));
  if (newnode==NULL)
  {
    printf("Unable to allocate memory \n");
    exit(0);
  }
  else 
  {
    printf("Enter the data of node 1: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    header=newnode;
    temp=newnode;

    for (int  i = 2; i <=n; i++)
    {  
       newnode=(struct node *)malloc(sizeof(struct node));
       if (newnode==NULL)
       {
        printf("Unable to allocate memory \n");
        exit(0);
       }
       else {
       
       printf("Enter the data of node %d: ",  i);
       scanf("%d",&data);
       newnode->data=data;
       newnode->next=NULL;
       temp->next=newnode;
       temp=temp->next;
       }

    }
    
  }
  
}
void displayList() {
    struct node *temp = header;
    printf("Linked list contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    displayList();
    return 0;
}
