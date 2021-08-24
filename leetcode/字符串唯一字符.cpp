#include <stdio.h>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> hash_char; 
        char tmp = '0';
        for (string::iterator it = s.begin(); it != s.end(); it++){
            hash_char[*it] ++;
        }

        for (map<char, int> :: iterator it2 = hash_char.begin();
        it2 != hash_char.end(); it2++){
            printf("%c, %d\t", it2->first, it2->second);
            if(it2->second == 1){
                printf("%c\n", it2->first);
                // return 0;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string num = "leetcode";
    s.firstUniqChar(num);
    return 0;
}

