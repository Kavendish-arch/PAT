#include <stdio.h>
void main()
{
    int y, m, d, f;
    printf("Input year and month y-m:");
    scanf("%d-%d", &y, &m);
    f = (y % 4 == 0 && y / 100 != 0 || y / 400 == 0); // ������,f�õ�1������f�õ�0
    if (m == 2)
        d = 28 + f;
    else
        d = 31 - ((m == 4) + (m == 6) + (m == 9) + (m == 11)); // �ù�ϵ����ʽ���������
    printf("%d-%d is %d days.\n", y, m, d);
}
