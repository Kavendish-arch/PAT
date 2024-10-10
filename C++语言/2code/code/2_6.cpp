// Preprocessor  directive that includes header iostream
#include <iostream>

using namespace std;

// start of your program: function block main()
int main(int argc, char * argv[])
{
    int inputNumber;
    cout << "Enter an integer: ";

    cin >> inputNumber;

    cout << "Enter your name: ";
    string inputName;
    
    // getline();
    cin >> inputName;

    cout << inputName << " entered " << inputNumber << endl;
    return 0;
}

