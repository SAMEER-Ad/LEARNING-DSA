// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *link;
// };
// void create_node(struct node *head, int data)
// {
//     struct node *ptr, *temp;

//     ptr = head;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;

//     while (ptr->link != NULL)
//     {
//         ptr = ptr->link;
//     }
//     ptr->link = temp;
// }

// void print_nodes(struct node *head)
// {
//     struct node *temp = head;
//     int count=0;
//     while (temp!= NULL)
//     {
//         printf("%d", temp->data);
//         printf("->");
//         count++;
//         temp = temp->link;
//     }
//     printf("NULL\n");
//     printf("there are %d nodes",count);
// }
// int user_input(){
//     int n= 0;
//     printf("enter how many values do u wanna add: ");
//     scanf("%d",&n);
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         printf("value %d: ",i);
//         scanf("%d",&arr[i]);
//     }
//     return arr[n];
    
// }

// int main()
// {
//     struct node *head = (struct node *)malloc(sizeof(struct node));
//     head->data = 10;
//     head->link = NULL;
//      int arr[100];
//       arr[1000]=user_input();
//       for (int i = 0; i < sizeof(arr); i++)
//       {
//         create_node(head,arr[i]);
//       }
      


//     print_nodes(head);
//     free(head);
// }
////solution
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void create_node(struct node *head, int data) {
    struct node *ptr = head;

    // Create a new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    // Traverse to the end of the list
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    // Link the new node
    ptr->link = temp;
}

void print_nodes(struct node *head) {
    struct node *temp = head;
    int count = 0;

    // Print each node's data
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->link;
        
            printf(" -> ");
        
        count++;
    }
    printf("NULL\n");
    printf("There are %d nodes\n", count);
}

void user_input(struct node *head) {
    int n;
    printf("Enter how many values do you want to add: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int value;
        printf("Value %d: ", i + 1);
        scanf("%d", &value);
        create_node(head, value);
    }
}

int main() {
    // Initialize the head node
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10; // You can initialize it to whatever value you prefer
    head->link = NULL;

    // Get user input and create nodes
    user_input(head);
    
    // Print the linked list
    print_nodes(head);

    // Free the allocated memory
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }

    return 0;
}
