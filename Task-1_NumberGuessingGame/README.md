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

