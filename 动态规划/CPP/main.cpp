/*
1049最后一块石头的重量2
*/
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
    }
}
}
;