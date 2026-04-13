#include<stdio.h>
#include<math.h>


int main(){
    int arr[5] = {1,3,5,7,11};
    int key;
    printf("enter key ");
    scanf("%d", &key);
    int start = 0, end = 4;
    int mid=0;
    while (start <= end)
    {
        mid = floor((start+end)/2);
        if(arr[mid]==key){
            break;
        }
        else if(arr[mid]>key){
            //left side
            end=mid-1;

        }
        else if(arr[mid]<key){
            //right side
            start=mid+1;
        }
    }
    if(start>end){
        printf("element didnt found");
    }else{
        printf("element found at index %d ",mid);
    }
}