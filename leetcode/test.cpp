#include <stdio.h>

int main(int argc, char const *argv[])
{
    float x = 23.23;
    long y1;
    float y2;

    y1 = *(long *)&x;
    y2 = *(float *)&x;

    printf("%ld, %f", y1, y2);
    return 0;
}
