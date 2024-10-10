#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int x, g, y;
	scanf("%d", &x);
	g = sqrt(x); // ��С����ֵ���������ﵽȡ����Ŀ��
	switch (g)
	{
	case 9:
		y = x + 2;
		break;
	case 8:
		y = 2 * x + 3;
		break;
	case 7:
		y = 2 * x + 4;
		break;
	case 6:
		y = 4 * x + 5;
		break;
	default:
		y = 0;
	}
	if (y == 0)
		printf("�޶���");
	else
		printf("%d", y);

	return 0;
}
