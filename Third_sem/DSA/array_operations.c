
#include <stdio.h>

#define CAPACITY 10  // Maximum size of the array

int arr[CAPACITY];  // Array storage
int size = 0;       // Current number of elements

// Function to insert an element
void insert(int element) {
    if (size < CAPACITY) {
        arr[size++] = element;
    } else {
        printf("Array is full! Cannot insert.\n");
    }
}


// Function to display the array
void display() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Insert elements
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    display();

    // Delete an element at index 2
    removeAt(2);
    display();

    // Insert more elements
    insert(30);
    insert(35);
    display();

    return 0;
}
