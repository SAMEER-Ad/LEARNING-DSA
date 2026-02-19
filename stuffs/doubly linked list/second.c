#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* firstNode(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data = data;
    temp->next=NULL;
    return temp;
}

struct node* addAtBeg(int data,struct node* head){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data =data;

    temp->next=head;
    head->prev= temp;
    head = temp;
    return head;
}
struct node* addAtEnd(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data = data;
    temp->next =NULL;
    struct node* tp =head;
    while (tp->next!=NULL)
    {
        tp=tp->next;
    }
    tp->next = temp;
    temp->prev= tp;
    return head;
    
}
void print(struct node* head){
    struct node* temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
    

}
int returnSize(struct node *head){
    struct node* ptr = head;
    int count  = 0;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
    
}
struct node* addAtPos(struct node* head,int data, int position,int size){
    struct node* newp= NULL;
    struct node* temp = head;
    struct node* temp2 =NULL;
    newp= firstNode(data);
    if(position>size){
        printf("sorry cant do that");
        return 0;
    }
    if(position==1){
        head = addAtBeg(data,head);
    return head;
    }

    while(position>2){
        temp=temp->next;
        position--;

    }
    if(temp->next== NULL){
        temp->next= newp;
        newp->prev=temp;
        return head;
    }
    else{
        temp2= temp->next;
        temp->next= newp;
        temp2->prev=newp;
        newp->next= temp2;
        newp->prev=temp;
        return head;
    }
}

int main(){
    struct node* head = NULL;
    head = firstNode(10);
    head= addAtBeg(0,head);
    head = addAtEnd(head,20);
    head = addAtEnd(head,30);
    head = addAtEnd(head,40);
    head = addAtEnd(head,50);
    int size = returnSize(head);
    head = addAtPos(head,35,5,size);
    print(head);

}