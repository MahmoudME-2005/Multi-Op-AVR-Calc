# AVR Expression Engine: Multi-Op Calculator for ATmega32

Inspired by my work as an **Embedded Systems Team Member at the Aviation Club**, this project is a robust C-based calculator engineered for the ATmega32. Unlike standard accumulative calculators, this system parses complex mathematical expressions using a **custom Singly Linked List architecture**.

## �� Key Features
* **True Operator Precedence:** Implements strict adherence to **BODMAS/PEMDAS** (Multiplication/Division handled before Addition/Subtraction).
* **Expression Parsing:** Supports long, multi-operation strings (e.g., `5 + 3 * 2 - 10 / 2`).
* **Unary Minus Support:** Correct recognition of negative numbers at the start or middle of expressions (e.g., `-5 * 3`).
* **Dynamic Memory Logic:** Uses a "list-collapsing" solver that merges nodes in memory as it evaluates the result.
* **Hardware Optimized:** Designed to run efficiently within the 32KB Flash and 2KB RAM constraints of the ATmega32.

## �� The Approach
The solver operates in a multi-pass system:
1.  **Pass 1 (MD):** Scans the list for `X` and `/` operations, performs the math, and collapses the neighbors into a single result node.
2.  **Pass 2 (AS):** Scans the remaining list for `+` and `-` operations to reach the final value.
This approach ensures that $2 + 3 \times 4$ correctly results in $14$, not $20$.



## ��️ Hardware Requirements
* **Microcontroller:** ATmega32
* **Input:** 4x4 Matrix Keypad
* **Output:** 16x2 Character LCD (HD44780)
* **Simulation:** Proteus VSM (Debugged via .elf file)

## �� Project Structure
* `/src` - C Source files (`Calculator.c`, `Linkedlist.c`, etc.)
* `/include` - Header files
* `/sim` - Proteus simulation files

## �� License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details. I built this to be a learning resource for other embedded students!
