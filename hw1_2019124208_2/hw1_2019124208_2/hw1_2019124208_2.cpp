#include <stdio.h>

char* concat(char c1[], char c2[]) {
	char c3[200] = {};
	int j = 0;
	for (int i = 0; c1[i] != 0; i++) {
		c3[i] = c1[i];
		j++;
	}
	for (int i = 0; c2[i] != 0; i++) {
		c3[j] = c2[i];
		j++;
	}
	return c3;
}

int main() {
	char s1[100];
	char s2[100];
	char* s3;
	scanf_s("%s", s1, 100);
	scanf_s("%s", s2, 100);
	s3 = concat(s1, s2);
	printf("-->%s", s3);
	return 0;
}