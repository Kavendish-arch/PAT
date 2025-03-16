#include <cstdio>
const int maxn = 100;
int n, V, maxValue = 0;
int w[maxn], v[maxn];
void DFS(int index, int sumW, int sumC)
{

    if (index == n)
    {
        return;
    }
    DFS(index + 1, sumW, sumC);
    if (sumW + w[index] > V)
    {
        return;
    }
    else
    {
        if (sumC + v[index] > maxValue)
        {
            maxValue = sumC + v[index];
        }
        DFS(index + 1, sumW + w[index], sumC + v[index]);
    }
    // if (index == n)
    // {
    //     if (sumW <= V && sumC > maxValue)
    //     {
    //         maxValue = sumC;
    //     }
    //     return
    // }
}

// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//     }
// };
