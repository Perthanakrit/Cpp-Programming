#ifndef BOOK_h
#define BOOK_h

#include <iostream>
#include "Shelf.h"
using namespace std;

class Shelf
{
private:
    Book **books;
    int maxBooks;
    int size;
}

#endif