# include <stdio.h>
# include<stdlib.h>

struct abc{
    int a;
    char b;
};
 
 void print(struct abc arr[]){

    for (int i = 0; i < 2; i++)
    {
        printf("%d %c \n", arr[i].a,arr[i].b);
        printf("\n");
    }
    
 }
 
int main(){
  struct abc arr[2] = {{1,'A'},{2,'B'}}; 
  print(arr);  
}

