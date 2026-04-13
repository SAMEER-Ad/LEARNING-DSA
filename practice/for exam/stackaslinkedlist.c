#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// 🔼 Push
void push(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// 🔽 Pop
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node* temp = top;
    top = top->next;
    free(temp);
}

// 👁️ Peek (Top element)
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

// 🔁 Display stack
void display() {
    struct node* temp = top;

    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 🧪 Main
int main() {
    push(10);
    push(20);
    push(30);

    display();   // 30 20 10

    peek();      // 30

    pop();
    display();   // 20 10

    pop();
    pop();
    pop();       // Underflow

    return 0;
}