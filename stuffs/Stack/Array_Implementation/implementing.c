#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top>=MAX-1){
        printf("stack overflow");
        return;
    }
    top=top+1;
    stack_arr[top] = data;
}
int pop(){
    if(top==-1){
        printf("stack underflow");
        exit(1);
    }
    int value = stack_arr[top];
    top = top-1;
    return value;
}
void traverse(){
    if(top<0){
        printf("stack is empty");
        return;
    }
    for (int i = top; i >=0; i--)
    {
        printf("%d\t",stack_arr[i]);
    }
    
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    int num = pop();
    traverse();
    return  0;

}