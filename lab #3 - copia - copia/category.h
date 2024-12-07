#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Category {
private:
    string name;
    vector<Book> books;

public:
    // Constructor
    Category(string n);

    // Getters
    string getName() const;

    // Non-const and const version of getBooks()
    vector<Book>& getBooks();  // Non-const version
    const vector<Book>& getBooks() const;  // Const version

    // Methods
    void addBook(const Book& book);
};

#endif
