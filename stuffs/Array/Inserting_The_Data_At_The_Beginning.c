# include <stdio.h>

void add_beg(int arr[],int n, int data){//function to shift elements
//    int i=n;
//    while(i>0){
//     arr[i]= arr[i-1];
//     i--;
//    }
for (int i = n; i > 0; i--)
{
    arr[i]= arr[i-1];
}

   arr[0]=data;
  
}


int main(){
    int arr[100],n,data,arr2[100];
    printf("enter the number of elements");
    scanf("%d",&n);

    printf("enter elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the data");
    scanf("%d",&data);

    add_beg(arr,n,data);
    
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
   
}