// Preprocessor  directive that includes header iostream
#include <iostream>

using namespace std;

enum CardinalDirecions
{
     North, 
     South,
     East,
     West,
};

// start of your program: function block main()
int main(int argc, char *argv[])
{

     cout << "Displaying directions and their symbolic values: " << endl;

     cout << "North: " << North << endl;
     cout << "South: " << South << endl;
     cout << "East: " << East<< endl;
     cout << "West: " << West << endl;

     CardinalDirecions windDirction = South;
     cout << " variable windDirection = " << windDirction << endl;


     unsigned short byteSize = 0;
     byteSize--;
     cout << byteSize << endl;
     return 0;
}
