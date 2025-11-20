#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    int total = 0;
    int index = 0;

    // Find where head should start
    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            index = i;
            break;
        }
    }

    printf("\nC-LOOK Order: ");

    // Move right
    for (i = index; i < n; i++) {
        printf("%d ", req[i]);
        total += abs(head - req[i]);
        head = req[i];
    }

    // Jump to lowest request
    if (index != 0) {
        total += abs(head - req[0]);
        head = req[0];
    }

    // Move right again
    for (i = 0; i < index; i++) {
        printf("%d ", req[i]);
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
