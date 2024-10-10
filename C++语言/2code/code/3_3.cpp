// Preprocessor  directive that includes header iostream
#include <iostream>

using namespace std;

int inputNumber;
int secondNumber;
int multiplicationResult = 0;

int MultiplyNumbers(){
    cout << "Enter an integer: ";
    cin >> inputNumber;
    
    cout << "Enter an integer: ";
    cin >> secondNumber;

    multiplicationResult = inputNumber * secondNumber; 

}

// start of your program: function block main()
int main(int argc, char * argv[])
{
    cout << "Ennter two Numbers;"  << endl;
    MultiplyNumbers();
    cout << inputNumber << " x " << secondNumber << " = " << multiplicationResult << endl;
    return 0;
}

