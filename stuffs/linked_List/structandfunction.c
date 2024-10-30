#include <stdio.h>

struct point
{
    char name[50];
    int age;
};

void print(struct point *p)
{
    printf("name is %s and age is %d", p->name, p->age);
}

int main()
{
    struct point p1 = {"samir", 18};
    print(&p1);
    
}