#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};

struct node* head = NULL;

void insert_node(int value);

int main() {
    struct node* current = NULL;
    struct node* next = NULL;
    int array[] = { 1, 5, 8, 3, 6, 0, 9, 4, 2, 7 };
    int i = 0;

    for (i = 0; i < 10; ++i) {
        insert_node(array[i]);
    }

    i = 0;
    current = head;
    while (current != NULL) {
        printf("%d\t%d\n", array[i++], current->number);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

void insert_node(int value) {
    struct node* temp = NULL;
    struct node* prev = NULL;
    struct node* current = NULL;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    temp->number = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else if (value <= head->number) {
        temp->next = head;
        head = temp;
    }
    else {
        prev = head;
        current = head->next;

        while (current != NULL && value > current->number) {
            prev = current;
            current = current->next;
        }

        temp->next = current;
        prev->next = temp;
    }
}