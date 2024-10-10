// Preprocessor  directive that includes header iostream
#include <iostream>
#include <cmath>

using namespace std;

constexpr double GetPi() { return 22.0 / 7; }

const double pi = M_PI;

// start of your program: function block main()
int main(int argc, char *argv[])
{

     cout << "Displaying directions and their symbolic values: " << endl;

     int radius = 0;
     cout << "Enter radius: " << endl;
     cin >> radius;

     // int iCircumference = 0;
     // int iArea = 0;

     double dCircumference = 0, dArea = 0;

     // iCircumference = GetPi() * radius * 2;
     // iArea = GetPi() * radius * radius;
     
     dCircumference = pi * radius * 2;
     dArea = pi * radius * radius;

     cout << "circumference: " << dCircumference << " area : " << dArea << endl;

     auto Integer;
     return 0;
}
