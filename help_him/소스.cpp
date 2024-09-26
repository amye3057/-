#include <stdio.h>
int main()
{
	int i, n, sum = 0;
	scanf("%d", &n);
	i = 0;
	while (i < n)
	{
		i++;
		if (i % 2 == 1)
			continue;
		sum += i;
	}
	printf("정수 1에서 %d 이하 짝수들의 합은 %d 입니다.", n, sum);
	return 0;
}