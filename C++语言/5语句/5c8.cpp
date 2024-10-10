#include <iostream>
#include <bitset>
using namespace std;
/**
 * 运算符
 * 1. 赋值=
 * 2.
 *
 */
int main(int argc, char const *argv[])
{

    cout << "Enter a number (0 - 255): ";

    int inputNum = 16;

    int halfNum = inputNum >> 1;
    int quarterNum = inputNum >> 2;
    int doubleNum = inputNum << 1;
    int quadrupleNum = inputNum << 2;
    cout << "Quarter: " << quarterNum << endl;
    cout << "Half: " << halfNum << endl;
    cout << "Double: " << doubleNum << endl;
    cout << "Quadruple: " << quadrupleNum << endl;

    return 0;
}
