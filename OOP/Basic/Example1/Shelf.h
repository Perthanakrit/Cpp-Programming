#ifndef Shelf_h
#define Shelf_h

#include <iostream>
#include "Book.h"
using namespace std;

class Shelf
{
private:
    Book **books;
    int maxBooks;
    int size;

public:
    Shelf(int);
    void addBook();
    void totalPages();
    int getSize();
    int getMaxBooks();
    void readMore(string, int);
};

#endif