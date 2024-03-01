## Destructor

```cpp
class Book
{
    public:
    Book() {

    }
    ~Book() {
        cout << "Object is destroyed" << endl;
    }
};
```

Destructor จะถูกเรียกในลําดับที่กลับกันกับลําดับ constructor
