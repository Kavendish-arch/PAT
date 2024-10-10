#include <iostream>
#include <string.h>
using namespace std;
/**
 * 不允许被复制的类
 */

class President
{
private:
    /* data */
    President(const President &);
    President &operator=(const President); // private copy assignment operator
    string name;

public:
    President(string sInputName);
    ~President();
};
President::President(string sInputName)
    : name(sInputName)
{
}

President::~President()
{
}
/**
 * 单例模式
 */
class President2
{
private:
    President2();                                   // private default construct
    President2(string sInputName);                  // private default construct
    President2(const President2 &);                 // private copy constructor
    const President &operator=(const President2 &); // assignment operator

    string name;

public:
    static President2 &GetInstance()
    {
        static President2 onlyInstance;
        return onlyInstance;
    }
    string GetName()
    {
        return name;
    }
    void SetName(string sInputName = " ")
    {
        name = sInputName;
    }
    ~President2();
};

President2::President2(string sInputName)
    : name(sInputName)
{
}

President2::~President2()
{
}

// start of your program: function block main()
int main(int argc, char *argv[])
{

    President One("zongtong1"), Two("zongtong2"), Three("zongtong3");

    President One2 = copy(One);
    // cout << hex << (unsigned int *)&One << (unsigned int *)&Two << (unsigned int *)&Three;

    return 0;
}
