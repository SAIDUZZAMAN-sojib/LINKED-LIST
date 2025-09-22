#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head, *last;

void createList(int n) {
    int i, data;
    struct node *newNode;

    if (n >= 1) {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;

        for (i = 2; i <= n; i++) {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode;
            last = newNode;
        }
    }
}

void insert_first(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    if (last == NULL)
        last = newNode;
}

void insert_last(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = last;
    if (last != NULL)
        last->next = newNode;
    last = newNode;
    if (head == NULL)
        head = newNode;
}

void insert_position(int data, int position) {
    struct node *newNode, *temp;
    int i;

    if (head == NULL) {
        printf("Error, List is empty!\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    if (newNode->next == NULL) {
        last = newNode;
    }
}

void displayList() {
    struct node *temp;
    int n = 1;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        printf("\nDATA IN THE LIST:\n");
        while (temp != NULL) {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}

int main() {
    int n, data, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    printf("\nEnter data to insert at first: ");
    scanf("%d", &data);
    insert_first(data);
    displayList();

    printf("\nEnter data to insert at last: ");
    scanf("%d", &data);
    insert_last(data);
    displayList();

    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    insert_position(data, pos);
    displayList();

    return 0;
}

