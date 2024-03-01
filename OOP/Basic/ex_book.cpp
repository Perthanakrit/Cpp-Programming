struct __Book
{
private:
    string : title;
    int totalPage;
    int read;

public:
    void Construct(string title, int totalPage)
    {
        this->title = title;
        this->totalPage = totalPage;
        this->read = 0;
    }

    void readMore()
    {
    }
};
