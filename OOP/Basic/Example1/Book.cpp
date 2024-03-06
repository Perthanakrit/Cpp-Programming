#include <iostream>
#include "Book.h"
using namespace std;
using namespace Book;

// :: is scope resolution operator
Book() // default constructor
{
    title = "";
    totalPage = 0;
    read = 0;
}

Book::Book(string title, int totalPage) : title(title), totalPage(totalPage), read(0)
{
}

void Book::print()
{
    cout << title << "(read: " << read << "/" << totalPage << ")" << endl;
}

void Book::readMore(int page)
{
    if (page > 0)
    {
        read = min(read + page, totalPage);
    }
}

string Book::getTitle()
{
    return title;
}

int Book::getTotalPage()
{
    return totalPage;
}

int Book::getRead()
{
    return read;
}

void Book::setTitle(string title)
{
    title = title;
}

string Book::toString()
{
    string result = "";
    result += "Title: " + title + "\n";
    result += "Read: " + to_string(read) + "\n";
    result += "TotalPage: " + to_string(totalPage) + "\n";
    return result;
}