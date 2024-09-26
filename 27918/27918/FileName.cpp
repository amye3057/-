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
		if (d == p + 2 || p == d + 2) //경기 진행 도중 누군가가 2점 앞서게 되면 경기가 종료
			break;
	}
	printf("%d:%d", d, p);
	return 0;
}