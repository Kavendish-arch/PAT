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

enum YourCard
{
     Ace = 43,
     Jack,
     Queen,
     King,
};
// start of your program: function block main()
int main(int argc, char *argv[])
{

     cout << "Displaying directions and their symbolic values: " << endl;

     cout << "North: " << Ace << endl;
     cout << "South: " << Jack<< endl;
     cout << "East: " << Queen<< endl;
     cout << "West: " << King << endl;

     CardinalDirecions windDirction = South;
     cout << " variable windDirection = " << windDirction << endl;


     unsigned short byteSize = 0;
     unsigned int u_iNum = 3;
     int iNum = 3;
     long lNum = 3;
     short sNum = 3;

     cout << " size of unsigned int :" << sizeof(u_iNum) << " size of int : " << sizeof(iNum) << endl;
     cout << " size of unsigned long :" << sizeof(lNum) << " size of short : " << sizeof(sNum) << endl;

     return 0;
}
