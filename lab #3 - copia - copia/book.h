#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;
    string category;
    bool isAvailable;

public:
    // Constructor
    Book(string t, string a, int year, string cat);

    // Getters
    string getTitle() const;
    string getAuthor() const;
    int getPublicationYear() const;
    string getCategory() const;
    bool getAvailability() const;

    // Status methods
    void borrow();
    void returnBook();
};

#endif
