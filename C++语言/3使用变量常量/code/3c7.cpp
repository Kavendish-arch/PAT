// Preprocessor  directive that includes header iostream
#include <iostream>

using namespace std;

constexpr double GetPi()
{
     return 22.0 / 7;
}
constexpr double TwicePi()
{
     return 2 * GetPi();
}
// start of your program: function block main()
int main(int argc, char *argv[])
{
     const double pi = 22.0 / 7;

     cout << "the value of const pi is : " << pi << endl;

     cout << GetPi() << endl;
     cout << TwicePi() << endl;
     return 0;
}
