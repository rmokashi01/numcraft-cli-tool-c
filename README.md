# NumCraft: Learn Number Systems in C

**NumCraft** is an interactive, command-line C project designed to help learners understand and visualize number systems like binary, octal, decimal, and hexadecimal. Built entirely in C, the project includes multiple modules for practicing quizzes, simulating two's complement, converting between number bases, and exploring bitwise operations.

---

## Project Objectives

- Simplify learning of number systems through interactive modules
- Visualize two’s complement logic for signed integers
- Convert between binary, decimal, octal, and hexadecimal
- Perform and visualize bitwise & byte-level operations
- Practice modular and structured programming in C

---

## 🧱 Project Architecture

```

main.c
│
├── quiz.c               -> Number system quiz
├── twos\_complement.c    -> Two's complement simulator
├── visualizer.c         -> Decimal/Binary/Octal/Hex converter
├── bit\_byte\_ops.c       -> Bitwise & Byte operations
├── input\_utils.c        -> Input helper functions
├── include/\*.h          -> Header files
└── build/               -> Compiled binary output

```

---

## Modules Included

| Module                         | Description                                     |
|-------------------------------|-------------------------------------------------|
| Quiz                          | Multiple-choice quiz on number systems         |
| Two's Complement Simulator     | Step-by-step signed binary conversion          |
| Conversion Visualizer         | Base conversion: Decimal, Binary, Octal, Hex   |
| Bit & Byte Operation Visualizer | Perform bitwise operations on characters       |

---

## User Interface Snapshots

```

\=======================================
Number System Learning Project
\- NumCraft -
=============

Choose a module to explore:

1. Take Number System Quiz
2. Two's Complement Simulator
3. Conversion Visualizer
4. Bit & Byte Operation Visualizer
5. Exit

````

> Each module displays clean, formatted, and easy-to-follow output in the terminal.

---

## C Concepts Applied

- Modular Programming (`.c` / `.h` files)
- Pointers and Dynamic Memory (`malloc`, `free`)
- Structures and Enums
- Bitwise Operations (`&`, `|`, `^`, `~`, `<<`, `>>`)
- Conditional Logic and Loops
- ASCII and Character Manipulation
- Header Guards and Function Prototypes

---

## Compilation & Execution

### ▶️ Using GCC:
```bash
gcc -Iinclude -Wall src/main.c src/quiz.c src/twos_complement.c src/visualizer.c src/bit_byte_ops.c src/input_utils.c -o build/numcraft
./build/numcraft
````

### ▶️ Optional: Using Makefile

```bash
make
./build/numcraft
```

---

## 🚀 Getting Started

1. Clone this repository
   `git clone https://github.com/rmokashi01/numcraft-cli-tool-c.git`

2. Navigate into the project
   `cd numcraft-number-system`

3. Compile and run the project
   `make` or use the manual GCC command above

---

## Developed As Part of

> **Emertxe Embedded Systems Course – Advanced C Module**
> **March 2025 – September 2025**

This project was built using concepts taught in the Advanced C module during the 6-month embedded systems course.

---


---

## Acknowledgments

* Emertxe Institute for training and guidance
* Open-source C resources and tutorials
* Terminal UI inspiration from educational CLI tools

---

## ✍️ Author

**Rehan Mokashi**
📧 [rehannokashi786@gmail.com](mailto:rehannokashi786@gmail.com)
🔗 [LinkedIn](https://www.linkedin.com/in/rehan-mokashi-7b32472a2/)
---

> 💬 *"Every bit counts, every byte matters — and with each logic built in C, we craft clarity from complexity."*

```
