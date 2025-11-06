#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
struct Node*createNode(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;

};
struct Node*insertatbegining(struct Node*head,int data){
    struct Node*newNode=createNode(data);
    newNode->next=head;
    return head;
}
struct Node*insertatend(struct Node*head,int data){
    struct Node*newNode=createNode(data);
    if (head==NULL)
        return newNode;
    struct Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return head;


}
struct Node*insertatposition(struct Node*head,int data,int position)
{
    struct Node*newNode=createNode(data);
    if(position==1){
        newNode->next=head;
        return newNode;
    }

    struct Node*temp=head;
    for(int i =1;i<position-1 && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL){
        printf("position out of range\n");
        free(newNode);
        return head;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
void display(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertatbegining(head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertatposition(head, data, pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
