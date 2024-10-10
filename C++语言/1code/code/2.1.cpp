// c++ 11
// preprocessordirective that includes header iostream
#include <iostream>


// start program: function block main();
int main()
{
    // tell the compiler what namesapce to search in 
    // 前者让您能够在不显式指定名称空间限定符 std::的情况下使用名称空间 std 中的所有元素（cout、cin 等）
    using namespace std;
    /* write to the screen */
    cout << "hello world" << endl;

    return 0;
}