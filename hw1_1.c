#include <stdio.h>

int sum(char a[]) {
	int s = 0;
	for (int i = 0; i < sizeof.a; i++) {
		if (a[i] > 47 && a[i] < 58) { //문자열 중 숫자에 해당하는 아스키코드가 나올시
			int j = 0;
			int n[10] = {};
			do {
				n[j] = a[i];
				j++;
				i++;
			} while (a[i] > 47 && a[i] < 58); //그게 끝나기 전까지 포함
		}
        s += atoi(n); //n 형변환 후 정수화 시켜서 s에 더하기.
	}
	return s;
}

int main() {
	char a[100] = {};
	printf("Input a string: ");
	scanf_s("%s", &a);
	int s = sum(a);
	printf("s");
}