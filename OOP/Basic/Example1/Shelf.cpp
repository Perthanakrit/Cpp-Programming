#include "Shelf.h"

Shelf::Shelf(int maxSize) : maxBooks(maxSize)
{
    size = 0;
    books = (Book **)malloc(maxSize * sizeof(Book *));
}

int Shelf::addBook()
{
    if (size == maxBooks)
    {
        if
    }
    return 0;
}