# 🎮 Task 3: Tic-Tac-Toe Game

A fun and colorful **Tic-Tac-Toe game** built in **C++**, allowing two players to compete on a 3x3 grid. The game is designed with a clear and colorful console interface for an engaging user experience.

---

## 📌 Features

* Two-player mode (Player 1: X, Player 2: O)
* Clear and colorful interface with ANSI color codes
* Input validation (avoids overwriting spots)
* Win detection (row, column, diagonal)
* Draw detection
* Replay option

---

## 🚀 How to Run

### 🧾 Prerequisites
C++ Compiler (like `g++`)

### 💻 Steps


g++ tic_tac_toe.cpp -o tictactoe
./tictactoe

---

## 🧠 How It Works
1. The board is initialized with numbers (1-9).

2. Players take turns to enter their move (1-9).

3. The board updates with the player's symbol (X or O).

4. The game checks for:

    - Win conditions (row, column, diagonal)
  
    - Draw condition (all spots filled)

5. Players can choose to replay after each game.
---

## 🌈 Example Output
```
🎮 TIC-TAC-TOE
Player 1 (X) vs Player 2 (O)

 1 | 2 | 3 
---+---+---
 4 | 5 | 6 
---+---+---
 7 | 8 | 9 

Player X, enter your move (1-9): 5

🎮 TIC-TAC-TOE
Player 1 (X) vs Player 2 (O)

 1 | 2 | 3 
---+---+---
 4 | X | 6 
---+---+---
 7 | 8 | 9 

Player O, enter your move (1-9): 3

...
🎉 Player X wins!
```

## 📊 Time & Space Complexity
| Component            | Time Complexity  | Space Complexity |
| -------------------- | ---------------- | ---------------- |
| Board Initialization | O(1)             | O(1)             |
| Move Validation      | O(1)             | O(1)             |
| Win/Draw Check       | O(1) (3x3 fixed) | O(1)             |

---

## 📂 File Structure
```
Task-3_TicTacToe/
├── tic_tac_toe.cpp       # Main source code
└── README.md             # Documentation
```
---

## 📌 Tags
#C++ #TicTacToe #ConsoleApp #BeginnerProject #GameDevelopment #Task3


