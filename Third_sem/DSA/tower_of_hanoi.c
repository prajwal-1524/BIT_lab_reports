#include <stdio.h>

// Function to solve Tower of Hanoi recursively
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to); // Base case: move one disk
        return;
    }
    // Move n-1 disks from 'from' to 'aux', so they are out of the way
    towerOfHanoi(n - 1, from, aux, to);
    // Move the nth disk from 'from' to 'to'
    printf("Move disk %d from %c to %c\n", n, from, to);
    // Move the n-1 disks from 'aux' to 'to'
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3;  // Number of disks
    printf("The sequence of moves to solve the Tower of Hanoi for 3 disks:\n");
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B, C are the rods
    return 0;
}
