#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

// Operation functions
int Add(int num1, int num2) { return num1 + num2; }
int Sub(int num1, int num2) { return num1 - num2; }
int Mul(int num1, int num2) { return num1 * num2; }
double Div(int num1, int num2) {
    if (num2 == 0) {
        cout << "\033[1;31mError: Division by zero is undefined.\033[0m\n";
        return 0;
    }
    return static_cast<double>(num1) / num2;
}

// Show calculator menu
void showMenu() {
    cout << "\n\033[1;34m==== SIMPLE CALCULATOR ====\033[0m\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    int num1, num2, choice;
    bool run = true;

    while (run) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "\033[1;31mInvalid input. Please enter a valid number (1-5).\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 5) {
            cout << "\033[1;32mThank you for using the calculator!\033[0m\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "\033[1;31mInvalid choice. Please select between 1 and 5.\033[0m\n";
            continue;
        }

        cout << "Enter two integers: ";
        cin >> num1 >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << Add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << Sub(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << Mul(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << Div(num1, num2) << endl;
                break;
        }
    }

    return 0;
}
