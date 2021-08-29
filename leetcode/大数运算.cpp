#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>

/**
 * 1        1 
 * 2 1,2    2
 * 3 1 1 1, 1,2, 2,1 3
 * 因为一次只能爬两步，所以，爬n阶 = 爬到 n-1 + 爬到n-2 的方法数之和 
 */
using namespace std;

typedef struct _bign{
    int array[1000];
    int len;
    _bign() {
        memset(array, 0, sizeof(array));
        len = 0;
    }    
} bign;

class Solution {
public:
    bign add(bign a, bign b){
        bign c;
        int len = a.len > b.len ? a.len : b.len;
        int carry = 0;
        for (int i = 0; i < len; i++){
            int tmp = a.array[i]+ b.array[i];
            c.array[i] += tmp % 10 + carry;
            carry = tmp / 10;
        }
        return c;
    }
    vector<int> char2int(vector<char> chs) {
        vector<int> result;
        for (int i = 0; i < chs.size(); i++){
            if (chs[i] >= '0' && chs[i] <= '9'){
                result.push_back(chs[i] - '0');
            }
        }
        return result;
    }
    vector<char> char2int(vector<int> chs) {
        vector<char> result;
        for (int i = 0; i < chs.size(); i++){
            if (chs[i] >= 0 && chs[i] <= 9){
                result.push_back(chs[i] + '0');
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    bign a,b;
    // a.array = {1,2,3,4,5,6};
    // b.array = {2,3,4,6,2,8};
    bign c;
    c = s.add(a,b);
    // printf("%d%d", c.in_carry, c.in_low);
    return 0;
}

