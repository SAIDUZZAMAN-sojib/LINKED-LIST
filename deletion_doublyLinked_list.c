#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

void insertAtEnd(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
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
        newNode->prev = temp;
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
        printf("%d <-> ", temp->data);
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
        if (head != NULL)
            head->prev = NULL;
        free(delnode);
    }
}

void end_deletion()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The list is already empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete;
    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        for (i = 1; i < position && toDelete != NULL; i++)
        {
            toDelete = toDelete->next;
        }
        if (toDelete != NULL)
        {
            if (toDelete == head)
            {
                head = toDelete->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else
            {
                if (toDelete->next != NULL)
                    toDelete->next->prev = toDelete->prev;
                if (toDelete->prev != NULL)
                    toDelete->prev->next = toDelete->next;
            }
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
