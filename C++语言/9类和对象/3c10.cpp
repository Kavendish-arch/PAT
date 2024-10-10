#include <iostream>
#include <string.h>
using namespace std;
/**
 * 移动构造函数
 */
class MyString
{
private:
    char *buffer;

public:
    MyString(const char *initString);
    MyString(const MyString &copySource);
    MyString(MyString &&moveSource);

    int GetLength()
    {
        return strlen(buffer);
    }

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
// moveconstructor
MyString::MyString(MyString &&moveSource)
{
    if (moveSource.buffer != NULL)
    {
        buffer = moveSource.buffer; // take owenership 'move'
        moveSource.buffer = NULL;   // set the moveSource to NULL
    }
}

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
/**
 * 禁止在栈中实例化类
 *
 */
class MonsterDB
{
private:
    string name;
    ~MonsterDB();

public:
    MonsterDB();

    static void DestoryInstance(MonsterDB *pInstance)
    {

        delete pInstance; // member can invoke private destructor;
        cout << "invoke private destructor " << endl;
    }

    void DoSomething() {};
};

MonsterDB::MonsterDB()
{
}

MonsterDB::~MonsterDB()
{
}

// start of your program: function block main()
int main(int argc, char *argv[])
{

    // MyString hum("Hello from String Class");

    // MyString overwrite(Copy(hum));

    // cout << "String Buffer in MyString is " << hum.GetLength() << " characters long ." << endl;
    // cout << "Buffer contatins: " << hum.GetString() << endl;

    // cout << "String Buffer in MyString is " << hum.GetLength() << "characters long." << endl;
    // cout << "Buffer contatins: " << overwrite.GetString() << endl;

    // 在堆上申请空间
    MonsterDB *monsdb = new MonsterDB;
    monsdb->DoSomething();
    /**
     * 3c10.cpp: In function 'int main(int, char**)':
     * 3c10.cpp:143:12: error: 'MonsterDB::~MonsterDB()' is private within this context
     * delete monsdb;
     *        ^~~~~~
     * 3c10.cpp:121:1: note: declared private here
     * MonsterDB::~MonsterDB()
     * ^~~~~~~~~
     */
    delete monsdb;

    MonsterDB::DestoryInstance(monsdb);
    return 0;
}
