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

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
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
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    return 0;
}
