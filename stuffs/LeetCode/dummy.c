#include <stdio.h>

// Function to calculate the length of a string
int stringLength(char *str) {
    int length = 0; // Initialize length to 0
    while (str[length] != '\0') { // Loop until the null terminator
        length++; // Increment length for each character
    }
    return length; // Return the calculated length
}

int main() {
    char *sentence = "Hello, this is a sample sentence."; // Initialize the string
    int length = stringLength(sentence); // Call the function to calculate length

    printf("The length of the sentence is: %d\n", length); // Print the length
    return 0;
}