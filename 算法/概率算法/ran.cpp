#include <math.h>
#include <stdio.h>


class RandomNumber
{
private:
    double s, t, p, q;
public:
    RandomNumber(/* args */);
    double Norm();
    double Gaussrand();
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
    double s, t, p, q;
    while (true)
    {
        s = 2 * t - 1;
        t = 2 * t - 1; 
        p = s * s + t * t;
        if (p < 1){
            break;
        }
    }
    q = sqrt((-2 * log(p)) / p);
    return s * q;
}
# define NSUM 25
double RandomNumber::Gaussrand()
{
    double x = 0;
    int i = 0;
    for (i = 0; i < NSUM; i++)
    {
        x += (double)rand() /  RAND_MAX;
    }
    x -= NSUM / 2.0;
    x /= sqrt(NSUM / 12.0);
    return x;
}

int main() 
{
    RandomNumber r;
    printf("%f",r.Gaussrand());
    return 0;
}