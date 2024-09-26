#include <stdio.h>
int main()
{
	int x, y, i, a, b;
	x = 900;
	y = 900;

	for (i = 0; i < 10000; i++)
	{
		a = x - (x * 0.1) + (y * 0.05);
		b = y - (y * 0.05) + (x * 0.1);
		x = a;
		y = b;
	}
	printf("x : %d, y : %d\nÃÑÇÕ : %d", x, y, x+y);
	return 0;
}