#include "Book.h"

// Constructor
Book::Book(string t, string a, int year, string cat)
    : title(t), author(a), publicationYear(year), category(cat), isAvailable(true) {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getPublicationYear() const { return publicationYear; }
string Book::getCategory() const { return category; }
bool Book::getAvailability() const { return isAvailable; }

// Status methods
void Book::borrow() { isAvailable = false; }
void Book::returnBook() { isAvailable = true; }
