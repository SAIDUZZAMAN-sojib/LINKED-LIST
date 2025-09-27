#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void insert_first(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    } else {
        tail = newnode;
    }

    head = newnode;
}

void insert_end(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL) {
        tail->next = newnode;
        tail = newnode;
    } else {
        head = tail = newnode;
    }
}

void insert_middle(int data, int position) {
    if (position <= 1) {
        insert_first(data);
        return;
    }

    struct node *temp = head;
    int i;
    for (i = 2; i <= position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        insert_end(data);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = data;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    } else {
        tail = newnode;
    }

    temp->next = newnode;
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("<-%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() { 
    insert_first(10);
    insert_end(30);
    insert_middle(20, 2);
    insert_middle(40, 10);
    display();
    return 0;
}
