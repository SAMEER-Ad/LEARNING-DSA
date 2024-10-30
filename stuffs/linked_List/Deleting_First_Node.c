# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* link;

};
void AtEnd(struct node* head,int data){
    struct node* ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }

    struct node* second= malloc(sizeof(struct node));
    second->data=data;
    second->link=NULL;

    ptr->link =second;
}

void PrintNodes(struct node* head){
    int count=0;
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
        count++;

    }
    printf("there are %d nodes",count);

    
}
 struct node* DeleteFirstNode(struct node* head){
    struct node* temp=head;
    head=head->link;
    free(temp);
    temp = NULL;
    return head;
 }

int main(){
   

   struct node* head= malloc(sizeof(struct node));
   head->data=0;
   head->link= NULL;

    AtEnd(head,1);
    AtEnd(head,2);
    AtEnd(head,3);
    AtEnd(head,4);
    AtEnd(head,5);
    
    head= DeleteFirstNode(head);
    head= DeleteFirstNode(head);
    PrintNodes(head);
}


