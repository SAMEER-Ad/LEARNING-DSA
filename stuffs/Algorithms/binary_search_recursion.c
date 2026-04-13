#include<stdio.h>
#include<math.h>

int mid;
int rec(int start,int end,int key,int *arr){
    if(start>end){
        return -1;
    }
    mid= floor((start+end)/2);
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        //go left side
       return rec(start,mid-1,key,arr);
    }else if(arr[mid]<key){
        //go right
       return rec(mid+1,end,key,arr);
    }
}

int main(){
    int arr[5] = {1,3,5,7,11};
    int key;
    printf("enter key ");
    scanf("%d", &key);
    int start = 0, end = 4;
    int mid=0;
    if(rec(start,end,key,arr)==-1){
        printf("element didnt found");
    }else{
        printf("element found at index %d ",rec(start,end,key,arr));
    }

}