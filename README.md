# Generalized Data Structures Library

## Overview
The **Generalized Data Structures Library** is a collection of various data structure implementations in C++. This library provides essential data structures such as stacks, queues, linked lists, and more, allowing for efficient data management and manipulation.

## Features
- **Singly Linked List**: Implementation of a singly linked list with basic operations.
- **Doubly Linked List**: Implementation of a doubly linked list supporting forward and backward traversal.
- **Circular Linked List**: Implementation of a circular linked list for continuous traversal.
- **Stack**: A stack implementation using a singly linked list.
- **Queue**: A queue implementation using a singly linked list.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- CMake (optional, for building projects)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/KaradkarOm/Generalized-Data-Structures-Library.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Generalized-Data-Structures-Library
   ```

### Usage
- To use the data structures in your project, include the respective header files in your source files. For example:
```cpp
#include "include/Stack.h"
#include "include/Queue.h"
```
Running Tests
To compile and run the test files, navigate to the Tests directory and compile the test files:

``` bash 
g++ -o testStack StackTest.cpp ../include/Stack.h
./testStack
```
Replace StackTest.cpp and Stack.h with the respective test file and header file as needed.


