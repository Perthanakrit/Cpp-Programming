# Class

### Encapsulation

- Data member
- Function member

### Defining a class

_ใช้ keyword `class`_

```cpp
class Student {
    public:
    string name;
    int scores[5];

    int GetTotalScore()
    {
        int total = 0;
        int i;
        for (i = 0; i < 5; i++)
        {
            total += scores[i];
        }
        return total;
    }
};
```

## Overload function

- ชื่อเดียวกัน แต่รับ parameter ที่ต่างกัน

```cpp
void ChangeSize(int d) {
    width += d;
    length += d;
}
void ChangeSize(int dw, int dl) {
    width += dw;
    length += dl;
}
```

## Naming Convention

### Type Names

- CamelCase

#### Constant Names

- `k`CamelCase

```cpp
const int kDaysInWeek = 7;
```

## Constructor

### Default Constructor

```cpp
class Student {
    public:
    Student() {
        name = "John Doe";
        scores[0] = 0;
        scores[1] = 0;
        scores[2] = 0;
        scores[3] = 0;
        scores[4] = 0;
    }
    string name;
    int scores[5];
};
```

### Parameterized Constructor

```cpp

```

### Constructor Overloading

```cpp
class Book
{
    public:
    Book() {
        title = "No title";
        author = "No author";
        pages = 0;
    }
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
    string title;
    string author;
    int pages;
};
```
