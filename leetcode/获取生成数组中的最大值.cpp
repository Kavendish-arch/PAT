#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    int getMaximumGenerated(int n) {
        int num[101];
        for (int i = 0; i < 101; i++) {
            num[i] = 0;
        }
        int max = 0;
        num[0] = 0;
        num[1] = 1;
        for (int i = 1; i <= n; i++) {
            if(i * 2 >= 2 && i * 2 <= n) {
                num[i * 2] = num[i];
            }
            if(i * 2 + 1 >= 2 && i * 2 + 1 <= n) {
                num[i * 2 + 1] = num[i] + num[i + 1];
            }

            if (num[i] > max) {
                max = num[i];
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d",s.getMaximumGenerated(8));
    int max = (1 << 31) - 1;
    int min = -(1 << 31);
    printf("\n%d, %d",max, min);
    printf("\n%d, %d",1 << 1, 1 << 2 );
    return 0;
}

