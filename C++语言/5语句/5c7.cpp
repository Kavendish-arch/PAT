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
    short inputNum = 181;
    // cin >> inputNum;

    bitset<8> inputBits(inputNum);
    cout << inputNum << " in binary is " << inputBits << endl;

    bitset<8> bitwiseNOT = (~inputNum);
    cout << "Logical NOT ~" << endl;
    cout << "~" << inputBits << " = " << bitwiseNOT << endl;

    cout << "Logical AND, & with 00001111" << endl;
    bitset<8> bitwiseAND = (0x0F & inputNum); // 0x0F is hex for 0001111
    cout << "0001111 & " << inputBits << " = " << bitwiseAND << endl;

    cout << "Logical OR, | with 00001111" << endl;
    bitset<8> bitwiseOR = (0x0F | inputNum);
    cout << "00001111 | " << inputBits << " = " << bitwiseOR << endl;

    cout << "Logical XOR, ^ with 00001111" << endl;
    bitset<8> bitwiseXOR = (0x0F ^ inputNum);
    cout << "00001111 ^ " << inputBits << " = " << bitwiseXOR << endl;

    return 0;
}
