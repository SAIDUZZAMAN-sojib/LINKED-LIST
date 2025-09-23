#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *header = NULL;

void createList(int n) {
    struct node *temp, *newNode;
    int data, i;

    if (n <= 0) {
        return;
    }

    header = (struct node *)malloc(sizeof(struct node));
    if (header == NULL) {
        return;
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    header->data = data;
    header->next = NULL;
    temp = header;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            return;
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

void displayList() {
    struct node *temp = header;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\nLinked list contents: ");
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
    createList(n);
    displayList();
    return 0;
}
