// c++ 11
// preprocessordirective that includes header iostream
#include <iostream>
using namespace std;

// start program: function block main();
int main()
{
    int x = 8;
    int y = 6;

    std::cout << std::endl;
    std::cout << x - y << " " << x * y << " " << x + y;
    std::cout << std::endl;

    return 0;
}