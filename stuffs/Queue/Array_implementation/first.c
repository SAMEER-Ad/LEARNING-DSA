#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("overflow");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = x;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = x;
    }
}

int dequeue()
{
    int x;
    if (front == -1 && rear == -1)
    {
        printf("empty");
        return -1;
    }
    else if (front == rear)
    {
        x = queue[front];

        front = -1;
        rear = -1;
    }
    else
    {
        x = queue[front];
        front++;
    }
    return x;
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("empty");
        return;
    }
    while (i < rear + 1)
    {
        printf("%d ", queue[i]);
        i++;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
   int x = dequeue();
    display();
    return 0;
}