#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	char a[2] = {}; // int로 해서 계속 오류났음
	double score = 0;
	scanf("%s", a);
	switch (a[0]) {
	case 'A':
		score = 4;
		break;
	case 'B':
		score = 3;
		break;
	case 'C':
		score = 2;
		break;
	case 'D':
		score = 1;
		break;
	case 'F':
		score = 0;
	}

	switch (a[1]) {
	case '+':
		score += 0.3;
		break;
	case '-':
		score -= 0.3;
		break;
	}

	printf("%.1f", score);
}