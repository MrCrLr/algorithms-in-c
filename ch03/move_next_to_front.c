#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *init_list() {
    Node *head = malloc(sizeof *head);
        if (!head) {
        perror("malloc failed for head in init_list");
        exit(EXIT_FAILURE);
    }
    Node *z = malloc(sizeof *z);
        if (!z) {
        perror("malloc failed for x in init_list");
        exit(EXIT_FAILURE);
    }
    head->next = z;
    z->next = z;
    return head;
}

void delete_next(Node *t) {
    t->next = t->next->next;
}

Node *insert_after(int v, Node *t) {
    Node *x = malloc(sizeof *x);
    if (!x) {
        perror("malloc failed in insert_after");
        exit(EXIT_FAILURE);
    }
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

void print_list(Node *head) {
    Node *t = head->next;
    while (t->next != t) {
        printf("%d->", t->key);
        t = t->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    Node *t = head;
    while (t->next != t) {
        Node *next = t->next;
        free(t);
        t = next;
    }
    free(t);
}

int main(void) 
{
    Node *head = init_list();

    Node *x = insert_after(10, head);
    x = insert_after(20, x);
    x = insert_after(30, x);

    print_list(head);
    free_list(head);
}