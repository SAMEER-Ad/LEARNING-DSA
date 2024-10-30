#include <stdio.h>

int main()
{
    int a = 0, i = 0, f = 1; // Initialize variable 'a' for user input
    int g = 1;               // Initialize variable 'g' for factorial result
    // Prompt the user to enter a number
    printf("Enter a number to find factorial: ");
    scanf("%d", &a); // Read the user input and store it in 'a'

    // Loop to calculate the factorial
    while (a > 1)
    {           // Continue until 'a' becomes 1
        g *= a; // Multiply 'g' by the current value of 'a'
        a--;    // Decrease 'a' by 1 (counting down)
    }

    // Output the calculated factorial
    printf("Factorial of the given number is %d\n", g);

    return 0; // End the program
}
