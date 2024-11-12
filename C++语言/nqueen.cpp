#include <math.h>
class nqueen
{
private:
    /* data */
    int n = 0;
    int a[n] = {0};

public:
    nqueen(/* args */);
    ~nqueen();
    bool is_place(int k){
        for(int i = 1; i < k; i++)
        {
            if (abs(i - k) == abs(a[i] - a[k]))
            {
                return false;
            }
            if (a[i] == a[k])
            {
                return false;
            }
        }
    }
    int queens(int k){
        for (int i = 1; i <= n; i++)
        {
            a[k] = i;
            if (k != 1 && is_place(k))
            {
                queens(k+1);
                if (k > n){
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
};

nqueen::nqueen(/* args */)
{
}

nqueen::~nqueen()
{
}
