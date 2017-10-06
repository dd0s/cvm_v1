#include <stdio.h>
#include <stdlib.h>

// STACK
struct node {
    int data;
    struct node* next;
} node;

// if it was init(struct node* head) {  }, function init would have its own COPY (not original) of 
// head pointer, but using pointers we can access original head pointer fairly easy
void init(struct node** head) {
    *head = NULL;
}

// pointer to pointer because in C everything is passed by value, even pointers
// so in order to access THAT ORIGINAL main()'s head pointer from push() function, you should 
// use pointer to pointer
void push(struct node** head, int value) {
    // after exiting from the function, tmp pointer will be destroyed
    // but the memory allocated on right side of "=" will remain, and 
    // the ORIGINAL head pointer will point to it
    struct node* tmp = (struct node*)malloc(sizeof(struct node));

    if (tmp == NULL) {
        exit(1);
    }
    tmp->data = value;
    tmp->next = *head;
    *head = tmp;
}

void print_stack(struct node* head) {
    struct node* curr = head;
    while(curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

void print_head(struct node* head) {
    printf("%d\n", head->data);
}

int main(int argc, char* argv[]) {
    struct node* head;
    init(&head);
    push(&head, 10);
    push(&head, 20);
    printf("%d\n", head->data);
    print_stack(head);
    return 0;
}

