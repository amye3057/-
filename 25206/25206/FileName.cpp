#include <stdio.h>

int change(char g[3]);

int main() {
	int sum = 0;
	double gradesum = 0;
	for (int i = 0; i < 20; i++) {
		char name[51] = {};
		double point;
		char grade[3] = {};
		scanf_s("%s %f %s", name, 51, &point, grade, 3);
		//printf("%c\n", grade[0]);
		if (grade[0] != 'P') {
			sum += point;
			gradesum += point * change(grade);
			printf("��\n");

		}
		printf("��\n");

	}
	gradesum /= sum;
	printf("%.6lf", gradesum);
	return 0;
}

int change(char g[3]) {
	int s;
	printf("g[0]=%c, ", g[0]);
	switch (g[0]) { //�� ���⼭ g[0]�� A�� ���� s=0�� �Ǵ� ������? case 'A' ���� 65�� �޾ƾ� �ϳ�? �׷� define A�� 65�� �ϰ�..
	case 'A':
		s = 4;
	case 'B':
		s = 3;
	case 'C':
		s = 2;
	case 'D':
		s = 1;
	case 'F':
		s = 0;
	}
	if (g[1] == '+')
		s += 0.5;
	printf("s = %d\n", s);//Ȯ�ο�
	return s;
}
