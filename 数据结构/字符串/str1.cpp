#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int P = 10000018;

long long
hashFunc(string str)
{
    long long resHash = 0;
    for (int i = 0; i < str.length(); i++)
    {
        //
        resHash = (resHash * P + (str[i] - 'a')) % MOD;
    }
    return resHash;
}

int main(int argc, char const *argv[])
{
    vector<long long> ans;
    string str;
    while (getline(cin, str), str != "#")
    {
        long long id = hashFunc(str);
        ans.push_back(id);
    }
    sort(ans.begin(), ans.end());
    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 || ans[i] != ans[i - 1])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
