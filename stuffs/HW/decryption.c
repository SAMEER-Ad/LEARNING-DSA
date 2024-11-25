#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void To_decrypt(char *loc1, char *loc2, char *str, int key, int n);

int main()
{
    char string[1000];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    int n = strlen(string);
    char *str = (char *)malloc(n * sizeof(char));
    strcpy(str, string);

    char *loc1 = (char *)malloc(26 * (sizeof(char)));
    for (int i = 0; i < 26; i++)
    {
        loc1[i] = 'A' + i;
    }
    char *loc2 = (char *)malloc(26 * (sizeof(char)));
    for (int i = 0; i < 26; i++)
    {
        loc2[i] = 'a' + i;
    }
    
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%d %c\n",i,loc1[i]);
    // }

    for (int i = 1; i <= 10; i++)
    {
        To_decrypt(loc1, loc2, str, i, n);
    }
    free(str);
    free(loc1);
    free(loc2);
}

void To_decrypt(char *loc1, char *loc2, char *str, int key, int n)
{
    printf("\n");
    printf("\nUsing key %d ", key);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
        {
            if (isupper(str[i]))
            {
                int mod = (-key + str[i] - 'A' + 26) % 26;
                printf("%c", loc1[mod]);
            }
            else if (islower(str[i]))
            {
                int mod = (-key + str[i] - 'a' + 26) % 26;
                printf("%c", loc2[mod]);
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}