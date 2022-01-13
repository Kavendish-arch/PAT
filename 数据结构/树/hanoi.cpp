#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        if(A.size() == 1)
        {
            C.push_back(A.back());
            A.pop_back();
        }
        else
        {
            B.push_back(A.back());
            A.pop_back();
            hanota(A, B, C);

            C.push_back(A.back());
            A.pop_back();

            C.push_back(B.back());
            B.pop_back();
            hanota(A, B, C);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A;
    for(int i = 0; i < 3;i++)
    {
        A.push_back(i);
    }
    vector<int> B;
    vector<int> C;

    Solution s;
    s.hanota(A,B,C);
    cout << A.size() << " " << C.size() << endl;
    for(vector<int>::iterator it = C.begin(); it != C.end(); it++)
    {
        printf("%d",it);
    }
    return 0;
}
