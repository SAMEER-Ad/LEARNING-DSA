# include <stdio.h>
#include <string.h>
struct person {
    int age;
    char name[100];

};

int main(){

struct person p1 = {18,"samir"};
struct person p2 ={19,"pranisha"};
struct person *p;
p=&p1;


printf("name is %s and age is %d\n",p->name,p->age);
p=&p2;
printf("name is %s and age is %d",p->name,p->age);

}