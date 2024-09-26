#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	int** c = (int**)calloc(a, sizeof(int));
	for (int i = 0; i < a; i++) {
		c[i] = (int*)calloc(b, sizeof(int));
		for (int j = 0; j < b; j++) {
			scanf_s("%s", c[i][j]);
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) { //4개의 조합 T,C,G,A로 이루어질 수 있다. 즉 각각의 문자에 맞는 번호 아스키코드.. 배열 안에 수가 들어가게 해서 제일 많은 거 당첨.

		}
	}
	
}