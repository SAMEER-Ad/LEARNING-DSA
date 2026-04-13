#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// ➕ Enqueue (Insert at rear)
void enqueue(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// ➖ Dequeue (Remove from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// 👁️ Peek (Front element)
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

// 🔁 Display queue
void display() {
    struct node* temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 🧪 Main
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();   // 10 20 30

    peek();      // 10

    dequeue();
    display();   // 20 30

    dequeue();
    dequeue();
    dequeue();   // Underflow

    return 0;
}