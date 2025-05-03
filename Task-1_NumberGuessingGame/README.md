# 🎮 Task 1: Number Guessing Game with Difficulty Levels

This project is a fun and interactive **Number Guessing Game** built in **C++**, enhanced with difficulty selection, hint system, scoring, and guess history tracking.

---

## 🧩 Objective

Build a C++ program where:
- The user selects a difficulty level (Easy, Medium, Hard)
- The game generates a random number in that range
- The user has a maximum of 10 attempts to guess the number
- Hints and guess history are provided
- The score decreases with each incorrect attempt

---

## 🚀 Features

- 🧠 **Difficulty Levels**: Easy (1-10), Medium (1-100), Hard (1-1000)
- 🔄 **Replay Option**: Users can play multiple rounds
- 📜 **Guess History**: Displays all previous guesses
- 🧮 **Hint System**: Odd/Even hints at certain attempts
- 🏆 **Scoring**: Score starts at 100, decreases by 10 per wrong guess
- ⏱️ 10 attempts per round

---

## 🛠️ How It Works

1. User chooses difficulty level.
2. A random number is generated in that range.
3. User enters guesses with feedback:
   - Too High / Too Low
4. Hints are shown on attempt 3 and 5:
   - Whether the number is **even** or **odd**
5. If guessed correctly:
   - Show congratulatory message and score
6. Else:
   - Reveal the correct number after 10 attempts

---

## 🧠 Logic Overview

- `rand() % max + 1` ensures a random number within selected range.
- A `vector` stores the history of guesses.
- Score calculation:
  ```cpp
  Score = 100 - (attempts * 10);
---
## ⏱ Time and Space Complexity
| Component         | Time Complexity | Space Complexity |
| ----------------- | --------------- | ---------------- |
| Random generation | O(1)            | O(1)             |
| Guess processing  | O(n)            | O(n) (history)   |
| Overall           | O(n)            | O(n)             |

---
## 🖥️ How to Run

▶️ Compile the program:

```
g++ number_guessing_game.cpp -o guessing_game
```
▶️ Run the executable:
```
./guessing_game
```
---

## 🧪 Sample Output

```
Choose Difficulty Level:
1. Easy (1 - 10)
2. Medium (1 - 100)
3. Hard (1 - 1000)
Enter your choice: 2

You have 10 attempts to guess the number!

Attempt 1 - Enter your guess: 50
Too low!

Previous guesses: 50

Attempt 2 - Enter your guess: 70
Too high!

Previous guesses: 50 70

Attempt 3 - Enter your guess: 65
Too high! (Hint: It's an odd number)

Previous guesses: 50 70 65

...

🎉 Correct! You guessed it in 6 tries.
Your Score: 40
```
---
## 📂 File Structure

Task-1_EnhancedNumberGuessingGame/
```
│
├── number_guessing_game.cpp   # Main source file
└── README.md                  # This file
```
---
## 📚 Learning Highlights

- Use of rand() and srand() for randomness
- User input validation and structured gameplay
- Using vector for dynamic data (guess history)
- Efficient control structures and scoring logic
---
💬 “Keep guessing... until you get it right — just like learning!”
