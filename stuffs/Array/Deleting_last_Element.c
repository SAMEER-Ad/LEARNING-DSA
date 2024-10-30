#include <stdio.h>

int Delete_Last(int *num)
{
    *num = *num - 1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Delete_Last(&size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}