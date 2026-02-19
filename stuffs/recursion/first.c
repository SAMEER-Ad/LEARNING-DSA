#include<stdio.h>

void func(int d){
    printf("%d left of happen\n",d);
    if(d>0){
        func(d-1);

    }
}

int main(){
    func(3);

}