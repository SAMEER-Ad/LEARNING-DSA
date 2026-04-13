#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top =-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isFull()){
        printf("stack overflow");
        exit(1);
    }
    top+=1;
    stack[top]=data;

}
int pop(){
    if(isEmpty()==1){
        printf("stack underflow\n");
        exit(1);
    }
    int val=stack[top];
    top=top-1;
    return val;
}

void print(){
    if(isEmpty()==1){
        printf("stack is empty\n");
        exit(1);
    } 
    for(int i = top; i >= 0; i--){
        printf("%d -> ", stack[i]);
    }  
}
int peek(){
    if(isEmpty()==1){
        printf("stack is empty\n");
        exit(1);
    } 
    return stack[top];    
}
int size(){
    return top + 1;
}

int main(){
    int choice, data;
    
    while(1){
        printf("\n=== STACK MENU ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                printf("Pushed: %d\n", data);
                break;
            case 2:
                if(isEmpty() == 1){
                    printf("Stack is empty\n");
                }
                else{
                    data = pop();
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
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