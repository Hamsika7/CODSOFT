# 🎯 Task 1 - Number Guessing Game

This is a simple yet interactive console-based **Number Guessing Game** developed in **C++** as part of my internship with [CodSoft](https://www.codsoft.in/).

---

## 📌 Objective

- To generate a random number within a user-defined range
- Ask the user to guess the number
- Provide feedback: whether the guess is too high or too low
- Repeat until the user guesses the correct number
- Display the number of attempts taken

---

## 💡 Features

- Accepts custom range (e.g., 1 to 100)
- Uses C++'s `rand()` function for randomness
- Console feedback for too high or too low guesses
- Tracks number of attempts
- Clean and user-friendly interaction
- Simple and beginner-friendly C++ project

---

## 🧠 Logic Used

- `srand(time(NULL))` to seed the random generator
- Random number generation with:
  ```cpp
  target = rand() % (upper - lower + 1) + lower;
- Use an infinite loop to continuously take guesses until the correct one is entered.

- Provide condition-based feedback using if, else if, else.

- Track the number of guesses using a counter (attempts).

---
## ⏱ Time and Space Complexity
| Aspect | Complexity                             | Explanation                                                           |
| ------ | -------------------------------------- | --------------------------------------------------------------------- |
| Time   | **O(1)** (per guess), **O(n)** overall | Each comparison is O(1); total time depends on number of guesses (n). |
| Space  | **O(1)**                               | No dynamic memory or arrays used — only basic variables.              |

---
## 🖥️ How to Run

▶️ Compile the program:

```
g++ number_guessing_game.cpp -o game
```
▶️ Run the executable:
```
./game
```
---

## 🧪 Sample Output

```
Enter the lower and upper limits for the number: 1 50
🎯 Welcome to the Number Guessing Game!
I have picked a number between 1 and 50.
Can you guess it?

Enter your guess: 25
TOO HIGH 🔺
Try again...

Enter your guess: 10
TOO LOW 🔻
Try again...

Enter your guess: 17
🎉 CONGRATULATIONS! You guessed it in 3 attempts.
```
---
