#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_end(int data) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) return;
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_first(int data) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insert_middle(int data, int position) {
    if (position == 1) {
        insert_first(data);
        return;
    }
    struct node *temp = head, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;
    newnode->data = data;
    newnode->next = NULL;
    for (int i = 2; i <= position - 1; i++) {
        if (temp == NULL) break;
        temp = temp->next;
    }
    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_first(10);
    insert_first(10);
    insert_middle(30,2);
    insert_first(10);
    insert_end(70);
    display();
    return 0;
}
