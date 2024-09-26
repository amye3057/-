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
			printf("용\n");

		}
		printf("인\n");

	}
	gradesum /= sum;
	printf("%.6lf", gradesum);
	return 0;
}

int change(char g[3]) {
	int s;
	printf("g[0]=%c, ", g[0]);
	switch (g[0]) { //왜 여기서 g[0]이 A가 들어가도 s=0이 되는 것이지? case 'A' 말고 65로 받아야 하나? 그럼 define A는 65로 하고..
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
	printf("s = %d\n", s);//확인용
	return s;
}
