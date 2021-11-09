
#include <iostream>

using namespace std;

const int maxn = 100010;
bool hashTbale[maxn] = {false};
int main(int argc, char const *argv[])
{
    int n, m ,x;
    scanf("%d,%d")
    return 0;
}

int hash_Func(char s[], int len){
    int id = 0;
    for(int i = 0;i < len; i++){
        id = id * 26 + (s[i] - 'A');
    }
}
