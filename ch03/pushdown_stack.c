#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *init_stack(int value) {
    Node *stack = malloc(sizeof *stack);
    if (!stack) {
        perror("malloc failed in init_stack()");
        exit(EXIT_FAILURE);
    }
    stack->key = value;
    stack->next = NULL;
    return stack;
}

void push(Node **stack, int value) {
    Node *new_node = malloc(sizeof *new_node);
    if (!new_node) {
        perror("malloc failed in push()");
        exit(EXIT_FAILURE);
    }
    new_node->key = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(Node **stack) {
    if (*stack == NULL) {
        fprintf(stderr, "Error: pop() on empty stack\n");
        exit(EXIT_FAILURE);
    }
    Node *top = *stack;
    int value = top->key;
    *stack = top->next;
    free(top);
    return value;
}

void print_stack(Node *stack) {
    for (Node *t = stack; t; t = t->next)
        printf("%d ", t->key);
    printf("\n");
}

int main(void) 
{
    Node *stack = init_stack(10);
    push(&stack, 9);
    push(&stack, 5);
    push(&stack, 2);

    printf("Stack before pop: ");
    print_stack(stack);

    int x = pop(&stack);
    printf("Popped value: %d\n", x);

    printf("Stack after pop: ");
    print_stack(stack);

    return 0;
}