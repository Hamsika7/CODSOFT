#include <iostream>
#include <limits>

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

char board[3][3];

// Function to initialize/reset the board
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

// Function to display the board with colors
void displayBoard() {
    system("clear || cls"); // Clears the console screen
    cout << BOLD << CYAN << "🎮 TIC-TAC-TOE\n" << RESET;
    cout << YELLOW << "Player 1 (" << RED << "X" << YELLOW << ") vs Player 2 (" << GREEN << "O" << YELLOW << ")\n\n" << RESET;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Assign colors to X and O
            if (board[i][j] == 'X') cout << RED << " X " << RESET;
            else if (board[i][j] == 'O') cout << GREEN << " O " << RESET;
            else cout << BLUE << " " << board[i][j] << " " << RESET;

            if (j < 2) cout << YELLOW << "|" << RESET;
        }
        if (i < 2) cout << "\n" << YELLOW << "---+---+---\n" << RESET;
    }
    cout << "\n";
}

// Function to validate input and get move
bool getPlayerMove(char currentPlayer) {
    int choice;
    while (true) {
        cout << CYAN << "Player " << currentPlayer << RESET << ", enter your move (1-9): ";
        cin >> choice;

        // Check input validity
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "❌ Invalid input! Enter a number between 1-9.\n" << RESET;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << RED << "❌ Spot taken! Choose another.\n" << RESET;
        } else {
            board[row][col] = currentPlayer;
            return true;
        }
    }
}

// Function to check win condition
bool checkWin(char player) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    
    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Main function
int main() {
    char currentPlayer;
    char playAgain;
    bool gameOver;

    do {
        resetBoard();
        currentPlayer = 'X';
        gameOver = false;

        while (!gameOver) {
            displayBoard();
            if (getPlayerMove(currentPlayer)) {
                if (checkWin(currentPlayer)) {
                    displayBoard();
                    cout << GREEN << "🎉 Player " << currentPlayer << " wins!\n" << RESET;
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << YELLOW << "🤝 It's a draw!\n" << RESET;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        // Ask if players want to replay
        cout << CYAN << "Would you like to play again? (y/n): " << RESET;
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "✅ Exiting Tic-Tac-Toe. Goodbye!\n";
    return 0;
}
