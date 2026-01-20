# C Data Structures

This repository contains my implementations of fundamental data structures in C. The primary goal is to understand the low-level logic, memory management, and pointer arithmetic behind these structures by implementing them from scratch.

Each structure is designed to be modular, clean, and reusable, mimicking how libraries are built in real-world scenarios.

## Project Structure

The project is organized by data structure. Common utilities are separated to be reused by other structures.

```text
C-Data-Structures/
├── dynamic-array/          # Generic Dynamic Array implementation
│   ├── dynamic_array.c
│   └── dynamic_array.h
├── linked-list/            # Singly Linked List
│   ├── linked_list_implementation/
│   │   ├── linked_list.c
│   │   ├── linked_list.h
│   │   └── test_linked_list.c
│   ├── node_trial/
│   │   ├── node_lib.h
│   │   └── node.c
├── stack/                  # Stack implementations
│   ├── array_based_implementation/
│   │   ├── stack.c
│   │   ├── stack.h
│   │   └── main.c          # Test file for Stack
│   └──  linked_list_based_implementation/
│   │   ├── stack.c
│   │   ├── stack.h
│   │   └── test_ll_stack.c
├── .gitignore
└── README.md
```

## Implemented Structures

### 1. Dynamic Array

A resizable, generic array implementation that serves as a core building block for other data structures.

- **Generic Design:** Uses `void*` to store any data type (int, struct, etc.).
- **Memory Management:** Handles manual memory allocation (`malloc`, `realloc`, `free`) internally.
- **Auto-Resizing:** Automatically doubles its capacity when full.
- **Custom Deconstructor:** Supports a user-defined function to free complex data types stored in the array.

### 2. Stack (Array Based)

A LIFO (Last-In, First-Out) data structure.

- **Modular Architecture:** This implementation does **not** manage a raw array directly. Instead, it utilizes the **Dynamic Array** module defined above.
- **Operations:** `push`, `pop`, `top`, `isEmpty`.
- **Separation of Concerns:** Shows how to decouple the container logic (Dynamic Array) from the data structure logic (Stack).

### 3. Linked List

A singly linked list implementation written from scratch.

- **Operations:** Insertion (head, tail), Deletion, Traversal, Search.
- **Memory:** Demonstrates dynamic node creation and pointer manipulation.

### Upcoming Structures

- Queue
- Tree (BST)
- Heap
- Hash Table

## Goals

- **Deep Understanding:** Learning how data structures work "under the hood" without relying on high-level abstractions or built-in libraries.
- **Memory Safety:** Practicing manual memory management to prevent memory leaks in C.
- **Code Reusability:** Writing modular code where low-level structures are reused by higher-level ones.

## Build & Run Guide

Since the project uses a modular structure (e.g., Stack depends on the Dynamic Array module), you need to link multiple source files and include headers during compilation.

**Example: Building the Stack**

1. Navigate to the stack implementation directory:
   ```bash
   cd stack/array_based_implementation
   ```
2. Compile using GCC (linking with Dynamic Array):

   ```bash
   gcc -I. -I../../dynamic-array *.c ../../dynamic-array/*.c -o program
   ```

_Note: `-I` flag tells the compiler where to look for header files. 3. Run the executable:_

    ```bash
    # Windows
    .\program.exe

    # Linux / Mac
    ./program
    ```

## Tools Used

- **Language:** C (Standard C99/C11)

- **Compiler:** GCC (via MinGW / MSYS2)

- **IDE:** VS Code

- **Debugger:** GDB

## Developer

[Çiğdem Yıldız](https://github.com/Cigdem-Yildiz)
