#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Category.h"
using namespace std;

class Library {
private:
    vector<Category> categories;

public:
    // Add category
    void addCategory(const string& name);

    // Add book
    void addBook(const Book& book, const string& categoryName);

    // Search books
    vector<Book> searchByTitle(const string& fragment);
    vector<Book> searchByAuthor(const string& fragment);
    vector<Book> searchByYear(int year);

    // Borrow and return books
    bool borrowBook(const string& title);
    bool returnBook(const string& title);

    // Get categories
    const vector<Category>& getCategories() const;
};

#endif
