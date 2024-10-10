// c++ 11
// preprocessordirective that includes header iostream
#include <iostream>
using namespace std;

// start program: function block main();
int main()
{
    // tell the compiler what namesapce to search in 
    // 后者让您能够在不显式指定名称空间限定符 std::的情况下使用 std::cout 和 std::endl
    using std::cout;
    using std::endl;
    /* write to the screen */
    cout << "hello world" << endl;

    return 0;
}