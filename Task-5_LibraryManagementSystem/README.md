# Task 5: Library Management System

A comprehensive console-based Library Management System with interactive features. This application allows library staff to efficiently manage their book inventory and borrower transactions with a user-friendly interface.

---

## 📚 Features

- **Interactive Console Interface**: Clean and organized menu system
- **Book Management**:
  - Add new books with title, author, and ISBN
  - Search books by title, author, or ISBN
  - Check out books to borrowers
  - Process book returns with fine calculation
  - View all books with availability status
- **Visual Elements**:
  - Status indicators for books (Available/Checked Out)
  - Emoji-based feedback for successful operations
  - Organized display of book information
- **Cross-Platform Compatibility**: Works on Windows, macOS, and Linux
- **Error Handling**: Input validation to prevent crashes and data corruption
---
## 🚀 How to Run

### 🧾 Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- Terminal with basic text support

### 💻 Steps

```bash
# Compile the code
g++ library_management.cpp -o library_management

# Run the application
./library_management   # On Linux/macOS
library_management.exe # On Windows
```
---
## 🧠 Sample Output

```
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. Show Books
6. Exit
Enter your choice: 1

Enter book title: Clean Code
Enter author: Robert C. Martin
Enter ISBN: 9780132350884

✅ Book added successfully!

===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. Show Books
6. Exit
Enter your choice: 5

📚 Available Books:
Title: Clean Code, Author: Robert C. Martin, ISBN: 9780132350884 (Available)
```
---
## 📊 Code Breakdown

### 🎯 Classes & Structures

| Component | Description |
|----------|-------------|
| `Book` | Structure to store book details (title, author, ISBN, status) |
| `Borrower` | Structure to store borrower information and borrowed books |
| `Library` | Main class that encapsulates all operations and data |

---
### 🔧 Key Functions

| Function | Description |
|----------|-------------|
| `addBook()` | Adds a new book to the library database |
| `searchBook()` | Searches for books by title, author, or ISBN |
| `checkoutBook()` | Processes book checkout operations |
| `returnBook()` | Handles book returns and calculates any fines |
| `showBooks()` | Displays all books in the library inventory |

---
### 📜 Control Flow

1. The main loop displays the menu until the user chooses to exit
2. Each menu option calls the corresponding Library class method
3. Input validation ensures the program handles user input properly
4. Status updates provide feedback after each operation
---
### 📊 Time & Space Complexity

- **Time Complexity**: O(n) for search operations where n is the number of books
- **Space Complexity**: O(n+m) where n is the number of books and m is the number of borrowers
---
## 📂 File Structure

```
Task-5_LibraryManagement/
├── library_management.cpp   # Main source code
└── README.md                # Documentation
```
---
## Advanced Features

- **Fine calculation**: Automated system for calculating overdue fines
- **Object-oriented design**: Encapsulated functionality for better code organization
- **Input validation**: Handles edge cases and unexpected inputs
- **Status indicators**: Visual feedback for operation results
- **ISBN-based tracking**: Unique identifiers for precise book management

---

## 📌 Tags

#CPP #LibraryManagement #BookTracker #ConsoleApp #DatabaseSystem #Task5 #InternshipProject
