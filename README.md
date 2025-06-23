# -Students-Database-Management-system
Designed a student database management system, that provides various options for adding, removing, sorting and manipulating the data entered. 

## Project Description
This project is a console-based Student Database Management System implemented in C, allowing users to choose between a linked list or a dynamically resizing array data structure at runtime. It manages student records (roll number, name, marks) through a menu-driven interface. Features include adding, removing, sorting (by roll number or marks), updating, and displaying records. The array implementation has no fixed size limit, growing as needed. The code is modular, with a single header file (`header.h`) and separate source files, ensuring clarity and ease of use.

## Features
- Choose linked list or dynamic array at runtime.
- Add new student records (no size limit for array).
- Remove students by roll number.
- Sort students by roll number (ascending) or marks (descending).
- Update student name or marks.
- Display all student records in a table.
- Input validation for robust operation.

## Requirements
- **Compiler**: GCC, MSVC, or any C-compatible compiler (e.g., Dev-C++, Code::Blocks).
- **OS**: Windows, Linux, or macOS.
- **Files**:
  - `src/main.c`: Menu-driven interface with data structure selection.
  - `src/student.c`: Linked list and dynamic array operations.
  - `src/utils.c`: Input validation functions.
  - `include/header.h`: All function and structure declarations.

## Setup Instructions
1. **Clone/Download**:
   - Download the project files or clone the repository.

2. **Compile**:
   - Using GCC:
     ```bash
     gcc src/main.c src/student.c src/utils.c -o student_db

## License
MIT License.

