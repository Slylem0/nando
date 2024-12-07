#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library library;

    // Add default categories
    library.addCategory("Fiction");
    library.addCategory("Science Fiction");
    library.addCategory("Horror");

    // Add books to the library
    library.addBook(Book("1984", "George Orwell", 1949, "Science Fiction"), "Science Fiction");
    library.addBook(Book("Brave New World", "Aldous Huxley", 1932, "Science Fiction"), "Science Fiction");
    library.addBook(Book("Dracula", "Bram Stoker", 1897, "Horror"), "Horror");
    library.addBook(Book("Frankenstein", "Mary Shelley", 1818, "Horror"), "Horror");
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813, "Fiction"), "Fiction");

    // Menu for user interaction
    int choice;
    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. View all books\n";
        cout << "2. Search books by title\n";
        cout << "3. Search books by author\n";
        cout << "4. Search books by year\n";
        cout << "5. Borrow a book\n";
        cout << "6. Return a book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: { // View all books
            cout << "\nBooks in the library:\n";
            for (const auto& category : library.getCategories()) {
                cout << "Category: " << category.getName() << "\n";
                for (const auto& book : category.getBooks()) {
                    cout << " - " << book.getTitle() << " by " << book.getAuthor()
                         << " (" << book.getPublicationYear() << ") ["
                         << (book.getAvailability() ? "Available" : "Borrowed") << "]\n";
                }
            }
            break;
        }
        case 2: { // Search books by title
            cout << "\nEnter title fragment: ";
            string fragment;
            cin.ignore();
            getline(cin, fragment);
            auto results = library.searchByTitle(fragment);
            cout << "\nSearch results:\n";
            for (const auto& book : results) {
                cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
            break;
        }
        case 3: { // Search books by author
            cout << "\nEnter author fragment: ";
            string fragment;
            cin.ignore();
            getline(cin, fragment);
            auto results = library.searchByAuthor(fragment);
            cout << "\nSearch results:\n";
            for (const auto& book : results) {
                cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
            break;
        }
        case 4: { // Search books by year
            cout << "\nEnter publication year: ";
            int year;
            cin >> year;
            auto results = library.searchByYear(year);
            cout << "\nSearch results:\n";
            for (const auto& book : results) {
                cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
            break;
        }
        case 5: { // Borrow a book
            cout << "\nEnter the title of the book to borrow: ";
            string title;
            cin.ignore();
            getline(cin, title);
            if (library.borrowBook(title)) {
                cout << "\nBook borrowed successfully.\n";
            } else {
                cout << "\nBook not found or already borrowed.\n";
            }
            break;
        }
        case 6: { // Return a book
            cout << "\nEnter the title of the book to return: ";
            string title;
            cin.ignore();
            getline(cin, title);
            if (library.returnBook(title)) {
                cout << "\nBook returned successfully.\n";
            } else {
                cout << "\nBook not found or not borrowed.\n";
            }
            break;
        }
        case 7:
            cout << "\nExiting the system. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
