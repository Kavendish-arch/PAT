
class point
{
    int x, y;

public:
    point(/* args */);
    ~point();
    int x, y;
    point(int v1, int v2)
    {
        x = v1;
        y = v2;
    }
    point operator+(point B);
    point operator++(int);
    point operator?: ();
    point operator=(point B);
    point operator=(point B);
    int GetX() { return x; }
    int GetY() { return y; }
}
