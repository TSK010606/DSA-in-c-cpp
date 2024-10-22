#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50  // Define a constant for the maximum size of the array

int arr[MAX_SIZE];  // Declare an array to hold the elements
int size = 0;       // Variable to keep track of the current size of the array

// Function to display the elements of the array
void display() {
    int i;
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }

    // Print each element in the array
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");  // Add a newline after the array elements are printed
}

// Function to insert an element at a specified position
void insertAtPos(int pos, int val) {
    int i;

    // Shift elements to the right to make space for the new element
    for (i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = val;  // Insert the new element at the specified position
    size++;          // Increment the size of the array
    printf("Inserted %d at pos %d\n", val, pos);  // Print confirmation
}

// Function to delete an element from a specified position
void deleteFromPos(int pos) {
    int i;
    int del = arr[pos];  // Store the value being deleted

    // Shift elements to the left to overwrite the deleted element
    for (i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;  // Decrement the size of the array
    printf("Deleted %d at pos %d\n", del, pos);  // Print confirmation
}

// Main function to handle the menu-driven program
int main() {
    int choice, val, pos;  // Variables to store user input for choice, value, and position

    while (1) {  // Infinite loop to continuously display the menu
        // Display menu options
        printf("\n -------- List Menu -----------\n");
        printf("1. Insert at end \n");
        printf("2. Insert at specified pos \n");
        printf("3. Delete at specified pos \n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");

        scanf("%d", &choice);  // Get the user's choice

        switch (choice) {  // Perform the action based on the user's choice
            case 1:  // Insert at the end of the array
                printf("Enter the data: ");
                scanf("%d", &val);
                if (size == MAX_SIZE) {
                    printf("Array is full\n");
                } else {
                    arr[size++] = val;  // Insert the element and increment size
                }
                break;
            case 2:  // Insert at a specified position
                if (size == MAX_SIZE) {
                    printf("Array is full\n");
                    break;
                }
                printf("Enter the pos (pos starts at 0): ");
                scanf("%d", &pos);
                if (pos < 0 || pos > size) {  // Check for valid position
                    printf("Invalid position\n");
                    break;
                }
                printf("Enter the data: ");
                scanf("%d", &val);
                insertAtPos(pos, val);  // Call the function to insert the element
                break;
            case 3:  // Delete an element from a specified position
                if (size == 0) {  // Check if the array is empty
                    printf("Array is empty\n");
                    break;
                }
                printf("Enter the pos: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= size) {  // Check for valid position
                    printf("Invalid position\n");
                } else {
                    deleteFromPos(pos);  // Call the function to delete the element
                }
                break;
            case 4:  // Display the array
                display();
                break;
            case 5:  // Exit the program
                exit(0);
            default:  // Handle invalid choices
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;  // Return 0 to indicate successful program execution
}

