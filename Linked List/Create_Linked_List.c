#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create_node(int value) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *new_node = NULL;
    int i, value;
    printf("Enter 5 integer: \n");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        new_node = create_node(value);
        if (head == NULL) {
            head = new_node;
            temp = head;
        }
        else {
            temp -> next = new_node;
            temp = temp -> next;
        }
    }

    return 0;
}