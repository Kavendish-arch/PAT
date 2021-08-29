#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
/**
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:
输入: "race a car"
输出: false
解释："raceacar" 不是回文串
提示：

1 <= s.length <= 2 * 105
字符串 s 由 ASCII 字符组成
通过次数266,569提交次数562,456

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

1. 只判断数字、字母 '0' - '9' 'a'-'z' 'A'-'Z'
48 - 57 
65 - 90 
97 - 122

2. 不区分大小写


 */
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> chs;
        for (char ch : s){
            if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                // printf("%c",ch);
                if (ch >= 'A' && ch <= 'Z'){
                    ch = ch - 'A' + 'a';
                }
                chs.push_back(ch);
            }
        }
        vector<char> chs_bak;
        chs_bak = chs;
        reverse(chs_bak.begin(), chs_bak.end());
        for (int i = 0; i < chs.size(); i++){
            if (chs_bak[i] != chs[i]) {
                return false;
            }
        } 
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    printf("%d\n",s.isPalindrome(str));
    return 0;
}

