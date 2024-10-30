#include <stdio.h>

// solution

 int add(int* a){
  *a=(*a)+1;
 }

int main(){
  int a=10;
  add(&a);
  printf("%d",a);
}