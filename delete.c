#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* delete_end(struct Node* start) {
    struct Node* ptr, *preptr;

    if (start == NULL)
        return NULL;


    if (start->next == NULL) {
        free(start);
        return NULL;
    }

    ptr = start;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);
    return start;
}

struct Node* delete_beg(struct Node* start) {
    struct Node* ptr;

    if (start == NULL)
        return NULL;

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

struct Node* delete_pos(struct Node* start) {
    struct Node* ptr, *preptr;
    int pos, i = 1;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
        return delete_beg(start);

    ptr = start;
    while (ptr != NULL && i < pos) {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Invalid position!\n");
        return start;
    }

    preptr->next = ptr->next;
    free(ptr);

    return start;
}


void display(struct Node* start) {
    struct Node* ptr = start;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int main() {
    struct Node* start = NULL;
    struct Node* n1 = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);


    start = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printf("Original Linked List:\n");
    display(start);

    start = delete_beg(start);
    printf("\nAfter deleting from beginning:\n");
    display(start);

    start = delete_end(start);
    printf("\nAfter deleting from end:\n");
    display(start);

    start = delete_pos(start);
    printf("\nAfter deleting from given position:\n");
    display(start);

    return 0;
}
