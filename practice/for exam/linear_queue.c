#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];

int front=-1;
int rear = -1;

int isEmpty(){
    if(front==-1&&rear==-1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    return 0;
}

void enqueue(int x){
    if(isEmpty()==1){
        front = rear = 0;
        queue[rear]=x;

    }
    else if(isFull()==1){
        printf("the queue is full");
        exit(0);

    }
    else{
        rear+=1;
        queue[rear]=x;
    }
}
void dequeue(){
    if(isEmpty()){
        printf("the queue is empty\n");
        return;
    }
    else if(front==0&&rear==0){
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeued: %d\n", queue[front]);
        front+=1;
    }
}
void print(){
    if(isEmpty()==1){
        printf("Queue is empty\n");
        return;
    }
    int val = front;
    while(val <= rear){
        printf("%d ", queue[val]);
        val++;
    }
    printf("\n");
}

int main(){
    int choice, data;
    
    while(1){
        printf("\n=== QUEUE MENU ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(isFull() == 1){
                    printf("Queue is full - cannot enqueue\n");
                }
                else{
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue(data);
                    printf("Enqueued: %d\n", data);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Queue elements: ");
                print();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}