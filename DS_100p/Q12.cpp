#include <stdio.h>

//����ü�� � ������ ���������� �𸣰ڴ�. 1���� �� ��ȯ�϶�� ����? �Դٰ� �̰� ���� �̷��ŵ� �����ؼ� ������ �ϳ�.. �ϴ� �н�

typedef struct {
	int y;
	int m;
	int d;
} date;

date dateof(int y, int m, int d) {

}

date after(date x, int n) {

}

date before(date x, int n) {

}

int main() {
	printf("D-DAY ����\n");
	int year;
	int month;
	int day;
	printf("���� : ");
	scanf_s("%d", &year);
	printf("\n�� : ");
	scanf_s("%d", &month);
	printf("\n�� : ");
	scanf_s("%d", &day);

	int x = 0;
	while (1) {
		printf("\n1.������ ��¥  2.������ ��¥\n");
		scanf_s("%d", &x);

		printf("\n%d.%d.%d", year, month, day);
		if (x == 1) {

			break;
		}
		else if (x == 2) {

			break;
		}
		else
			printf("�ùٸ��� ���� �����Դϴ�.\n");
	}

	return 0;
}