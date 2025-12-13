#include <stdio.h>
#include <stdlib.h>
#define size 4

int stack_arr[size];
int top = -1;

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    if (!is_full())
    {
        top += 1;
        stack_arr[top] = data;
        return;
    }
    printf("sorry the stack is full\n");
}

int pop()
{
    if (!is_empty())
    {
        int val = stack_arr[top];
        top -= 1;
        return val;
    }
    
    printf("sorry the stack is empty\n");
    return -1;
}

int peek()
{
    if (!is_empty())
    {
        return stack_arr[top];
    }
    printf("sorry the stack is empty\n");
    return -1;
}

void print()
{
    if (!is_empty())
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack_arr[i]);
        }
    }
    else{
            printf("stack is empty\n");
    return;
    }

}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. print the top most element \n");
        printf("4. print all the elements of the stack \n");
        printf("5. quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter a element to push\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("popped data is %d", data);
            break;
        case 3:
            printf("%d", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);

        default:
            printf("worng input sorry\n");
            break;
        }
    }
}
