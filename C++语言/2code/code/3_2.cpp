// Preprocessor  directive that includes header iostream
#include <iostream>

using namespace std;


int MultiplyNumbers(){
    cout << "Enter an integer: ";
    int inputNumber;
    cin >> inputNumber;
    
    cout << "Enter an integer: ";
    int secondNumber;
    cin >> secondNumber;

    int multiplicationResult = inputNumber * secondNumber; 

}

// start of your program: function block main()
int main(int argc, char * argv[])
{
    cout << "Ennter two Numbers;"  << endl;
    MultiplyNumbers();
    cout << inputNumber << " x " << secondNumber << " = " << multiplicationResult << endl;
    return 0;
}

