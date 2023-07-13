//linkedlist
#include<stdio.h>
struct node
{
    int data;
   struct node *next;
};

struct node*createnode(int val)
{
    struct node*newnode= (struct node*)malloc(sizeo(struct node));
    newnode->data=val;
    newnode->next=NULL;
}

void begin(struct node**head,int val)
{
    struct node* newnode= createnode(val);
    newnode->next=*head;
    *head=newnode;
}
void end(struct node**head,int val)
{
    struct node *newnode=createnode(val);
    if(*head==NULL)
    {
        *head=newnode;
    }
    struct node*temp=*head;
    while (temp->next!NULL)
    {
        /* code */
        temp=temp->next;
    }
    temp->next=newnode;
    
}

void mid(struct node**head,int val,int pos)
{
    if(pos==1)
    {
        begin(head,val);
    }
        struct Node* newNode = createNode(val);
    struct Node* temp = *head;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
       
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
}
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
   
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < position && temp != NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    
    prev->next = temp->next;
    free(temp);
   
}

void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while (temp2 != NULL && temp2->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    
}
void traverseLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    return 0;
}