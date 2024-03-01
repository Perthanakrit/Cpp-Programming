#ifndef BOOK_h
#define BOOK_h

#include <iostream>
using namespace std;

class Book
{
private: // hided data member
    string title;
    int totalPage;
    int read;

public:     // public member function (method)
    Book(); // default constructor
    Book(string, int);
    void print(); // lowerCamelCase
    void readMore(int);

    // Getter, Accessor
    string getTitle();
    int getTotalPage();
    int getRead();

    // Setter, Mutator
    void setTitle(string);

    // toString
    string toString();
};

#endif