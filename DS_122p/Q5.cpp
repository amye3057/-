#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	do {
		int pc = (pl + pr) / 2; //����ؼ� �߰����� �ٲ��� �ϴϱ�
		if (a[pc] == key)
			return pc;
		else if (a[pc] > key)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);
	return -1; //����
}

int main() {
	int nx, ky;
	printf("�����˻�\n ��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);

	int i = 1;
	while (i < nx) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
		if (x[i]>x[i-1]) {
			i++;
		}
		else
			printf("���� �Էº��� ū ���� �Է����ּ���.\n");
	}

	printf("�˻��� : ");
	scanf_s("%d", &ky);
	int s = bin_search(x, nx, ky);
	if (s == -1)
		printf("�˻��� �����߽��ϴ�.");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�.", ky, s);

	free(x);
	return 0;
}