#include <stdio.h>
#define EYEMAX 21

typedef struct {
	char name[20];
	int height;
	double vision;
} PC;

//���Ű
double ave_h(const PC a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i].height;
	}
	return sum / n;
}

//�÷� ����
void eye(const PC a[], int n, int b[]) {
	for (int i = 0; i < EYEMAX; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		b[(int)(a[i].vision * 10)]++;
	}
}

int main_a() {
	PC x[] = {
		{"������", 160, 0.1},
		{"�ռ���", 180, 1.0},
		{"����ǥ", 170, 0.5},
		{"����", 173, 0.7},
		{"���缮",177, 0.3},
		{"���ӽ�", 190, 1.6},
		{"�Ƹ��", 188, 1.2},
		{"�ź���",159, 1.0}
	};

	int n = sizeof(x) / sizeof(x[0]);

	for (int i = 0; i < n; i++) {
		printf("%s %d %.1f\n", x[i].name, x[i].height, x[i].vision);
	}
	printf("���Ű : %.2f\n", ave_h(x, n));

	int e[EYEMAX];
	eye(x, n, e);

	printf("�÷� ����\n");
	for (int i = 0; i < EYEMAX; i++) {
		printf("%.1f~ : ", i*0.1);
		for (int j = 0; j < e[i]; j++)
			printf("*");
		printf("\n");
	}
	return 0;

}