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
    Node *tail = malloc(sizeof *tail);
        if (!tail) {
        perror("malloc failed for x in init_list");
        exit(EXIT_FAILURE);
    }
    head->next = tail;
    tail->next = tail;
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

Node *move_next_to_front(Node *head, Node *tail, Node *t) {
    if (!head || !t || !t->next) return head;
    if (t->next == tail) return head;

    Node *x = t->next;
    t->next = x->next;
    x->next = head->next;
    head->next = x;

    return head;
}

Node *exchange(Node *head, Node *tail, Node *t, Node *u) {
    if (!head || !t || !t->next || !u || !u->next) return head;
    if (t->next == tail || u->next == tail) return head;
    if (t == u) return head;

    Node *x = t->next;
    Node *y = u->next;

    // Case 1: Non-adjacent
    if (x != u && y != t) {
        Node *tmp = x->next;
        t->next = y;
        u->next = x;
        x->next = y->next;
        y->next = tmp;
        return head;
    }
    // Case 2: Adjacent (x follows t, and y == x->next)
    // t -> x -> y
    if (u == x) {
        t->next = y;
        x->next = y->next;
        y->next = x;
        return head;
    }
    // Case 3: Adjacent reversed (u before t)
    if (t == y) {
        u->next = x;
        y->next = x->next;
        x->next = y;
        return head;
    }

    return head;
}

void print_list(Node *head) {
    Node *t = head->next;
    while (t->next != t) {
        printf("%d", t->key);
        t = t->next;
        if (t->next != t) printf("->");
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
    Node *tail = head->next;
    
    Node *t = insert_after(10, head);
    Node *u = insert_after(20, t);
    u = insert_after(30, u);
    Node *w = insert_after(40, u);
    w = insert_after(50, w);
    w = insert_after(60, w);

    printf("t->key = %d, u->key = %d, w->key = %d\n", t->key, u->key, w->key);
    print_list(head);

    move_next_to_front(head, tail, u);
    print_list(head);

    exchange(head, tail, t, u);
    print_list(head);

    delete_next(head->next->next);
    print_list(head);

    free_list(head);

    return 0;
}