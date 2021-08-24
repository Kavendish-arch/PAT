#include <stdio.h>
#include <string>
#include <map>
#include <vector>

/**
 * 1        1 
 * 2 1,2    2
 * 3 1 1 1, 1,2, 2,1 3
 * 因为一次只能爬两步，所以，爬n阶 = 爬到 n-1 + 爬到n-2 的方法数之和 
 */
using namespace std;


class Solution {
public:
    // int climbStairs(int n) {
    //     if (n == 1){
    //         return 1;
    //     }
    //     if (n == 2){
    //         return 2;
    //     }
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
    int climbStairs(int n) {
        if (n == 1){
            return 1;
        }
        int * x = (int*) malloc (sizeof(int) * (n + 1));

        for (int i = 0; i < n + 1; i++) {
            x[i] = 1;
        }
        // 1 1  2   3   5   8
        for(int i = 2; i < n + 1; i++){
            // x[i] = x[i-2] + x[i-1];
            x[i] = x[i-1] + x[i-2];
        }
        int ansower = x[n];
        free(x);
        return ansower;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("\n%d",s.climbStairs(5));
    return 0;
}

