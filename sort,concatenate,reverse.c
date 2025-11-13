#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *insert_end(struct node *start, int val)
{
    struct node *ptr, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(start == NULL)
        return newnode;

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    return start;
}



struct node *sort_list(struct node *start)
{
    struct node *i, *j;
    int temp;

    for(i = start; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return start;
}


struct node *reverse(struct node *start)
{
    struct node *prev = NULL, *curr = start, *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}



struct node *concatenate(struct node *start1, struct node *start2)
{
    struct node *ptr;

    if(start1 == NULL)
        return start2;

    ptr = start1;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = start2;
    return start1;
}



void display(struct node *start)
{
    struct node *ptr = start;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


int main()
{
    struct node *list1 = NULL, *list2 = NULL;

    list1 = insert_end(list1, 30);
    list1 = insert_end(list1, 10);
    list1 = insert_end(list1, 50);

    list2 = insert_end(list2, 20);
    list2 = insert_end(list2, 40);

    display(list1);
    display(list2);

    list1 = sort_list(list1);
    printf("Sorted: ");
    display(list1);

    list1 = reverse(list1);
    printf("Reversed: ");
    display(list1);

    list1 = concatenate(list1, list2);
    printf("Concatenated: ");
    display(list1);

    return 0;
}
