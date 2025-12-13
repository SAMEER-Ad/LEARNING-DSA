#include <stdio.h>
#include<stdlib.h>
#define size 4
int stack_arr[size];
int top = -1;

int is_empty(){
    if(top == -1){
        return 1;
    }
    return 0;

}

int is_full(){
    if(top == size-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(!is_full()){
     top+=1;
     stack_arr[top]= data;   
     return;          
    }
    printf("the stack is full stack overflow");


}

int pop(){
    if(!is_empty()){
        int val;
        val = stack_arr[top];
        top-=1;
        return val;
    }
    printf("the stack is impty");
    exit(1);
}

void traverse(){
    for(int i = top;i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    int data = pop();
    traverse();

}