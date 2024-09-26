#include <stdio.h>
#define swap(type,x,y) do {type t=x; x=y; y=t;} while(0)

void reverse(char arr[], int n) {
	for (int i = 0; i < n/2; i++) {
		swap(char, arr[i], arr[n - i - 1]);
		//printf("a[%d]<->a[%d] : %d <-> %d\n", i, n - i - 1, arr[i], arr[n - i - 1]);
	}
}

void change(int x, int n, char arr[]) {
	int i = 0;
	char jin[] = ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	while (x / n > 0) {
		arr[i] = jin[x % n];
		printf("%d | %7d *** %c\n", n, x, jin[x % n]);
		printf("  + -------\n");
		x = x / n;
		i++;
	}
	arr[i] = jin[x];
	printf("arr[%d] = %d\n", i, arr[i]);
	printf("%d | %7d *** %c\n", n, x, jin[x]);
	printf("  + -------\n%11d\n",0);

	reverse(arr, i+1);
	printf("%d������ ", n);
	for (int j = 0; j < i+1; j++) {
		printf("%c", arr[j]);
	}
	printf("�Դϴ�.\n");
}

int main_b() {
	int n;
	int play = 1;
	char arr[512];
	while (play) {
		int x = -1;
		printf("10������ ��� ��ȯ�մϴ�.\n");
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		while (x < 0)
			scanf_s("%d", &x);
		printf("� ������ ��ȯ�ұ��?(2-36) : ");
		scanf_s("%d", &n);

		change(x, n, arr);
		printf("�� �� �� �ұ��?(1 *** ��/0 *** �ƴϿ�) : ");
		scanf_s("%d", &play);
	}
	return 0;
}