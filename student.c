```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// --- Linked List Implementation ---

void ll_addStudent(Student **head, int rollNo, char *name, float marks) {
    Student *current = *head;
    while (current) {
        if (current->rollNo == rollNo) {
            printf("Roll number %d already exists!\n", rollNo);
            return;
        }
        current = current->next;
    }
    
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }
    newStudent->rollNo = rollNo;
    strncpy(newStudent->name, name, 49);
    newStudent->name[49] = '\0';
    newStudent->marks = marks;
    newStudent->next = *head;
    *head = newStudent;
    printf("Student added successfully!\n");
}

void ll_removeStudent(Student **head, int rollNo) {
    Student *current = *head, *prev = NULL;
    while (current && current->rollNo != rollNo) {
        prev = current;
        current = current->next;
    }
    
    if (!current) {
        printf("Roll number %d not found!\n", rollNo);
        return;
    }
    
    if (prev) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }
    free(current);
    printf("Student removed successfully!\n");
}

void ll_sortByRollNo(Student **head) {
    if (!*head || !(*head)->next) return;
    
    Student *sorted = NULL, *current;
    while (*head) {
        current = *head;
        *head = current->next;
        
        if (!sorted || sorted->rollNo >= current->rollNo) {
            current->next = sorted;
            sorted = current;
        } else {
            Student *temp = sorted;
            while (temp->next && temp->next->rollNo < current->rollNo) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    *head = sorted;
    printf("Sorted by roll number!\n");
}

void ll_sortByMarks(Student **head) {
    if (!*head || !(*head)->next) return;
    
    Student *sorted = NULL, *current;
    while (*head) {
        current = *head;
        *head = current->next;
        
        if (!sorted || sorted->marks <= current->marks) {
            current->next = sorted;
            sorted = current;
        } else {
            Student *temp = sorted;
            while (temp->next && temp->next->marks > current->marks) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    *head = sorted;
    printf("Sorted by marks!\n");
}

void ll_updateStudent(Student *head, int rollNo) {
    Student *current = head;
    while (current && current->rollNo != rollNo) {
        current = current->next;
    }
    
    if (!current) {
        printf("Roll number %d not found!\n", rollNo);
        return;
    }
    
    printf("Enter new name: ");
    scanf(" %[^\n]", current->name);
    printf("Enter new marks: ");
    scanf("%f", ¤t->marks);
    printf("Student updated successfully!\n");
}

void ll_displayStudents(Student *head) {
    if (!head) {
        printf("No students in database!\n");
        return;
    }
    
    printf("\nStudent Database:\n");
    printf("Roll No | Name                 | Marks\n");
    printf("--------|----------------------|-------\n");
    Student *current = head;
    while (current) {
        printf("%-7d | %-20s | %.2f\n", current->rollNo, current->name, current->marks);
        current = current->next;
    }
}

void ll_freeStudents(Student **head) {
    Student *current = *head, *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// --- Array Implementation ---

void arr_addStudent(Student **array, int *count, int *capacity, int rollNo, char *name, float marks) {
    // Check for duplicate roll number
    for (int i = 0; i < *count; i++) {
        if ((*array)[i].rollNo == rollNo) {
            printf("Roll number %d already exists!\n", rollNo);
            return;
        }
    }
    
    // Resize array if full
    if (*count >= *capacity) {
        int newCapacity = *capacity == 0 ? 10 : *capacity * 2;
        Student *temp = (Student *)realloc(*array, newCapacity * sizeof(Student));
        if (!temp) {
            printf("Memory allocation failed!\n");
            return;
        }
        *array = temp;
        *capacity = newCapacity;
    }
    
    // Add student
    (*array)[*count].rollNo = rollNo;
    strncpy((*array)[*count].name, name, 49);
    (*array)[*count].name[49] = '\0';
    (*array)[*count].marks = marks;
    (*count)++;
    printf("Student added successfully!\n");
}

void arr_removeStudent(Student **array, int *count, int rollNo) {
    int i;
    for (i = 0; i < *count; i++) {
        if ((*array)[i].rollNo == rollNo) break;
    }
    
    if (i == *count) {
        printf("Roll number %d not found!\n", rollNo);
        return;
    }
    
    for (int j = i; j < *count - 1; j++) {
        (*array)[j] = (*array)[j + 1];
    }
    (*count)--;
    printf("Student removed successfully!\n");
}

void arr_sortByRollNo(Student *array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j].rollNo > array[j + 1].rollNo) {
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted by roll number!\n");
}

void arr_sortByMarks(Student *array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j].marks < array[j + 1].marks) {
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted by marks!\n");
}

void arr_updateStudent(Student *array, int count, int rollNo) {
    for (int i = 0; i < count; i++) {
        if (array[i].rollNo == rollNo) {
            printf("Enter new name: ");
            scanf(" %[^\n]", array[i].name);
            printf("Enter new marks: ");
            scanf("%f", &array[i].marks);
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("Roll number %d not found!\n", rollNo);
}

void arr_displayStudents(Student *array, int count) {
    if (count == 0) {
        printf("No students in database!\n");
        return;
    }
    
    printf("\nStudent Database:\n");
    printf("Roll No | Name                 | Marks\n");
    printf("--------|----------------------|-------\n");
    for (int i = 0; i < count; i++) {
        printf("%-7d | %-20s | %.2f\n", array[i].rollNo, array[i].name, array[i].marks);
    }
}

void arr_freeStudents(Student **array) {
    if (*array) {
        free(*array);
        *array = NULL;
    }
}
```