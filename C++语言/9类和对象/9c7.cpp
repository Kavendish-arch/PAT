// Preprocessor  directive that includes header iostream
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Human
{
private:
     // private member data;
     int age;
     char *buffer;
     /* data */
public:
     string name;
     void IntroduceSelf()
     {
          cout << "I am " + name << " and I am ";
          cout << age << " years old" << endl;
     }
     Human(/* args */);
     Human(string sInputName);
     Human(string sInputName, int iInputAge = 0)
         : name(sInputName), age(iInputAge) {};
     Human(const char *initString);
     ~Human();

     void SetAge(int hummanAge)
     {
          if (hummanAge > 0)
          {
               age = hummanAge;
          }
     }

     int GetAge()
     {

          if (age > 30)
          {
               return 18;
          }
     }
     int GetLenth()
     {
          return strlen(buffer);
     }
     const char *GetString()
     {
          return buffer;
     }
};

Human::Human(/* args */)
{
     age = 1;
     name = "weizhi";
     cout << "Constructed an instance of class Human. " << endl;
}
Human::Human(string sInputName)
    : name(sInputName), age(1)
{
     // age = 1;
     // name = sInputName;
     cout << "Constructed an instance of class Human. " << sInputName << endl;
}
// Human::(string sInputName, int iInputAge = 0)
// {
//      age = iInputAge;
//      name = sInputName;
//      cout << "Constructed an instance of class Human. " << sInputName << " age = " << iInputAge << endl;
// }
Human::Human(const char *initString)
    : name("weizhi"), age(0)
{
     if (initString != NULL)
     {
          buffer = new char[strlen(initString) + 1];// strlen 获取size new 获取内存
          strcpy(buffer, initString);
     }
     else
     {
          buffer = NULL;
     }
}
Human::~Human()
{
     cout << "Invoking destructor, clearing up" << endl;
     if (buffer != NULL)
     {
          delete[] buffer;
     }
}

// start of your program: function block main()
int main(int argc, char *argv[])
{

     Human hum("Hello from String Class");
     cout << "String buffer in hum lonth : " << hum.GetLenth() << endl;
     cout << "String buffer in hum string : " << hum.GetString() << endl;

     return 0;
}
