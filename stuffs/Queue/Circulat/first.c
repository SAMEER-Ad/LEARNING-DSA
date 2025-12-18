#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

int isEmpty(){
    if(front==-1&&rear == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if((rear+1)%N == front){
        return 1;
    }
    return 0;
}

void enqueue(int x){
    if (isFull())
    {
        printf("the queue is full");
        return;
        
    }
    else if(isEmpty()){
        front = 0;
        rear =0;
        queue[rear] = x;
    }
    else{
        rear =(rear+1)%N;
        queue[rear] = x;
    }

}

int dequeue(){
    int x;
    if(isEmpty()){
      printf("the queue is already empty");
      return -1;
    }
    else if(front == rear){
         x= queue[front];
        front =-1;
        rear =-1;

    }
    else{
        x= queue[front];
        front = (front+1)%N;
    }
    return x;
}

int peek()
{
    if (isEmpty())
    {
        printf("the queue is already empty");
        return -1;
    }
    return queue[front];
}
void display()
{
    if (isEmpty())
    {
       printf("the queue is empty");
       return;
    }
    
    int x = front;
    while (1)
    {
        printf("%d ", queue[x]);
        if(x==rear){
            break;
        }
        x= (x+1)%N;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    int x = dequeue();
    x = dequeue();
    display();
}
