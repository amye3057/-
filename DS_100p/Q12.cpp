#include <stdio.h>

//구조체를 어떤 식으로 만들라는지를 모르겠다. 1번은 뭘 반환하라는 거지? 게다가 이거 윤년 이런거도 생각해서 만들어야 하나.. 일단 패스

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
	printf("D-DAY 계산기\n");
	int year;
	int month;
	int day;
	printf("연도 : ");
	scanf_s("%d", &year);
	printf("\n월 : ");
	scanf_s("%d", &month);
	printf("\n일 : ");
	scanf_s("%d", &day);

	int x = 0;
	while (1) {
		printf("\n1.이전의 날짜  2.이후의 날짜\n");
		scanf_s("%d", &x);

		printf("\n%d.%d.%d", year, month, day);
		if (x == 1) {

			break;
		}
		else if (x == 2) {

			break;
		}
		else
			printf("올바르지 않은 접근입니다.\n");
	}

	return 0;
}