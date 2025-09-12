#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[100];
    int id;
    char location[100];
    float cg;
    struct node *next;
};

int main() { 
    struct node n1, n2, n3, n4;
    struct node *p;

    printf("Enter the information serially (name) (id) (location) (cg)\n");
    scanf("%s %d %s %f", n1.name, &n1.id, n1.location, &n1.cg);
    scanf("%s %d %s %f", n2.name, &n2.id, n2.location, &n2.cg);
    scanf("%s %d %s %f", n3.name, &n3.id, n3.location, &n3.cg);
    scanf("%s %d %s %f", n4.name, &n4.id, n4.location, &n4.cg);

    p = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    printf("\n%-15s %-10s %-15s %-10s\n", "Name", "ID", "Location", "CG");
    printf("--------------------------------------------------------\n");

    while (p != NULL) {
        printf("%-15s %-10d %-15s %-10.2f\n", p->name, p->id, p->location, p->cg);
        p = p->next;
    }

    return 0;
}
