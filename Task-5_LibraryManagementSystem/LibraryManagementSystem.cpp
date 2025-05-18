#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

// Structure to store information about each book.
struct Book {
    string title;
    string author;
    string isbn;
    bool isCheckedOut = false;
};

// Structure to store borrower information.
struct Borrower {
    string name;
    vector<string> borrowedISBNs;
};

// Library class encapsulating the database and functions to operate on it.
class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    const int fineRate = 1; // Fine rate per overdue day

public:
    void addBook();
    void searchBook();
    void checkoutBook();
    void returnBook();
    void showBooks();
};

// Function definitions outside class for clarity
void Library::addBook() {
    Book newBook;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter book title: "; getline(cin, newBook.title);
    cout << "Enter author: "; getline(cin, newBook.author);
    cout << "Enter ISBN: "; cin >> newBook.isbn;

    books.push_back(newBook);
    cout << "\n✅ Book added successfully!\n";
}

void Library::searchBook() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter title, author, or ISBN to search: ";
    string key; getline(cin, key);

    for (const auto &book : books) {
        if (book.title.find(key) != string::npos || book.author.find(key) != string::npos || book.isbn == key) {
            cout << "\n🔎 Book Found:\nTitle: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn
                 << " (" << (book.isCheckedOut ? "Checked Out" : "Available") << ")\n";
            return;
        }
    }
    cout << "\n❌ No books found.\n";
}

void Library::checkoutBook() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter ISBN to checkout: "; string isbn; getline(cin, isbn);

    for (auto &book : books) {
        if (book.isbn == isbn) {
            if (book.isCheckedOut) { cout << "\n❌ This book is already checked out.\n"; return; }
            book.isCheckedOut = true;
            cout << "\n✅ Book checked out successfully!\n";
            return;
        }
    }
    cout << "\n❌ Book not found.\n";
}

void Library::returnBook() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter ISBN to return: "; string isbn; getline(cin, isbn);

    for (auto &book : books) {
        if (book.isbn == isbn) {
            if (!book.isCheckedOut) { cout << "\nThis book is already in the library.\n"; return; }
            book.isCheckedOut = false;

            char overdue; cout << "Was the book overdue? (y/n): "; cin >> overdue;
            if (overdue == 'y' || overdue == 'Y') {
                int days; cout << "Enter number of overdue days: "; cin >> days;
                cout << "Total fine: ₹" << (days * fineRate) << "\n";
            }
            cout << "\n✅ Book returned successfully!\n";
            return;
        }
    }
    cout << "\n❌ Book not found.\n";
}

void Library::showBooks() {
    cout << "\n📚 Available Books:\n";
    if (books.empty()) { cout << "No books in the library.\n"; return; }

    for (const auto &book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn
             << " (" << (book.isCheckedOut ? "Checked Out" : "Available") << ")\n";
    }
}

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Show Books\n6. Exit\n";
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.searchBook(); break;
            case 3: lib.checkoutBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.showBooks(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

