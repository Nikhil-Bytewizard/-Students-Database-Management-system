```c
#ifndef HEADER_H
#define HEADER_H

// Student structure
typedef struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student *next; // Used only for linked list
} Student;

// Linked list function prototypes
void ll_addStudent(Student **head, int rollNo, char *name, float marks);
void ll_removeStudent(Student **head, int rollNo);
void ll_sortByRollNo(Student **head);
void ll_sortByMarks(Student **head);
void ll_updateStudent(Student *head, int rollNo);
void ll_displayStudents(Student *head);
void ll_freeStudents(Student **head);

// Array function prototypes
void arr_addStudent(Student **array, int *count, int *capacity, int rollNo, char *name, float marks);
void arr_removeStudent(Student **array, int *count, int rollNo);
void arr_sortByRollNo(Student *array, int count);
void arr_sortByMarks(Student *array, int count);
void arr_updateStudent(Student *array, int count, int rollNo);
void arr_displayStudents(Student *array, int count);
void arr_freeStudents(Student **array);

// Utility function prototypes
void clearInputBuffer(void);
int getIntInput(void);
float getFloatInput(void);

#endif
```