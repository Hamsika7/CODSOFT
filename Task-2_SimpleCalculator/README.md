# 🧮 Task 2: Simple Calculator

A command-line C++ calculator that allows users to perform **basic arithmetic operations**: addition, subtraction, multiplication, and division. Designed with input validation, error handling (e.g., division by zero), and a clear, user-friendly menu system.

---

## 📌 Features

- Addition, Subtraction, Multiplication, Division
- User-friendly interface with colorful output
- Robust error handling for invalid inputs and division by zero
- Continuous operation until user chooses to exit

---

## 🚀 How to Run

### 🧾 Prerequisites
C++ Compiler (like `g++`)

### 💻 Steps

```bash
g++ simple_calculator.cpp -o calculator
./calculator
```
---
## 🧠 Sample Output

```
==== SIMPLE CALCULATOR ====
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
5. Exit
Enter your choice (1-5): 4
Enter two integers: 12 0
Error: Division by zero is undefined.
```
---
## 🧮 Code Breakdown
### 🎯 Functions
| Function | Description                               |
| -------- | ----------------------------------------- |
| `Add()`  | Adds two integers                         |
| `Sub()`  | Subtracts the second from the first       |
| `Mul()`  | Multiplies two integers                   |
| `Div()`  | Divides first by second, with error check |


### 📜 Control Flow
1. Show menu

2. Take user choice

3. Ask for two integers

4. Perform operation using switch

5. Repeat until exit

---

## 📊 Time & Space Complexity

| Operation      | Time Complexity | Space Complexity |
| -------------- | --------------- | ---------------- |
| Addition       | O(1)            | O(1)             |
| Subtraction    | O(1)            | O(1)             |
| Multiplication | O(1)            | O(1)             |
| Division       | O(1)            | O(1)             |

---
## 📂 File Structure
```
Task-2_SimpleCalculator/
├── simple_calculator.cpp   # Main source code
└── README.md               # Documentation
```
---
## 📌 Tags
#C++ #Calculator #BeginnerProject #ConsoleApp #BasicMath #Task2







