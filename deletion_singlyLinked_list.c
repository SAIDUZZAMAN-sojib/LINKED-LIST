#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertAtEnd(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void front_deletion()
{
    struct node *delnode;
    if (head == NULL)
    {
        printf("the node is already empty\n");
    }
    else
    {
        delnode = head;
        head = head->next;
        free(delnode);
    }
}

void end_deletion()
{
    struct node *temp, *delnode;

    if (head == NULL)
    {
        printf("The list is already empty\n");
        return;
    }

    if (head->next == NULL)
    {
        delnode = head;
        head = NULL;
        free(delnode);
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delnode = temp->next;
    temp->next = NULL;
    free(delnode);
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;
    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;
        for (i = 2; i <= position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;
            if (toDelete == NULL)
                break;
        }
        if (toDelete != NULL)
        {
            if (toDelete == head)
                head = head->next;
            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            free(toDelete);
            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Insert at end\n");
        printf("2. Delete from front\n");
        printf("3. Delete from end\n");
        printf("4. Delete from middle (by position)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 2:
                front_deletion();
                break;

            case 3:
                end_deletion();
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteMiddleNode(position);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
