#include <iostream>
#include <vector>
#include <string>

using namespace std;
const string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution
{
public:
    vector<string> ans;
    string s;
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return ans;
        }

        int len = digits.length();
        for (int i = 0; i < digits.length(); i++)
        {
            if (digits[i] >= '2' && digits[i] <= '9')
            {
                for (char c : keypad[digits[i] - '0'])
                {
                    s.push_back(c);
                    backtrack(digits, s, i + 1, len);
                    s.pop_back();
                }
            }
            else
            {
                len--;
            }
        }
        return ans;
    }

    void backtrack(string &digits, string &s, int i, int len)
    {
        if (s.length() == len)
        {
            ans.push_back(s);
            return;
        }
        if (digits[i] >= '2' && digits[i] <= '9')
        {
            for (char c : keypad[digits[i] - '0'])
            {
                s.push_back(c);
                backtrack(digits, s, i + 1, len);
                s.pop_back();
            }
        }
        else
        {
            len--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::string> result = s.letterCombinations("23");

    for (const std::string &str : result)
    {
        cout << str << " ";
    }
    return 0;
}
