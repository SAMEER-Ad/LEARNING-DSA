#include <stdio.h>

int count(int* arr,int size){
    if(size!=0){


        count(arr,size-1);
        return 1;
    }else
    {
        return 0;
    }
    
}