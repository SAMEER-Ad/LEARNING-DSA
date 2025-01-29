#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pointer;
};

int  countNode(struct node *head){
    int count =0;
    struct node *current = head;
    while(current!=NULL){
        count++;
        current = current->pointer;
 
    }
return count;
}

int insertNOdeAtCertainPosition(int data,int position,struct node *head){
    struct node *current = head;
    if(position>countNode(head)){
        printf("position is out of bound");
        return 0;
    }
}

void DeleteLastNode(struct node *head){
    struct node *current = head;
    while(current->pointer->pointer!=NULL){
        current = current->pointer;
    }
    current->pointer = NULL;
}
void deleteFirstNode(struct node *head){
    struct node *current = head;
    head = head->pointer;
    free(current);
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->pointer = NULL;
    head->data = 0;

    struct node* second = malloc(sizeof(struct node));
    second->pointer=NULL;
    second->data= 1;
    head->pointer = second;
    int count =countNode(head);
    printf("%d",count);


}