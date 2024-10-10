#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
private:
    char *buffer;

public:
    MyString(const char *initString);
    MyString(const MyString &copySource);

    int GetLength() { return strlen(buffer); }

    const char *GetString() { return buffer; }

    ~MyString()
    {
        cout << "Invoking destructor, clearing up" << endl;
        if (buffer != NULL)
        {
            delete[] buffer;
        }
    }
};

MyString::MyString(const char *initString)
{
    if (initString != NULL)
    {
        buffer = new char[strlen(initString) + 1]; // strlen 获取size new 获取内存
        strcpy(buffer, initString);
    }
    else
    {
        buffer = NULL;
    }
};
MyString::MyString(const MyString &copySource)
{
    buffer = NULL;
    cout << "Copy constructor: copying from mystring" << enld;

    if (copySource.buffer != NULL)
    {
        buffer = new char[strlen(copySource.buffer) + 1];

        strcpy(buffer, copySource.buffer);

        cout << "buffer points to : 0x" << hex;
        cout << (unsigned int *)buffer << endl;
    }
}

void UseMyString(MyString str)
{
    cout << "String Buffer in MyString is " << str.GetLength();
    cout << "characters long " << endl;

    cout << "Buffer contatins: " << str.GetString() << endl;

    return;
}

// start of your program: function block main()
int main(int argc, char *argv[])
{

    MyString hum("Hello from String Class");

    UseMyString(hum);

    cout << "String Buffer in MyString is " << hum.GetLength();
    cout << "characters long " << endl;
    cout << "Buffer contatins: " << hum.GetString() << endl;
    return 0;
}
