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

or

`explicit` keyword ใช้กับ constructor ที่มี parameter มากกว่า 1 ตัว

```cpp
class Book
{
    public:
    explicit Book(string t, string a = "No author", int p = 0) {
        title = t;
        author = a;
        pages = p;
    }
    string title;
    string author;
    int pages;
};
```

## Access Modifier

- Data member ควรเป็น **private**
- Constructor และ member function ส่วนใหญ่เป็น **public**

### Getter and Setter

```cpp
class Student
{
    private:
        string name;
        int scores[5];

    public:
    string GetName() {
        return name;
    }
    void SetName(string n) {
        name = n;
    }
    int GetScore(int i) {
        return scores[i];
    }
    void SetScore(int i, int s) {
        scores[i] = s;
    }
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

### Operator Overloading

```cpp
class Complex
{
    double real;
    double imag;

    public:
    Complex() {
        real = 0;
        imag = 0;
    }
    Complex(double r, double i) {
        real = r;
        imag = i;
    }
    Complex &operator+(Complex &c1) {
        double w = width + c1.width;
        double l = length + c1.length;

        Rectangle r3(w, l);

        return r3;
    }

    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << " + " << c.imag << "i";
        return out;

    }

};

int main()
{
    Complex c1(3, 4);
    Complex c2(2, 3);

    cout << "c1" << c1 << endl;

    //Complex c3;
    //c3 = c1 + c2;
    //cout << c3.real << " + " << c3.imag << "i" << endl;
    return 0;
}

```

## Object Handles

- Object **name**
- Object **reference**
- Object **pointer**

### Object Reference

การประกาศ reference จะใช้ `&` ตามหลัง type

```cpp
BankAccount account1(1,500);
BankAccount &accountRef = account1;
```

จากโค้ด​จะมี 1 object 2 ชื่อ คล้่ายๆ เป็นการ copy ค่าของ object มาให้ชื่อใหม่

### Object Pointer

```cpp
BankAccount account1(1,500);
BankAccount *accountPtr = &account1;
accountPtr->Deposit(100);
```

## Composition

### การสร้าง object ใหม่จาก class อื่น

## Polymorphism

ใช้เมื่อมี function ที่มีชื่อเหมือนกัน แต่รับ parameter มีการทำงานที่ต่างกัน

#### Virtual

ทำให้ sub class สามารถ override function ของ base class ได้
**เพื่อเปลี่ยนการทำงาน**

### Pure Virtual

```cpp
class Shape
{
    public:
    virtual void Draw() = 0;
};
```

**เพื่อให้ sub class ทำงานเอง**

#### Implementation

```cpp
class Circle : public Shape
{
    public:
    void Draw() {
        cout << "Draw a circle" << endl;
    }
};

class Rectangle : public Shape
{
    public:
    void Draw() {
        cout << "Draw a rectangle" << endl;
    }
};
```

นำไปใช้

```cpp
int main()
{
    Shape *circle = new Circle();
    Shape *rectangle = new Rectangle();

    circle->Draw();
    rectangle->Draw();
    return 0;
}
```

การเรียกใช้ function มี 2 ขั้นตอน

1. ตรวจสอบว่า สามารถเรียกใช้ function ได้หรือไม่ โดยดูจาก static type ว่ามี function นี้หรือไม่
2. ผ่านขั้นที่ 1 เรียกได้ จะตรวจสอบว่า จะเรียก function ของ object ประเภทไหน โดยดูจาก dynamic type จะเรียก function ของ object ประเภทนั้น ตามที่ pointer หรือ reference ชี้ไป
