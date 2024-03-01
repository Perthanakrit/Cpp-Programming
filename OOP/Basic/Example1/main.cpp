#include <iostream>
#include "Book.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Book python; // object
    Book cpp("C++ Programming", 500);
    Book *books[10];

    int total = 0;
    // python.print();
    // cpp.print();

    books[0] = &python;
    books[1] = &cpp;
    books[2] = new Book("Java Programming", 400); // dynamic memory allocation, new ConstructorName()

    python.setTitle("Python Programming");

    for (int i = 0; i < 3; i++)
    {
        books[i]->readMore(i);
        books[i]->print();
        total += books[i]->getTotalPage();
    }

    cout << '\n'
         << "TotalPage:" << total << endl;

    return 0;
}