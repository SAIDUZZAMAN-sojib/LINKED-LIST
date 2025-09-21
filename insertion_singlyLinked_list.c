#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
} *header;

void first_insertion(int data)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(0);
    }
    else
    {
        printf("Enter the first node value to insert :");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = header;
        header = newnode;
        printf("Data inserted successfully\n");
    }
}

void last_insertion(int data)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("unable to allocate memory \n");
        exit(0);
    }
    else
    {
        printf("Enter the data you insert in the end\n");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        if (header == NULL)
        {
            header = newnode;
        }
        else
        {
            temp = header;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf("Data insert successfully at the end\n");
    }
}

void insert_anyposition(int data, int position)
{
    struct node *newnode, *temp;
    int i;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &position);
        printf("Enter the data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        if (position == 1)
        {
            newnode->next = header;
            header = newnode;
            printf("DATA INSERTED SUCCESSFULLY\n");
            return;
        }
        temp = header;
        for (i = 2; i <= position - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
            free(newnode);
        }
    }
}

void display()
{
    struct node *temp = header;
    printf("Linked list contents: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int data;
    int choice;
    printf("Enter where you want to add data\n");
    while (1)
    {
        printf("1.Front\n2.Any position\n3.End\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:first_insertion(data);break;
        case 2:insert_anyposition(data,0);break;
        case 3:last_insertion(data);break;
        case 4:display();break;
        case 5:exit(0);
        default:printf("Insert a valid choice\n");
        }
    }
    return 0;
}
