#include <stdio.h>

int main() {
	int n;
	int d = 0, p = 0;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char a;
		scanf_s("%c", &a);
		getchar();
		if (a == 'D')
			d++;
		else if (a == 'P')
			p++;
		else {}
		if (d == p + 2 || p == d + 2) //��� ���� ���� �������� 2�� �ռ��� �Ǹ� ��Ⱑ ����
			break;
	}
	printf("%d:%d", d, p);
	return 0;
}