# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node{
    char data[100];
    struct node *link;

};

int main(){
    struct node *head= (struct node*)malloc(sizeof(struct node));
   
    strcpy( head->data,"samir");
    head->link= NULL;

   struct node *temp =(struct node*)malloc(sizeof(struct node));
   strcpy( temp->data,"pranisha");
   head->link=temp;
   temp->link =NULL;
      
      printf("%s  %s\n",head->data,temp->data);//same as
      printf("%s  %s",head->data,head->link->data);
   free(head);
   free(temp);
}