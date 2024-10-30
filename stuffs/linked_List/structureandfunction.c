#include <stdio.h>

struct point {
    int x; 
    int y;
};

struct point2 {
    int a;
    int b;
};

// Edit function for struct point
struct point edit(struct point p) {
    p.x++;           // Increment x by 1
    p.y += 5;        // Add 5 to y
    return p;
}

// Edit function for struct point2
struct point2 edit2(struct point2 p) {
    p.a++;           // Increment a by 1
    p.b += 5;        // Add 5 to b
    return p;
}

// Print function for struct point
void print(struct point p) {
    printf("%d %d\n", p.x, p.y);
}

// Print function for struct point2
void print2(struct point2 p) {
    printf("%d %d\n", p.a, p.b);
}

int main() {
    struct point p1 = {1, 2};    // Initialize struct point
    struct point2 a1 = {3, 4};   // Initialize struct point2

    // Modify both structures
    p1 = edit(p1);   // Call edit for struct point
    a1 = edit2(a1);  // Call edit2 for struct point2

    // Print the modified structures
    print2(a1);      // Output for struct point2
    print(p1);       // Output for struct point (Output is 2 and 7)

    return 0;
}
