/**
 * 你在进行一个简化版的吃豆人游戏。你从 [0, 0] 点开始出发，你的目的地是 target = [xtarget, ytarget] 。地图上有一些阻碍者，以数组 ghosts 给出，第 i 个阻碍者从 ghosts[i] = [xi, yi] 出发。所有输入均为 整数坐标 。

每一回合，你和阻碍者们可以同时向东，西，南，北四个方向移动，每次可以移动到距离原位置 1 个单位 的新位置。当然，也可以选择 不动 。所有动作 同时 发生。

如果你可以在任何阻碍者抓住你 之前 到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱成功。

只有在你有可能成功逃脱时，输出 true ；否则，输出 false 。
 */
#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int> >& ghosts, vector<int>& target) {
        int distance = abs(target[0] - 0) + abs(target[1]);
        
        for (vector<vector<int> > :: iterator it = ghosts.begin(); it != ghosts.end(); it ++){
            printf("%d, %d\n", (*it)[0], (*it)[1]);
            int tmp_distance = abs((*it)[0] - target[0]) + abs((*it)[1] - target[1]);
            if (tmp_distance <= distance){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s ;
    vector<vector<int> > ghosts;
    vector<int> target;
    target.push_back(0);
    target.push_back(5);
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    ghosts.push_back(a);
    a.clear();
    a.push_back(2);
    a.push_back(3);
    ghosts.push_back(a);
    a.clear();
    a.push_back(8);
    a.push_back(3);
    ghosts.push_back(a);
    s.escapeGhosts(ghosts,target);
    return 0;
}
