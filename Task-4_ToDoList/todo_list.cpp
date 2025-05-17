#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ANSI color codes - compatible with most terminals
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";

// ASCII-only symbols (no Unicode) for better compatibility
const string CHECK_MARK = "+";
const string X_MARK = "X";

struct Task {
    string description;
    bool completed;
    string category;
};

// Function to detect if terminal supports colors
bool supportsColors() {
    #ifdef _WIN32
        // For Windows, check if running in modern terminal
        return true; // Modern Windows terminals support ANSI
    #else
        // For Unix-like systems
        const char* term = getenv("TERM");
        return term != nullptr && string(term) != "dumb";
    #endif
}

// Safe clear screen function
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        cout << "\033[2J\033[1;1H";
    #endif
}

void displayTitle() {
    if (supportsColors()) {
        cout << CYAN;
    }
    
    cout << " _____         _         _     _     _   " << endl;
    cout << "|_   _|___  __| |___    | |   (_)___| |_ " << endl;
    cout << "  | |/ _ \\ / _` / _ \\   | |   | / __| __|" << endl;
    cout << "  | | (_) | (_| | (_) |  | |__| \\__ \\ |_ " << endl;
    cout << "  |_|\\___/ \\__,_\\___/   |____|_|___/\\__|" << endl;
    
    if (supportsColors()) {
        cout << RESET;
        cout << YELLOW;
    }
    
    cout << "------------------------------------------" << endl;
    
    if (supportsColors()) {
        cout << RESET;
    }
}

void displayMenu() {
    cout << "\nMENU OPTIONS:" << endl;
    
    if (supportsColors()) {
        cout << BLUE;
    }
    
    cout << " [1]";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " Add new task" << endl;
    
    if (supportsColors()) {
        cout << BLUE;
    }
    
    cout << " [2]";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " View all tasks" << endl;
    
    if (supportsColors()) {
        cout << BLUE;
    }
    
    cout << " [3]";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " Mark task as completed" << endl;
    
    if (supportsColors()) {
        cout << BLUE;
    }
    
    cout << " [4]";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " Delete task" << endl;
    
    if (supportsColors()) {
        cout << BLUE;
    }
    
    cout << " [5]";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " Exit application" << endl;
    
    if (supportsColors()) {
        cout << YELLOW;
    }
    
    cout << "\n > ";
    
    if (supportsColors()) {
        cout << RESET;
    }
}

void addTask(vector<Task>& tasks) {
    clearScreen();
    displayTitle();
    
    if (supportsColors()) {
        cout << MAGENTA << BOLD;
    }
    
    cout << "\nADD NEW TASK";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl;
    
    string description;
    cout << "\nTask description: ";
    getline(cin, description);
    
    if (description.empty()) {
        if (supportsColors()) {
            cout << RED;
        }
        
        cout << "Task cannot be empty! Press Enter to continue...";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cin.get();
        return;
    }
    
    string category;
    cout << "Category (work/personal/study/other): ";
    getline(cin, category);
    
    if (category.empty()) {
        category = "other";
    }
    
    tasks.push_back({description, false, category});
    
    if (supportsColors()) {
        cout << GREEN;
    }
    
    cout << "\nTask added successfully!";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl;
    cout << "\nPress Enter to continue...";
    cin.get();
}

void viewTasks(const vector<Task>& tasks) {
    clearScreen();
    displayTitle();
    
    if (tasks.empty()) {
        if (supportsColors()) {
            cout << YELLOW;
        }
        
        cout << "\nYour task list is empty!";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << endl;
        cout << "\nPress Enter to continue...";
        cin.get();
        return;
    }
    
    if (supportsColors()) {
        cout << MAGENTA << BOLD;
    }
    
    cout << "\nTASK LIST";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl << endl;
    
    // Count stats
    int completed = 0;
    
    // Display ASCII table header
    cout << "+---+-----+---------------------------------+-----------+" << endl;
    cout << "| # | " << (supportsColors() ? BOLD : "") << "S" << (supportsColors() ? RESET : "") 
         << "   | " << (supportsColors() ? BOLD : "") << "Description" << (supportsColors() ? RESET : "") 
         << "                     | " << (supportsColors() ? BOLD : "") << "Category" << (supportsColors() ? RESET : "") 
         << "   |" << endl;
    cout << "+---+-----+---------------------------------+-----------+" << endl;
    
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].completed) completed++;
        
        // Status symbol and color
        string status;
        if (tasks[i].completed) {
            status = supportsColors() ? GREEN + CHECK_MARK + RESET : CHECK_MARK;
        } else {
            status = supportsColors() ? RED + X_MARK + RESET : X_MARK;
        }
        
        // Truncate description if too long
        string desc = tasks[i].description;
        if (desc.length() > 30) {
            desc = desc.substr(0, 27) + "...";
        }
        
        // Format and print the row
        cout << "| " << setw(1) << left << i + 1 << " | " << setw(3) << left << status
             << " | " << setw(31) << left << desc
             << " | " << setw(9) << left << tasks[i].category << " |" << endl;
    }
    
    cout << "+---+-----+---------------------------------+-----------+" << endl;
    
    // Show statistics
    cout << "\nTotal: " << tasks.size() << " tasks | ";
    
    if (supportsColors()) {
        cout << GREEN;
    }
    
    cout << "Completed: " << completed;
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << " | ";
    
    if (supportsColors()) {
        cout << RED;
    }
    
    cout << "Pending: " << tasks.size() - completed;
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl;
    
    cout << "\nPress Enter to continue...";
    cin.get();
}

void markCompleted(vector<Task>& tasks) {
    clearScreen();
    displayTitle();
    
    if (tasks.empty()) {
        if (supportsColors()) {
            cout << YELLOW;
        }
        
        cout << "\nYour task list is empty!";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << endl;
        cout << "\nPress Enter to continue...";
        cin.get();
        return;
    }
    
    if (supportsColors()) {
        cout << MAGENTA << BOLD;
    }
    
    cout << "\nMARK TASK AS COMPLETED";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl << endl;
    
    // Show task list for reference
    for (size_t i = 0; i < tasks.size(); i++) {
        string status;
        if (tasks[i].completed) {
            status = supportsColors() ? GREEN + CHECK_MARK + RESET : CHECK_MARK;
        } else {
            status = supportsColors() ? RED + X_MARK + RESET : X_MARK;
        }
        
        if (supportsColors()) {
            cout << BLUE;
        }
        
        cout << i + 1 << ".";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << " [" << status << "] " << tasks[i].description << endl;
    }
    
    // Get input
    cout << "\nEnter task number to mark as completed (0 to cancel): ";
    int taskNum;
    
    cin >> taskNum;
    cin.ignore();
    
    if (taskNum == 0) {
        return;
    }
    
    if (taskNum >= 1 && taskNum <= static_cast<int>(tasks.size())) {
        if (tasks[taskNum - 1].completed) {
            if (supportsColors()) {
                cout << YELLOW;
            }
            
            cout << "\nThis task is already completed!";
            
            if (supportsColors()) {
                cout << RESET;
            }
            
            cout << endl;
        } else {
            tasks[taskNum - 1].completed = true;
            
            if (supportsColors()) {
                cout << GREEN;
            }
            
            cout << "\nTask marked as completed!";
            
            if (supportsColors()) {
                cout << RESET;
            }
            
            cout << endl;
        }
    } else {
        if (supportsColors()) {
            cout << RED;
        }
        
        cout << "\nInvalid task number!";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << endl;
    }
    
    cout << "\nPress Enter to continue...";
    cin.get();
}

void deleteTask(vector<Task>& tasks) {
    clearScreen();
    displayTitle();
    
    if (tasks.empty()) {
        if (supportsColors()) {
            cout << YELLOW;
        }
        
        cout << "\nYour task list is empty!";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << endl;
        cout << "\nPress Enter to continue...";
        cin.get();
        return;
    }
    
    if (supportsColors()) {
        cout << MAGENTA << BOLD;
    }
    
    cout << "\nDELETE TASK";
    
    if (supportsColors()) {
        cout << RESET;
    }
    
    cout << endl << endl;
    
    // Show task list for reference
    for (size_t i = 0; i < tasks.size(); i++) {
        string status;
        if (tasks[i].completed) {
            status = supportsColors() ? GREEN + CHECK_MARK + RESET : CHECK_MARK;
        } else {
            status = supportsColors() ? RED + X_MARK + RESET : X_MARK;
        }
        
        if (supportsColors()) {
            cout << BLUE;
        }
        
        cout << i + 1 << ".";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << " [" << status << "] " << tasks[i].description << endl;
    }
    
    // Get input
    cout << "\nEnter task number to delete (0 to cancel): ";
    int taskNum;
    
    cin >> taskNum;
    cin.ignore();
    
    if (taskNum == 0) {
        return;
    }
    
    if (taskNum >= 1 && taskNum <= static_cast<int>(tasks.size())) {
        if (supportsColors()) {
            cout << RED;
        }
        
        cout << "\nAre you sure you want to delete this task? (y/n): ";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        char confirm;
        cin >> confirm;
        cin.ignore();
        
        if (tolower(confirm) == 'y') {
            tasks.erase(tasks.begin() + (taskNum - 1));
            
            if (supportsColors()) {
                cout << GREEN;
            }
            
            cout << "\nTask deleted successfully!";
            
            if (supportsColors()) {
                cout << RESET;
            }
            
            cout << endl;
        }
    } else {
        if (supportsColors()) {
            cout << RED;
        }
        
        cout << "\nInvalid task number!";
        
        if (supportsColors()) {
            cout << RESET;
        }
        
        cout << endl;
    }
    
    cout << "\nPress Enter to continue...";
    cin.get();
}

int main() {
    vector<Task> tasks;
    int choice = 0;
    
    while (true) {
        clearScreen();
        displayTitle();
        displayMenu();
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        cin.ignore();
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                clearScreen();
                
                if (supportsColors()) {
                    cout << GREEN;
                }
                
                cout << "\nThank you for using ToDo List Manager!";
                
                if (supportsColors()) {
                    cout << RESET;
                }
                
                cout << endl;
                return 0;
            default:
                if (supportsColors()) {
                    cout << RED;
                }
                
                cout << "\nInvalid choice! Press Enter to continue...";
                
                if (supportsColors()) {
                    cout << RESET;
                }
                
                cin.get();
        }
    }
    
    return 0;
}
