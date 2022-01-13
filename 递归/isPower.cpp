/**
 * @brief 
 * 位运算 求幂 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPowerOfTwo(int n){
    if(n == 1)
    {
        return true;
    }
    if(n % 2 == 0)
    {
        return isPowerOfTwo(n / 2);
    }
    else
    {
        return false;
    }
}
/**
 * @brief 
 * 快速幂算法 
 * @param x 
 * @param n 
 * @return double 
 */
double myPow(double x, int n){ 
    
    return n >= 0 ? quickPow(x, n) : 1 / quickPow(x, -n);

}

double quickPow(double x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        int tmp = quickPow(x, n/2);
        return n%2 == 0 ? tmp*tmp : tmp*tmp*x;
    }
}