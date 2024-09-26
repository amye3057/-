#include <stdio.h>
#define start 1

int main() {
	int a, b;
	int c = 1;
	int n = 0;
	int sum = 0;
	scanf_s("%d %d", &a, &b);

	for (int i = start + 1; i < 1002; i++) {
		for (int j = start; j < i; j++) {
			printf("%d ", c);
			n++;
			if (n >= a && n <= b) {
				sum += c;
				if (n == b)
					break;
			}
			else if (n == a && n == b) {
				sum += c;
				break;
			}
			else{}
		}
		c++;
		if (n == a - 1 && a == b) // a와 b가 같은 상황에서, 자꾸 1 전에 break로 루프를 빠져나가서 조건 명시. 
			continue;
		if (n == b) // 위에서 break 되는 조건을 만족시킬 경우 for문 전체 종료.
			break;
	}

	printf("\nsum : %d", sum);

	return 0;
}