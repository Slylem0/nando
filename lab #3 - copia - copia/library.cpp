#include "Library.h"
#include <algorithm>

// Add category to library
void Library::addCategory(const string& name) {
    categories.push_back(Category(name));
}

// Add a book to the library under a specified category
void Library::addBook(const Book& book, const string& categoryName) {
    auto it = find_if(categories.begin(), categories.end(), [&](Category& c) {
        return c.getName() == categoryName;
    });

    if (it != categories.end()) {
        it->addBook(book);
    } else {
        Category newCategory(categoryName);
        newCategory.addBook(book);
        categories.push_back(newCategory);
    }
}

// Search books by title
vector<Book> Library::searchByTitle(const string& fragment) {
    vector<Book> results;
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getTitle().find(fragment) != string::npos) {
                results.push_back(book);
            }
        }
    }
    return results;
}

// Search books by author
vector<Book> Library::searchByAuthor(const string& fragment) {
    vector<Book> results;
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getAuthor().find(fragment) != string::npos) {
                results.push_back(book);
            }
        }
    }
    return results;
}

// Search books by year
vector<Book> Library::searchByYear(int year) {
    vector<Book> results;
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getPublicationYear() == year) {
                results.push_back(book);
            }
        }
    }
    return results;
}

// Borrow a book
bool Library::borrowBook(const string& title) {
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getTitle() == title && book.getAvailability()) {
                book.borrow();
                return true;
            }
        }
    }
    return false;
}

// Return a book
bool Library::returnBook(const string& title) {
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getTitle() == title && !book.getAvailability()) {
                book.returnBook();
                return true;
            }
        }
    }
    return false;
}

// Get all categories
const vector<Category>& Library::getCategories() const {
    return categories;
}
