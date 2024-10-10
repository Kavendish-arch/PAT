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
            cout << "buffer points to : 0x" << hex;
            cout << (unsigned int *)buffer << endl;
            delete[] buffer;
        }
    }
};

MyString::MyString(const char *initString)
{
    buffer = NULL;
    cout << "Default constructor : creating new MyString" << endl;
    if (initString != NULL)
    {
        buffer = new char[strlen(initString) + 1]; // strlen 获取size new 获取内存
        strcpy(buffer, initString);

        cout << "buffer points to : 0x" << hex;
        cout << (unsigned int *)buffer << endl;
    }
    else
    {
        buffer = NULL;
    }
};
MyString::MyString(const MyString &copySource)
{
    buffer = NULL;
    cout << "Copy constructor: copying from mystring" << endl;

    if (copySource.buffer != NULL)
    {
        buffer = new char[strlen(copySource.buffer) + 1];

        strcpy(buffer, copySource.buffer);

        cout << "buffer points to : 0x" << hex;
        cout << (unsigned int *)buffer << endl;
    }
}

// MyString::operator=(const MyString & copySource)
// {
// }

void UseMyString(MyString str)
{
    cout << "String Buffer in MyString is " << str.GetLength();
    cout << "characters long " << endl;

    cout << "Buffer contatins: " << str.GetString() << endl;

    return;
}

MyString Copy(MyString &source)
{
    MyString copyForReturn(source.GetString());

    return copyForReturn;
}

// start of your program: function block main()
int main(int argc, char *argv[])
{

    MyString hum("Hello from String Class");

    // MyString overwrite(Copy(hum));
    MyString overwrite("who cares?");

    overwrite = hum;

    // UseMyString(hum);

    cout << "String Buffer in MyString is " << hum.GetLength() << " characters long ." << endl;
    cout << "Buffer contatins: " << hum.GetString() << endl;

    cout << "String Buffer in MyString is " << hum.GetLength() << "characters long." << endl;
    cout << "Buffer contatins: " << overwrite.GetString() << endl;

    return 0;
}
