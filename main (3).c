```c
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    Student *ll_head = NULL; // Linked list head
    Student *arr = NULL; // Dynamic array for students
    int arr_count = 0; // Array student count
    int arr_capacity = 0; // Array capacity
    int dataStructure, choice, rollNo;
    char name[50];
    float marks;
    
    // Choose data structure
    printf("Student Database Management System\n");
    printf("Choose data structure:\n");
    printf("1. Linked List\n");
    printf("2. Array\n");
    printf("Enter choice (1 or 2): ");
    dataStructure = getIntInput();
    
    if (dataStructure != 1 && dataStructure != 2) {
        printf("Invalid choice! Defaulting to Linked List.\n");
        dataStructure = 1;
    }
    
    printf("Using %s implementation.\n", dataStructure == 1 ? "Linked List" : "Array");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Sort by Roll Number\n");
        printf("4. Sort by Marks\n");
        printf("5. Update Student\n");
        printf("6. Display Students\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        choice = getIntInput();
        
        switch (choice) {
            case 1: // Add Student
                printf("Enter roll number: ");
                rollNo = getIntInput();
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter marks: ");
                marks = getFloatInput();
                if (dataStructure == 1) {
                    ll_addStudent(&ll_head, rollNo, name, marks);
                } else {
                    arr_addStudent(&arr, &arr_count, &arr_capacity, rollNo, name, marks);
                }
                break;
                
            case 2: // Remove Student
                printf("Enter roll number: ");
                rollNo = getIntInput();
                if (dataStructure == 1) {
                    ll_removeStudent(&ll_head, rollNo);
                } else {
                    arr_removeStudent(&arr, &arr_count, rollNo);
                }
                break;
                
            case 3: // Sort by Roll Number
                if (dataStructure == 1) {
                    ll_sortByRollNo(&ll_head);
                    ll_displayStudents(ll_head);
                } else {
                    arr_sortByRollNo(arr, arr_count);
                    arr_displayStudents(arr, arr_count);
                }
                break;
                
            case 4: // Sort by Marks
                if (dataStructure == 1) {
                    ll_sortByMarks(&ll_head);
                    ll_displayStudents(ll_head);
                } else {
                    arr_sortByMarks(arr, arr_count);
                    arr_displayStudents(arr, arr_count);
                }
                break;
                
            case 5: // Update Student
                printf("Enter roll number: ");
                rollNo = getIntInput();
                if (dataStructure == 1) {
                    ll_updateStudent(ll_head, rollNo);
                } else {
                    arr_updateStudent(arr, arr_count, rollNo);
                }
                break;
                
            case 6: // Display Students
                if (dataStructure == 1) {
                    ll_displayStudents(ll_head);
                } else {
                    arr_displayStudents(arr, arr_count);
                }
                break;
                
            case 7: // Exit
                if (dataStructure == 1) {
                    ll_freeStudents(&ll_head);
                } else {
                    arr_freeStudents(&arr);
                }
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
```