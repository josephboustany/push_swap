
# Push Swap

This project is part of the 42 School curriculum and aims to create a sorting algorithm using a limited set of operations and two stacks (A and B). The goal is to sort a list of integers in ascending order with the fewest number of operations possible.

## Table of Contents
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Features](#features)
- [Operations](#operations)
- [Sorting Algorithm](#sorting-algorithm)

## Project Structure

This repository contains the following main files:

- **Makefile**: Builds the `push_swap` executable.
- **main.c**: Entry point for the program.
- **linked_list.c**: Defines linked list operations for managing the stacks.
- **basic_operations.c**: Contains core stack operations such as `push`, `swap`, etc.
- **rotation_operations.c**: Implements rotation operations for stack manipulation.
- **radix_sort.c**: Contains the sorting algorithm based on radix sort.
- **utils.c**: Helper functions to support various functionalities.
- **push_swap.h**: Header file with shared definitions and prototypes.

## Getting Started

### Prerequisites
- **GCC** or any C compiler
- **Make** (for using the Makefile)
- **Standard libraries**: The project only depends on standard C libraries.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/username/push_swap.git
   cd push_swap
   ```
2. Build the project using the Makefile:
   ```bash
   make
   ```
   This will generate the `push_swap` executable in the directory.

## Usage

To run the program, use:
```bash
./push_swap <list_of_numbers>
```
Example:
```bash
./push_swap 3 2 5 1 4
```

The program outputs the sequence of operations required to sort the list in ascending order.

## Features

- **Error Handling**: Handles invalid inputs (non-integer values, duplicates, etc.).
- **Optimized Operations**: Minimizes the number of moves to sort the list.
- **Multiple Sorting Algorithms**: Implements an optimized radix sort for larger inputs.

## Operations

This project uses the following operations:

1. **sa**: Swap the first two elements of stack A.
2. **sb**: Swap the first two elements of stack B.
3. **ss**: Simultaneously swap the first two elements of both stacks.
4. **pa**: Push the first element of stack B onto stack A.
5. **pb**: Push the first element of stack A onto stack B.
6. **ra**: Rotate stack A (shift all elements up, first becomes last).
7. **rb**: Rotate stack B.
8. **rr**: Rotate both stacks A and B.
9. **rra**: Reverse rotate stack A.
10. **rrb**: Reverse rotate stack B.
11. **rrr**: Reverse rotate both stacks A and B.

## Sorting Algorithm

For small inputs, the algorithm minimizes moves through brute-force or simple sorting techniques. For larger inputs, a more complex approach like radix sort is implemented to reduce the number of operations.
