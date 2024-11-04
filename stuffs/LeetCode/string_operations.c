#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool iscercular(char *c)
{

    int length = strlen(c);
    // while (c[length]!='\0')
    // {
    //     length++;
    // }
    length--;
    printf(" length is %d",length);

    if (length < 1 || length > 500)
    {
        return false;
    }
    else
    {
        int count = 0;
        char first_letter = c[0];
        char last_letter = c[length - 1];
        printf("first letter is %c and lastone is %c\n", first_letter, last_letter);
        if (first_letter == last_letter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    char c[1000];
    printf(" enter something ");
    fgets(c,sizeof(c),stdin);

    if (iscercular(c))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}