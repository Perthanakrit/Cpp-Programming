#include <iostream>
#include "Media.h"
using namespace std;

Media::Media(string title)
{
    this->title = title;
    this->sizeInBytes = 0;
}

string Media::getTitle()
{
    return title;
}

int Media::getSizeInBytes()
{
    return sizeInBytes;
}

double Media::getSeizeInKB()
{
    return sizeInBytes / 1024.0;
}
