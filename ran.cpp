#include <math.h>
class RandomNumber
{
private:
    double s, t, p, q;
public:
    RandomNumber(/* args */);
    double Norm();
    ~RandomNumber();
};

RandomNumber::RandomNumber(/* args */)
{
}

RandomNumber::~RandomNumber()
{
}

double RandomNumber::Norm()
{
    while (true)
    {
        // s = 2 * Random() - 1;
        t = 2 * 
        p = s * s + t * t;
        if (p < 1){
            break;
        }
    }
    q = sqrt((-2 * log(p)) / p);
    return s * q;
}