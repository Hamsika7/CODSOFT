# Task 4: To-Do List Manager

A feature-rich console-based To-Do List application with an attractive, interactive interface. This application allows users to manage their tasks efficiently with visual formatting and user-friendly prompts.

---

## 📌 Features

- **Interactive Console UI**: Color-coded interface with ASCII art header
- **Task Management**:
  - Add tasks with descriptions and categories
  - View all tasks in a formatted table
  - Mark tasks as completed
  - Delete unwanted tasks
- **Visual Elements**:
  - Color-coding for statuses (completed/pending)
  - ASCII tables for organized display
  - Task statistics showing completion progress
- **Cross-Platform Compatibility**: Works on Windows, macOS, and Linux
- **Error Handling**: Robust input validation to prevent crashes
---
## 🚀 How to Run

### 🧾 Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- Terminal that supports ANSI colors (optional, but recommended for best experience)

### 💻 Steps

```bash
# Compile the code
g++ todo_list.cpp -o todo_list

# Run the application
./todo_list   # On Linux/macOS
todo_list.exe # On Windows
```
---

## 🧠 Sample Output

```
 _____         _         _     _     _   
|_   _|___  __| |___    | |   (_)___| |_ 
  | |/ _ \ / _` / _ \   | |   | / __| __|
  | | (_) | (_| | (_) |  | |__| \__ \ |_ 
  |_|\___/ \__,_\___/   |____|_|___/\__|
------------------------------------------

MENU OPTIONS:
 [1] Add new task
 [2] View all tasks
 [3] Mark task as completed
 [4] Delete task
 [5] Exit application

 > 2

TASK LIST

+---+-----+---------------------------------+-----------+
| # | S   | Description                     | Category   |
+---+-----+---------------------------------+-----------+
| 1 | X   | Complete C++ assignment         | study     |
| 2 | X   | Buy groceries                   | personal  |
| 3 | +   | Update resume                   | work      |
+---+-----+---------------------------------+-----------+

Total: 3 tasks | Completed: 1 | Pending: 2

Press Enter to continue...
```
---
## 📊 Code Breakdown

### 🎯 Functions

| Function | Description |
|----------|-------------|
| `displayTitle()` | Renders the ASCII art header |
| `displayMenu()` | Shows the main menu options |
| `addTask()` | Handles adding new tasks to the list |
| `viewTasks()` | Displays all tasks in a formatted table |
| `markCompleted()` | Allows marking tasks as completed |
| `deleteTask()` | Removes tasks from the list |
| `clearScreen()` | Clears the terminal for better UI |
| `supportsColors()` | Detects terminal color support |

---
### Control Flow

1. The main loop continuously displays the menu until the user chooses to exit
2. Each menu option calls the corresponding function
3. After each operation, the user is prompted to continue
4. Input validation ensures the program doesn't crash with invalid inputs
---

### 📊 Time & Space Complexity

- **Time Complexity**: O(n) for most operations where n is the number of tasks
- **Space Complexity**: O(n) where n is the number of tasks
---

## 📂 File Structure

```
Task-4_ToDoList/
├── todo_list.cpp   # Main source code
└── README.md       # Documentation
```
---

## Advanced Features

- **Automatic color detection**: Adapts to terminal capabilities
- **ASCII art interface**: Provides a professional appearance
- **Cross-platform compatibility**: Functions correctly on all major operating systems
- **Input validation**: Handles unexpected inputs gracefully
---
## Future Improvements

- Task persistence (saving to file)
- Due date reminders
- Priority levels for tasks
- Search and filter capabilities
- Task editing functionality
---
## 📌 Tags

#CPP #ToDoList #TaskManager #ConsoleApp #ProductivityTool #Task4 #InternshipProject
