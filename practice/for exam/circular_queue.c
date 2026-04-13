#include<stdlib.h>
#include<stdio.h>

#define N 10

int queue[N];
int front =-1;
int rear =-1;

int isEmpty(){
    if(front==-1&&rear==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if((rear+1)%N==front){
        return 1;
    }
    return 0;
}
void enqueue(int x){
    if(isEmpty()){
        front=rear=0;
        queue[rear]=x;
    }
    else if(isFull()){
        printf("full");
        exit(1);

    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void print(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    for(int val=front;val!=rear;val=(val+1)%N){
        printf("%d ", queue[val]);
    }
    printf("%d", queue[rear]);
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue[front];
    
    if(front==rear){
        front = rear = -1;
    }
    else{
        front=(front+1)%N;
    }
    return val;
}

int main(){
    int choice, data;
    
    while(1){
        printf("\n=== CIRCULAR QUEUE MENU ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(isFull()){
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
                data = dequeue();
                if(data != -1){
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                printf("Queue elements: ");
                print();
                printf("\n");
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