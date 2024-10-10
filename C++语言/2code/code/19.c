#include <stdio.h>
void main()
{
    float score;
    scanf("%f", &score);
    if (score < 60)
        printf("%c", 'E');
    else if (score < 70)
        printf("%c", 'D');
    else if (score < 80)
        printf("%c", 'C');
    else if (score < 90)
        printf("%c", 'B');
    else
        printf("%c", 'A');
}
