/**
 * 暴力匹配
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        // 0 <= rowIndex <= 33
        int num[35][35];
        num[0][0] = 1;
        num[1][0] = 1;
        num[1][1] = 1;
        for (int i = 2; i <= rowIndex; i++)
        {
            num[i][0] = num[i - 1][0];
            for (int j = 1; j <= i; ++j)
            {
                num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
            }
        }

        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i)
        {
            ans.push_back(num[rowIndex][i]);
        }
        return ans;
    }
};

int main()
{
    cout << "hello" << endl;
}