#include "Category.h"

// Constructor
Category::Category(string n) : name(n) {}

// Getters
string Category::getName() const { return name; }

// Non-const version of getBooks
vector<Book>& Category::getBooks() {
    return books;
}

// Const version of getBooks
const vector<Book>& Category::getBooks() const {
    return books;
}

// Add a book to the category
void Category::addBook(const Book& book) {
    books.push_back(book);
}
